CC=gcc
CFLAGS=-O2 -Wall

sort: merge_sort.o
	$(CC) $(CFLAGS) -o $@ $<

merge_sort.o: merge_sort.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o sort
