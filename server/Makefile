# Makefile

CC = gcc
CFLAGS = -g 
OBJS = main.o inputport.o runserver.o
LIBS = 
all:	server

server:	$(OBJS)
	$(CC) $(CFLAGS) -o server $(OBJS) $(LIBS)

main.o:	main.c
	$(CC) $(CFLAGS) -c main.c
inputport.o: inputport.c
	$(CC) $(CFLAGS) -c inputport.c
runserver.o: runserver.c
	$(CC) $(CFLAGS) -c runserver.c

clean:
	rm -f $(OBJS) add core
