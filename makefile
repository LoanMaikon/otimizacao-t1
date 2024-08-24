CFLAGS = -Wall
LDFLAGS = -lm
CC = gcc
objects = transporte *.o
     
transporte: main.o
	$(CC) -o transporte main.o $(LDFLAGS)

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f $(objects)
