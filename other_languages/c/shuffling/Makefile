CC=gcc
CFLAGS=-O2 -Wall

shuffle: shuffle_array.o
	$(CC) $(CFLAGS) -o $@ $<

shuffle_array.o: shuffle_array.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o shuffle
