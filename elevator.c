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