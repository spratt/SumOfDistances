# if mode is release, don't include debug info
ifeq ($(mode),release)
	CXXFLAGS=-O2 -Wall
else
	mode = debug
	CXXFLAGS=-O0 -g -Wall
endif

#begin actual makefile stuff
all: test

# executables
test: SumOfDifferences.o test.cpp

# object files
SumOfDifferences.o: SumOfDifferences.h

# in case of emergency
clean:
	@if [ -f test ]; then rm test; fi
	@rm -f *.o # remove all object files and be quiet about it

