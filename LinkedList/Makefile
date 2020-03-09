CC=g++
GTEST_INCLUDE_PATH=../googletest/googletest/include/
GTEST_LIBRARY_PATH=../googletest/build/lib/ -lgtest -lgtest_main
CCFLAGS=-Wall -std=c++14

all: LinkedList.o
	$(CC) test_LinkedList.cpp LinkedList.o $(CCFLAGS) -I$(GTEST_INCLUDE_PATH) -L$(GTEST_LIBRARY_PATH)

LinkedList.o:
	$(CC) -c LinkedList.cpp $(CCFLAGS)

clean:
	rm ./a.out *.o
