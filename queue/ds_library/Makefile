CC=gcc
CFLAGS=-O2 -Wall

main: main.o queue.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o main
