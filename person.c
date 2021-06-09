#include "person.h"
#include <stdlib.h>

Person* createPerson(int src, int dest){
    Person* out = malloc(sizeof(Person));
    out->src = src;
    out->dest = dest;
}