#include "person.h"
#include <stdlib.h>
#include <stdio.h>

Person* createPerson(int src, int dest){
    Person* out = malloc(sizeof(Person));
    out->src = src;
    out->dest = dest;
    return out;
}

PersonList* insert(Person* p, PersonList* list){
    PersonList *out = malloc(sizeof(PersonList));
    out->person = p;
    out->next = list;
    return out;
}

int length(PersonList* p){
    int i = 0;
    PersonList *tmp = p;
    while(tmp->next != NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}

PersonList* emptyPersonList(){
    PersonList* out = malloc(sizeof(PersonList));
    out->next=NULL;
    out->person=NULL;
    return out;
}

Person* get(PersonList* list, int i){
    int k=0;
    PersonList* tmp = list;
    while(k<i && tmp->next!=NULL){
        tmp=tmp->next;
        k++;
    }
    return tmp->person;
}

void printPerson(Person* p){
    printf("%d%d", p->src, p->dest);
}

void printPersonList(PersonList* list){
    PersonList* tmp = list;
    while(tmp->next != NULL){
        printPerson(tmp->person);
        tmp=tmp->next;
    }
}