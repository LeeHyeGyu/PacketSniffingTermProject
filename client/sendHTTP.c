#include "client.h"

void sendHTTP(){
	int sockfd, portnum;
	int optval = 1;
	int rcvcnt;
	char ipaddr[BUFSIZ];
	char header[BUF_SIZE];
	char buffer[BUF_SIZE];

	struct sockaddr_in addr;

	struct iphdr *ip = (struct iphdr *) header;
	struct tcphdr *tcp = (struct tcphdr *) (header + sizeof(struct iphdr));

	memset(header, 0, BUF_SIZE);

	// get destination address information by standard input.
	inputaddr(ipaddr, &portnum);

	// create socket
	if((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) == -1){
		perror("socket()");
		exit(1);
	}
	else	printf("\nSocket has created...\n");

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(ipaddr);
	addr.sin_port = htons(portnum);

	// declare using raw socket on socket option.
	if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) == -1){
		perror("setsockopt()");
		exit(1);
	}

	// init TCP connection forward to the server.
	if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1){
		perror("connect()");
		exit(1);
	}
	else	printf("\nConnected...\n");

	// send HTTP GET request to server
	sprintf(buffer, "GET / HTTP/1.1\r\nHOST: %s\r\nConnection: close\r\n\r\n", ipaddr);
	write(sockfd, buffer, strlen(buffer));

	memset(buffer, 0, sizeof(buffer));
	if((rcvcnt = read(sockfd, buffer, sizeof(buffer))) == -1){
		perror("read()");
		exit(1);
	}
	
	close(sockfd);
	
}
