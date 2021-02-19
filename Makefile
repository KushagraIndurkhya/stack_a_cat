# SHELL = /bin/sh
CC = g++
.SILENT:
LIST = 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
SOURCE = ./stack$$i/driver.cpp ./stack$$i/stack.cpp
TARGET = ./bin/stack$$i
compile:
	mkdir -p bin;
	for i in $(LIST); do ${CC} ${SOURCE} -o ${TARGET}; done
	# echo "\e[0;32m Compiled stack$$i \342\234\224 \e[0m"; done
	# for i in $(LIST); do echo "\e[0;31m....................................$$i......................................\e[0m";${TARGET}<inp.txt;done
clean:
	rm -r ./bin
