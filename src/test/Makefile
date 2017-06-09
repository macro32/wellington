#!/usr/bin/make

all: 
	$(MAKE) -C actor_factory 
	$(MAKE) -C xml
	$(MAKE) -C resource 
	$(MAKE) -C log 

install:
	$(MAKE) -C actor_factory install
	$(MAKE) -C xml install
	$(MAKE) -C resource install
	$(MAKE) -C log install

clean:
	$(MAKE) -C actor_factory clean
	$(MAKE) -C xml clean
	$(MAKE) -C resource clean
	$(MAKE) -C log clean

uninstall:
	$(MAKE) -C actor_factory uninstall
	$(MAKE) -C xml uninstall
	$(MAKE) -C resource uninstall
	$(MAKE) -C log uninstall

