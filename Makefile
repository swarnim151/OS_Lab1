# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Swarnim>

list: main.c
	gcc -o main main.c list.h list.c