#include <stdio.h>
#include <winsock.h>

#define PORT 13301
#define BUFFER_LENGTH 1024
#define MAX_CLIENTS 10

int main() {
	WSADATA wsaData;
	WSAStartup(0x0202, &wsaData);

	char buffer[BUFFER_LENGTH];

	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
  size_t client_address_len = sizeof(client_address);

	int listening_socket;
	int connected_socket;

	int activity;
	int connected_sockets[MAX_CLIENTS];
	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		connected_sockets[i] = 0;
	}

	fd_set readfds;

	int received_len;
	int sent_len;

	listening_socket = socket(
		AF_INET,        //IPv4
		SOCK_STREAM,    //two-way socket
		IPPROTO_TCP     //TCP
	);

	if (listening_socket < 0) {
		printf("Socket creation failed.\n");
		exit(1);
	}

	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = INADDR_ANY; //any interface

	if (bind(listening_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
		printf("Binding socket failed.\n");
		exit(1);
	}

	if (listen(listening_socket, 5) < 0) {
		printf("Listening of socket failed.\n");
		exit(1);
	}

	printf("Listening on %u...\n", PORT);

	while (1) {
		printf("Start of loop\n");
		memset(&buffer, 0, sizeof(buffer));
		memset(&client_address, 0, sizeof(client_address));

		//clear the socket fd set
		FD_ZERO(&readfds);

		//add listening socket to fd set
		FD_SET(listening_socket, &readfds);

		//add children to fd set
		for(int i = 0; i < MAX_CLIENTS; i++) {
			if(connected_sockets[i] > 0)
				FD_SET(connected_sockets[i], &readfds);
		}

		activity = select(0, &readfds, NULL, NULL, NULL);

		if(activity == SOCKET_ERROR) {
			printf("Select call failed with error code : %d" , WSAGetLastError());
				exit(EXIT_FAILURE);
		}

		//if activity happened to the listening socket - it's an incoming connection
		if(FD_ISSET(listening_socket, &readfds)){
			connected_socket = accept(listening_socket, (struct sockaddr *) &client_address, &client_address_len);
			printf("Client connected.\n");
			//add socket to fd set
			for(int i = 0; i < MAX_CLIENTS; i++) {
				if(connected_sockets[i] == 0)
				{
					connected_sockets[i] = connected_socket;
					break;
				}
			}	
		}

		//check other connections
		for(int i = 0; i < MAX_CLIENTS; i++){
			printf("Socket %d:\n", i);
			connected_socket = connected_sockets[i];

			if(FD_ISSET(connected_socket, &readfds)) {
				received_len = recv(connected_socket, buffer, sizeof(buffer), 0);
				if( received_len == SOCKET_ERROR)
				{
						int error_code = WSAGetLastError();
						if(error_code == WSAECONNRESET)
						{
								//Somebody disconnected , get his details and print
								printf("Host disconnected unexpectedly\n");
							
								//Close the socket and mark as 0 in list for reuse
								closesocket(connected_socket);
								connected_sockets[i] = 0;
						}
						else
						{
								printf("recv failed with error code : %d" , error_code);
						}
				}
				if(received_len == 0)
				{
					printf("Client disconnected.\n");
					closesocket(connected_socket);
					connected_sockets[i] = 0;
				}
				printf("Received: %s\n", buffer);
				sent_len = send(connected_socket, buffer, received_len, 0);
			}
		}
	}
	return 0;
}