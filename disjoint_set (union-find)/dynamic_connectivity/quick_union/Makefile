CC=gcc
CFLAGS=-O2 -Wall

main: main.o quick_union.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

quick_union.o: quick_union.c quick_union.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o main
