#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

INCDIRS = -I../../cmd
LIBDIRS = -L../../../lib

CXXFLAGS = $(INCDIRS) -g -Wall -std=c++11
CFLAG = $(INCDIRS) $(CXXFLAGS)

LDFLAGS	= -g $(LIBDIRS) 

LIBS = -l:cmd.a

prefix = ../../../test

SRCS = bmain.cpp
OBJS = $(SRCS:.cpp=.o)
OUT = test_cmd

all: $(OUT) 

$(OUT): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS) $(LIBS) 

install: all
	cp $(OUT) $(prefix)

clean:
	@rm -f *.o *.a $(OUT)

uninstall:
	@rm -f $(prefix)/$(OUT)
