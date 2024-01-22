all: main.out

main.out: main.o quadraticroots.c quadraticroots.h
	gcc quadraticroots.c main.o -o main.out

main.o: main.c quadraticroots.h
	gcc -c main.c

clear:
	rm -f *.o *.out