#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedulers.h"
#include "list.h"

struct node* head;

void add(char *name, int priority, int burst) {
    struct task* temp;
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;
    insert(head, temp);
}
