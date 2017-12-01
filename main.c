#include "client.h"

int main (void){
	char appnum;
	while(1){
		switch(appnum = selapp()){
			case('1'):
				sendHTTP();
				break;
			case('2'):
//				sendDNS();
				break;
			case('3'):
//				sendSMTP();
				break;
			case('0'):
				system("clear");
				return 0;

			default:
				printf("!! wrong selection, input any key to proceed. !!\n");
				getchar();
				break;
		}
	}
	return 0;
}
