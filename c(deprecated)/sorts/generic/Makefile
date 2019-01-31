CC=gcc
CFLAGS=-O2 -Wall 


main: main.o sort.o
	$(CC) $(CFLAGS) -g -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o main
