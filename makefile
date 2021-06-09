all: main

main.o: main.c
	gcc -c main.c

main: main.o
	gcc -o Elevator main.o -lncurses