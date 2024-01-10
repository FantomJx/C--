all: safeadd.out safesubtruct.out safemultiply.out safedivide.out

safeadd.out: safeadd.c safeint.h safeint.o
	gcc safeadd.c safeint.o -o safeadd.out

safesubtruct.out: safesubtruct.c safeint.h safeint.o
	gcc safesubtruct.c safeint.o -o safesubtract.out

safemultiply.out: safemultiply.c safeint.h safeint.o
	gcc safemultiply.c safeint.o -o safemultiply.out

safedivide.out: safedivide.c safeint.h safeint.o
	gcc safedivide.c safeint.o -o safedivide.out

safeint.o: safeint.c safeint.h
	gcc -c safeint.c -o safeint.o

clear:
	rm -f *.out *.o