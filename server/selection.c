#include "client.h"

char selapp(){
	char appnum;

	system("clear");
        printf("==================================================\n");
        printf("Choose Application Protocol Number You Want To Send\n");
        printf("1. HTTP\n");
        printf("2. DNS\n");
        printf("3. SMTP\n");
        printf("0. Quit\n");
        printf("==================================================\n");
	appnum = fgetc(stdin);
	getchar();

	return appnum;
}

