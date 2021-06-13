#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
    int src;
    int dest;
} Person;

typedef struct _PersonList {
    Person *person;
    struct _PersonList *next;
} PersonList;

Person* createPerson(int src, int dest);
PersonList* insert(Person *p, PersonList *list);
PersonList* revert(PersonList* list);
PersonList* emptyPersonList();
int length(PersonList* p);
Person* get(PersonList* list, int i);
void printPerson(Person* p);
void printPersonList(PersonList* list);
#endif