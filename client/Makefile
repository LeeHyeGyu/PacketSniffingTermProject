# Makefile

CC = gcc
CFLAGS = -g 
OBJS = main.o selection.o inputaddr.o sendHTTP.o
LIBS = 
all:	client

client:	$(OBJS)
	$(CC) $(CFLAGS) -o client $(OBJS) $(LIBS)

main.o:	main.c
	$(CC) $(CFLAGS) -c main.c
selection.o: selection.c
	$(CC) $(CFLAGS) -c selection.c
inputaddr.o: inputaddr.c
	$(CC) $(CFLAGS) -c inputaddr.c
sendHTTP.o: sendHTTP.c
	$(CC) $(CFLAGS) -c sendHTTP.c

clean:
	rm -f $(OBJS) add core
