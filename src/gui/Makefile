#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g

INCLUDES = -I../cmd -I../io -I../log -I../actors -I../etc -I../xml -I../res

SRC = 	cmd.cpp \
		stdscr_controller.cpp \
		stdscr_view.cpp \
		stdscr_model.cpp
 
OBJ = $(SRC:.cpp=.o)
OUT = gui.a

all: $(OUT) 

.cpp.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.o *.a
	@rm -f ../../lib/$(OUT)

