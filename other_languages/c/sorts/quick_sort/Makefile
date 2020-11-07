CC=gcc
CFLAGS=-O2 -Wall

sort: quick_sort.o
	$(CC) $(CFLAGS) -o $@ $<

quick_sort.o: quick_sort.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o sort
