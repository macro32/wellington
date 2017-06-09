#/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g


OUT = cmd.a

SRC = driver.cpp scanner.cpp parser.cpp order_dictionary.cpp
OBJ = (SRC:.cpp.o)


all: $(OUT) 

OBJ = driver.o parser.o order_dictionary.o

.cpp.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.o *.a a.out 
	@rm -f ../../lib/$(OUT)

