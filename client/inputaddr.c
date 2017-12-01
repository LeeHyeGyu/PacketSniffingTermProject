#include "client.h"

void inputaddr(){
	system("clear");
       	printf("==================================================\n");
       	printf("==================================================\n");
	printf("Input Server's Ipv4 Address : ");
	fgets(glob_address, BUFSIZ, stdin);
	printf("Input Port Number : ");
	fgets(glob_portnum, BUFSIZ, stdin);
}
