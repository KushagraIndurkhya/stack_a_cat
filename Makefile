# SHELL = /bin/sh
CC = g++
.SILENT:
LIST = 0
# LIST = 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
SOURCE = ./stack$$i/driver.cpp ./stack$$i/stack.cpp
TARGET = ./bin/stack$$i
compile:
	mkdir -p bin;
	for i in $(LIST); do ${CC} ${SOURCE} -o ${TARGET};done
clean:
	rm -r ./bin