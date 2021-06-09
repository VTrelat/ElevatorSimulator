#include <stdlib.h>
#include <stdio.h>
#include "person.h"
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    Elevator *out = (Elevator*) malloc(sizeof(Elevator));
    out->capacity = capacity;
    out->currentFloor = currentFloor;
    out->persons = persons;
    out->targetFloor = NULL;
    return out;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    Building *out = (Building*) malloc(sizeof(Building));
    out->elevator = elevator;
    out->nbFloor = nbFloor;
    out->waitingLists = waitingLists;
    return out;
}

PersonList* exitElevator(Elevator *e){

}

PersonList* enterElevator(Elevator *e, PersonList *list){

}

void stepElevator(Building *b){
    
}