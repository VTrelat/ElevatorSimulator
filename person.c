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


PersonList* emptyPersonList(){
    PersonList* out = malloc(sizeof(PersonList));
    out->next=NULL;
    out->person=NULL;
    return out;
}

int length(PersonList* p){
    if(p==NULL){
        return 0;
    }
    else
    {
    int i = 0;
    PersonList *tmp = p;
    while(tmp->person != NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
    }
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
    if(list==NULL){
        printf("Error in PrintPersonList : list is NULL");
    } else {
        printf("[");
        PersonList* tmp = list;
        while(tmp->next != NULL){
            printPerson(tmp->person);
            if(tmp->next->next != NULL){
                printf(", ");
            }
            tmp=tmp->next;
        }
    }
    printf("]\n");
}