#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <linux/ip.h>
#include <linux/tcp.h>

#define BUF_SIZE 1024

char selapp();
void inputaddr(char* addr, int* portnum);
void sendHTTP();



