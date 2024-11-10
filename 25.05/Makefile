all: main.out

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

main.out: dynarr.o main.c
	gcc main.c dynarr.o -o main.out

clean:
	rm -f *.o *.out