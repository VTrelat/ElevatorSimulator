FLAGS = -Wall -g
all: main

main.o: main.c
	gcc ${FLAGS} -c main.c

person.o : person.c
	gcc ${FLAGS} -c person.c

elevator.o : elevator.c
	gcc ${FLAGS} -c elevator.c

main: main.o person.o elevator.o
	gcc ${FLAGS} -o Elevator main.o person.o elevator.o -lncurses

clean:
	rm -f -f *.o ./main