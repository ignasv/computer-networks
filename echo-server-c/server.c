#include <stdio.h>
#include <winsock.h>

#define PORT 13301
#define BUFFER_LENGTH 1024

int main() {
    WSADATA wsaData;
    WSAStartup(0x0202, &wsaData);

    char buffer[BUFFER_LENGTH];

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    int listening_socket;
    int connected_socket;
    
    int received_len;
    int sent_len;

    listening_socket = socket(
        AF_INET,        //IPv4
        SOCK_STREAM,    //two-way socket
        IPPROTO_TCP     //TCP
    );
    
    if(listening_socket < 0) {
        printf("Socket creation failed.\n");
        exit(1);
    }

    memset(&server_address,0, sizeof(server_address)); 
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons (PORT);
    server_address.sin_addr.s_addr = INADDR_ANY; //any interface

    if(bind(listening_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Binding socket failed.\n");
        exit(1);
    }

    if(listen(listening_socket, 5) < 0) {    
        printf("Listening of socket failed.\n");
		exit(1);
    }
    
    printf("Listening on %u...\n", PORT);
    
    while(1) {
        memset(&buffer, 0, sizeof(buffer));
        memset(&client_address, 0, sizeof(client_address));

        size_t client_address_len = sizeof(client_address);
        connected_socket = accept(listening_socket, (struct sockaddr *) &client_address, &client_address_len);
        
        if(connected_socket < 0) {
            printf("Socket connection failed.\n");
            exit(1);
        }

        printf("Connection established.\n");

        received_len = recv(connected_socket, buffer, sizeof(buffer), 0);
        sent_len = send(connected_socket, buffer, received_len, 0);

        printf("Client: %s. Received: %d. Sent: %d.\n", inet_ntoa(client_address.sin_addr), received_len, sent_len);

        closesocket(connected_socket);
        printf("Client disconnected.\n");
    }
    return 0;
}