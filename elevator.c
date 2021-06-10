#include <stdlib.h>
#include <stdio.h>
#include "person.h"
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    Elevator *out = (Elevator*) malloc(sizeof(Elevator));
    out->capacity = capacity;
    out->currentFloor = currentFloor;
    out->persons = persons;
    out->targetFloor = currentFloor;
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
    PersonList* out = (PersonList*)malloc(sizeof(PersonList));
    PersonList* tmp = e->persons;
    while(tmp != NULL){
        if(tmp->person->dest == e->currentFloor){
            out = insert(tmp->person, out);
        }
        tmp = tmp->next;
    }
    return out;
}

PersonList* enterElevator(Elevator *e, PersonList *list){
    int nbInElev = length(e->persons);
    int nbWaiting = length(list);
    PersonList* out=emptyPersonList();
    int i = 0;
    while(i+nbInElev < e->capacity && nbWaiting > 0){
        out=insert(get(list, i), out);
        i++;
    }
    return out;
}

void stepElevator(Building *b){
    Elevator* elev = b->elevator;
    if (elev->currentFloor == elev->targetFloor){
        elev->persons = exitElevator(elev);
        elev->persons = enterElevator(elev, *(b->waitingLists+elev->currentFloor));
    }
    else{
        if (elev->currentFloor > elev->targetFloor){
            (elev->currentFloor)--;
        }
        else{
            (elev->currentFloor)++;
        }
    }
}