CC=gcc
CFLAGS=-O2 -Wall

main: main.o quick_find.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

quick_find.o: quick_find.c quick_find.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o main
