#include "client.h"

void inputaddr(char *addr, int* portnum){
	system("clear");
       	printf("==================================================\n");
       	printf("==================================================\n");
	printf("Input Server's Ipv4 Address : ");
	fgets(addr, BUFSIZ, stdin);
	printf("Input Port Number : ");
	scanf("%d", portnum);
	getchar();
}
