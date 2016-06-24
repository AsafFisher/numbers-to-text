runfile:	numbers.o
	gcc	-g	-ansi	-Wall	numbers.o	-o	runfile
numbers.o:	numbers.c
	gcc	-c	-ansi	-Wall	-pedantic	numbers.c -o numbers.o
