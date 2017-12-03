#include "client.h"

void sendHTTP(){
	int sockfd;
	int optval = 1;
	int cnt;
	char buffer[BUF_SIZE];

	struct sockaddr_in addr;

	// create socket
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket()");
		exit(1);
	}
	else	printf("\nSocket has created...\n");

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(ipaddr);
	addr.sin_port = htons(portnum);

	// init TCP connection forward to the server.
	if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1){
		perror("connect()");
		exit(1);
	}
	else	printf("\nConnected...\n");

	// send HTTP GET request to server
	ipaddr[strlen(ipaddr)-1] = '\0';
	sprintf(buffer, "GET / HTTP/1.1\r\nHOST: %s\r\nConnection: close\r\n\r\n", ipaddr);
	printf("%s\n", buffer);
	sleep(5);
	
	while((cnt = write(sockfd, buffer, sizeof(buffer))) > 0){
		perror("write()");
		exit(1);
	}
	
	printf("Sending Done\n");
	getchar();
	close(sockfd);
}
