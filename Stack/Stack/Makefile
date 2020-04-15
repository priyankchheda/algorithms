CC=g++
GTEST_INCLUDE_PATH=../../googletest/googletest/include/
GTEST_LIBRARY_PATH=../../googletest/build/lib/ -lgtest -lgtest_main
CCFLAGS=-Wall -std=c++14

all:
	$(CC) test_Stack.cpp $(CCFLAGS) -I$(GTEST_INCLUDE_PATH) -L$(GTEST_LIBRARY_PATH)

clean:
	rm ./a.out
