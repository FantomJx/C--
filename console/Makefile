all: taskmanager.out

processes.o: processes.c processes.h
	gcc -c processes.c

taskmanager.out: taskmanager.c processes.o
	gcc taskmanager.c processes.o -o taskmanager.out

clear:
	rm -f *.o *.out
