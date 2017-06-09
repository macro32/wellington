#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = -I../cmd -I../io -I../etc -I../xml -I../gui -I../res -I../actors -I../log
LIBDIRS  = -L../../lib
CXXFLAGS = $(INCDIRS) -g -Wall -std=c++11

CFLAGS = 	$(INCDIRS) $(CXXFLAGS)

LIBS    = -l:logger.a -l:io.a -l:gui.a -l:cmd.a -l:actors.a -l:pugixml.a -lncurses -l:libboost_program_options.a -l:libboost_log.a -l:libboost_thread.a -l:libboost_filesystem.a -l:libboost_system.a -l:libboost_date_time.a -lpthread
LDFLAGS	= $(LIBDIRS)

prefix = ../../game
battle = ../../assets/battles/vitoria

SRCS = 	main.cpp 
OBJS = $(SRCS:.cpp=.o)

all: welly

welly: $(OBJS) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

install: all
	cp welly $(prefix)
	cp $(battle)/* $(prefix)

clean:
	@rm -f *.o welly

uninstall:
	@rm -f $(prefix)/*
