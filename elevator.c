#include <stdio.h>
#include <stdlib.h>

#include "elevator.h"
#include "person.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    Elevator* elev = (Elevator*) malloc(sizeof(Elevator));
    elev->capacity = capacity;
    elev->currentFloor = currentFloor;
    elev->targetFloor = NULL;
    elev->persons = persons;
    return elev;
}