all: main

main.o: main.c
	gcc -c main.c

person.o : person.c
	gcc -c person.c

elevator.o : elevator.c
	gcc -c elevator.c

main: main.o person.o elevator.o
	gcc -o Elevator main.o person.o elevator.o -lncurses