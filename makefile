# Makefile for list.c
# Hayden Walker, 2022-02-09

CC = gcc
CFLAGS = -std=c89

list : list.c
	$(CC) $(CFLAGS) -o list list.c

clean :
	rm list