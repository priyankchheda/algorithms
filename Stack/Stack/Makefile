CC=g++
GTEST_INCLUDE_PATH=../../googletest/googletest/include/
GTEST_LIBRARY_PATH=../../googletest/build/lib/ -lgtest -lgtest_main
CCFLAGS=-Wall -std=c++14

all: Stack.o
	$(CC) test_Stack.cpp Stack.o $(CCFLAGS) -I$(GTEST_INCLUDE_PATH) -L$(GTEST_LIBRARY_PATH)

Stack.o:
	$(CC) -c Stack.cpp $(CCFLAGS)

clean:
	rm ./a.out *.o
