CC=gcc
CFLAGS=-O2 -Wall

main: main.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o main
