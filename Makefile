CC = g++
CFLAGS = -Wall -std=c++11

BISON = bison
FLEX = flex

OUTPUT = main

SRCS = proiect.l main.y
OBJS = lex.yy.c main.tab.c

all: corect

corect:
	bison -d main.y
	flex proiect.l
	g++ lex.yy.c main.tab.c -o main

clean:
	rm -f $(OUTPUT) $(OBJS) lex.yy.c main.tab.c main.tab.h

.PHONY: all clean