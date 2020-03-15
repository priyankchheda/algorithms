CC=g++
GTEST_INCLUDE_PATH=../../googletest/googletest/include/
GTEST_LIBRARY_PATH=../../googletest/build/lib/ -lgtest -lgtest_main
CCFLAGS=-Wall -std=c++14

all: Queue.o
	$(CC) test_Queue.cpp Queue.o $(CCFLAGS) -I$(GTEST_INCLUDE_PATH) -L$(GTEST_LIBRARY_PATH)

Queue.o:
	$(CC) -c Queue.cpp $(CCFLAGS)

clean:
	rm ./a.out *.o
