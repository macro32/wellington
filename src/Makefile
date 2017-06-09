#!/usr/bin/make

all: 
	$(MAKE) -C log
	$(MAKE) -C gui
	$(MAKE) -C cmd 
	$(MAKE) -C io 
	$(MAKE) -C xml
	$(MAKE) -C actors
	$(MAKE) -C main

install:
	$(MAKE) -C main install

clean:
	$(MAKE) -C log clean
	$(MAKE) -C gui clean
	$(MAKE) -C cmd clean
	$(MAKE) -C io clean
	$(MAKE) -C xml clean
	$(MAKE) -C actors clean
	$(MAKE) -C main clean

uninstall:
	$(MAKE) -C main uninstall
