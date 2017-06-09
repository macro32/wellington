#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g

INCLUDES = -I../io -I../log -I../actors -I../etc -I../xml -I../res

SRC = 	tile_scan.cpp tile_parser.cpp 
 
OBJ = $(SRC:.cpp=.o)
OUT = io.a

all: $(OUT) 

.cpp.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.o *.a
	@rm -f ../../lib/$(OUT)

