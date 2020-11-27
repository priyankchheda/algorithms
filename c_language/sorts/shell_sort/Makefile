CC=gcc
CFLAGS=-O2 -Wall

sort: shell_sort.o
	$(CC) $(CFLAGS) -o $@ $<

shell_sort.o: shell_sort.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o sort
