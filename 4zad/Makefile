all: help.out strlength.out strconcat.out strcompare.out

help.out: help.c
	gcc help.c -o help.out

strlength.out: strlength.c mystrings.o mystrings.h
	gcc strlength.c mystrings.o -o strlength.out

strconcat.out: strconcat.c mystrings.o mystrings.h
	gcc strconcat.c mystrings.o -o strconcat.out

strcompare.out: strcompare.c mystrings.o mystrings.h
	gcc strcompare.c mystrings.o -o strcompare.out

mystrings.o: mystrings.h mystrings.c
	gcc -c mystrings.c -o mystrings.o

clear:
	rm -f *.out *.o