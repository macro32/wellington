#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = -I../../etc -I../../xml -I../../ui -I../../res -I../../actors
LIBDIRS  = -L../../../lib
CXXFLAGS = $(INCDIRS) -g -Wall -std=c++11

CFLAGS = 	$(INCDIRS) $(CXXFLAGS)

LIBS    = -l:libboost_log.a -l:libboost_log_setup.a -l:libboost_thread.a -l:libboost_filesystem.a -l:libboost_system.a -lpthread
LDFLAGS	= $(LIBDIRS)

prefix = ../../../test

SRCS1 = test_log.cpp 
SRCS2 = tutorial_log.cpp 
SRCS3 = tutorial_attributes.cpp 
SRCS4 = tutorial_fmt_stream.cpp 
SRCS5 = tutorial_fmt_stream_manual.cpp 
SRCS6 = tutorial_fmt_format.cpp 
SRCS7 = tutorial_fmt_string.cpp 
SRCS8 = tutorial_fmt_custom.cpp 
SRCS9 = tutorial_filtering.cpp 

OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)
OBJS3 = $(SRCS3:.cpp=.o)
OBJS4 = $(SRCS4:.cpp=.o)
OBJS5 = $(SRCS5:.cpp=.o)
OBJS6 = $(SRCS6:.cpp=.o)
OBJS7 = $(SRCS7:.cpp=.o)
OBJS8 = $(SRCS8:.cpp=.o)
OBJS9 = $(SRCS9:.cpp=.o)

OUT1  = test_log 
OUT2  = tutorial_log
OUT3  = tutorial_attributes
OUT4  = tutorial_fmt_stream
OUT5  = tutorial_fmt_stream_manual
OUT6  = tutorial_fmt_format
OUT7  = tutorial_fmt_string
OUT8  = tutorial_fmt_custom
OUT9  = tutorial_filtering

all: $(OUT1) $(OUT2) $(OUT3) $(OUT4) $(OUT5) $(OUT6) $(OUT7) $(OUT8) $(OUT9)

$(OUT1): $(OBJS1) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS1) $(LIBS)

$(OUT2): $(OBJS2) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS2) $(LIBS)

$(OUT3): $(OBJS3) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS3) $(LIBS)

$(OUT4): $(OBJS4) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS4) $(LIBS)

$(OUT5): $(OBJS5) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS5) $(LIBS)

$(OUT6): $(OBJS6) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS6) $(LIBS)

$(OUT7): $(OBJS7) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS7) $(LIBS)

$(OUT8): $(OBJS8) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS8) $(LIBS)

$(OUT9): $(OBJS9) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS9) $(LIBS)

install: all
	cp $(OUT1) $(prefix)
	cp $(OUT2) $(prefix)
	cp $(OUT3) $(prefix)
	cp $(OUT4) $(prefix)
	cp $(OUT5) $(prefix)
	cp $(OUT6) $(prefix)
	cp $(OUT7) $(prefix)
	cp $(OUT8) $(prefix)
	cp $(OUT9) $(prefix)

clean:
	@rm -f *.o $(OUT1) 
	@rm -f $(OUT2) 
	@rm -f $(OUT3) 
	@rm -f $(OUT4) 
	@rm -f $(OUT5) 
	@rm -f $(OUT6) 
	@rm -f $(OUT7) 
	@rm -f $(OUT8) 
	@rm -f $(OUT9) 
	@rm -f *.log

uninstall:
	@rm -f $(prefix)/$(OUT1)
	@rm -f $(prefix)/$(OUT2)
	@rm -f $(prefix)/$(OUT3)
	@rm -f $(prefix)/$(OUT4)
	@rm -f $(prefix)/$(OUT5)
	@rm -f $(prefix)/$(OUT6)
	@rm -f $(prefix)/$(OUT7)
	@rm -f $(prefix)/$(OUT8)
	@rm -f $(prefix)/$(OUT9)

