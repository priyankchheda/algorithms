CC=gcc
CFLAGS=-O2 -Wall

sort: bubble_sort.o
	$(CC) $(CFLAGS) -o $@ $<

bubble_sort.o: bubble_sort.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o sort
