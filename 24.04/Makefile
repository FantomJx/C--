all: tests.out egn.out

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

tests.out: dynarr.o tests.c
	gcc tests.c dynarr.o -o tests.out

egn.out: dynarr.o egn.c
	gcc egn.c dynarr.o -o egn.out

clean:
	rm -f *.o *.out