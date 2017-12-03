#include "server.h"

void runserver(){
	int serv_sock, clnt_sock, portnum;
	int rcvcnt;

	char buffer[BUF_SIZE];
	char* ipaddr;

	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_sz;

	// get port number by standard input.
	inputaddr(&portnum);

	// create socket.
	if((serv_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket()");
		exit(1);
	}
	else	printf("\nSocket has created...\n");

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(portnum);

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1){
		perror("bind()");
		exit(1);
	}
	else	printf("\nBinding Is Successful...\n");

	if(listen(serv_sock, 5) == -1){
		perror("listen()");
		exit(1);
	}
	else	printf("\nListening...\n");

	clnt_adr_sz = sizeof(clnt_adr);

	if((clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz)) == -1){
		perror("accept()");
		exit(1);
	} 
	else{
		ipaddr = inet_ntoa(clnt_adr.sin_addr);
		printf("\nClient [%s] Connected...\n", ipaddr);
	}

		memset(buffer, 0, sizeof(buffer));
	while((rcvcnt = read(clnt_sock, buffer, BUF_SIZE)) > 0)
		read(clnt_sock, buffer, BUF_SIZE);

		printf("msg : %s\n", buffer);
}
