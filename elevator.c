#include <stdlib.h>
#include <stdio.h>
#include "person.h"
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    Elevator *out = (Elevator*) malloc(sizeof(Elevator));
    out->capacity = capacity;
    out->currentNb = length(persons);
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
    PersonList* out = emptyPersonList();
    PersonList* tmp = e->persons;
    while(tmp != NULL && tmp->person != NULL){
        if(tmp->person->dest != e->currentFloor){
            out = insert(tmp->person, out);
        }
        else
        {
            e->currentNb--;
        }
        tmp = tmp->next;
    }
    return revert(out);
}

PersonList* enterElevator(Elevator *e, PersonList *list){
    PersonList* out=e->persons;
    while(e->currentNb < e->capacity && list->person != NULL){
        out=insert(list->person, out);
        e->currentNb++;
        if(list->next!=NULL){
            *list=*(list->next);
        }       
        else
        {
            *list = *emptyPersonList();
        }
        
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