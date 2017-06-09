#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = -I../../log -I../../etc -I../../xml -I../../ui -I../../res -I../../actors
LIBDIRS  = -L../../../lib
CXXFLAGS = $(INCDIRS) -g -Wall -std=c++11

CFLAGS = 	$(INCDIRS) $(CXXFLAGS)

LIBS    = -l:logger.a -l:ui.a -l:actors.a -l:pugixml.a -lncurses -l:libboost_program_options.a -l:libboost_system.a -l:libboost_thread.a -l:libboost_log.a -lpthread
LDFLAGS	= $(LIBDIRS)

prefix = ../../../test
battle = ../../../assets/battles/vitoria

SRCS = 	test_resource.cpp 
OBJS = $(SRCS:.cpp=.o)
OUT  = test_resource

all: $(OUT) 

$(OUT): $(OBJS) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

install: all
	cp $(OUT) $(prefix)
	cp $(battle)/*.xml $(prefix)

clean:
	@rm -f *.o $(OUT) 

uninstall:
	@rm -f $(prefix)/*.xml
	@rm -f $(prefix)/$(OUT)

