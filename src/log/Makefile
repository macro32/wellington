#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g

INCLUDES = -I../actors -I../etc -I../xml -I../res

SRC = 	logger.cpp
 
OBJ = $(SRC:.cpp=.o)
OUT = logger.a

all: $(OUT) 

.cpp.o: 
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ) 
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.o *.a
	@rm -f ../../lib/$(OUT)

