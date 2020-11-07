CC=gcc
CFLAGS=-O2 -Wall

sort: insertion_sort.o
	$(CC) $(CFLAGS) -o $@ $<

insertion_sort.o: insertion_sort.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o sort
