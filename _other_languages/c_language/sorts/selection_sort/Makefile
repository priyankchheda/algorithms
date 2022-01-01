CC=gcc
CFLAGS=-O2 -Wall

sort: selection_sort.o
	$(CC) $(CFLAGS) -o $@ $<

selection_sort.o: selection_sort.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o sort
