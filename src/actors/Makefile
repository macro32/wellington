#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g

INCLUDES = -I../cmd -I../log -I../etc -I../xml -I../res

SRC = 	actor.cpp \
	actor_factory.cpp \
	identity_component.cpp \
	move_component.cpp \
	representation_component.cpp \
	fire_component.cpp \
	order_component.cpp

OBJ = $(SRC:.cpp=.o)
OUT = actors.a

all: $(OUT) 

.cpp.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.o *.a
	@rm -f ../../lib/$(OUT)

