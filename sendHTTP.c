#include "client.h"

void sendHTTP(char tpnum){
	int sockfd;

	inputaddr();

	if(tpnum == 1){
		sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	}	
	else{

	}
}
