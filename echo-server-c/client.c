#include <stdio.h>
#include <winsock.h>
 
#define PORT 13301
#define BUFFER_LENGTH 1024
#define HOST "127.0.0.1"

int main() {
    WSADATA wsaData;
    WSAStartup(0x0202, &wsaData);

    int curr_socket;
    struct sockaddr_in servaddr;

    char send_buffer[BUFFER_LENGTH];    
    char receive_buffer[BUFFER_LENGTH];    

    curr_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(curr_socket < 0) {
        printf("Socket creation failed.\n"); 
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(HOST);

    if (connect(curr_socket,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){
		printf("Socket connection failed.\n");
		exit(1);
	}
	printf("Connected!\nEnter the message to send:\n");

    fgets(send_buffer, sizeof(send_buffer), stdin);

    memset(&receive_buffer, 0, BUFFER_LENGTH);

    send(curr_socket, send_buffer, strlen(send_buffer), 0);
    printf("Sent: %s\n", send_buffer);
    
    recv(curr_socket, receive_buffer, BUFFER_LENGTH, 0);
    printf("Received: %s\n", receive_buffer);
    
    closesocket(curr_socket);
    printf("Disconnected.\n");

    return 0;
}