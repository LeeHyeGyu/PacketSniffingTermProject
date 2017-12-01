#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

char glob_address[BUFSIZ], glob_portnum[BUFSIZ];

char selapp();
void inputaddr();



