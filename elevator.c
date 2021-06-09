#include <stdlib.h>
#include "person.h"
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    Elevator *out = malloc(sizeof(Elevator));
    out->capacity = capacity;
    out->currentFloor = currentFloor;
    out->persons = persons;
    out->targetFloor = NULL;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    Building *out = malloc(sizeof(Building));
    out->elevator = elevator;
    out->nbFloor = nbFloor;
    out->waitingLists = waitingLists;
}