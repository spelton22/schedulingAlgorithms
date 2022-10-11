#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

/* Priority scheduler
 * Looks at the priority number and
 * sends the highest priority jobs to the 
 * cpu first.
*/

struct node* head = NULL;
struct node* tail = NULL;


void add(char *name, int priority, int burst) {
    
    //struct node* place

    struct task* temp = malloc(sizeof(struct task));
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;

    insertTail(&tail, &head, temp);

}

void schedule() {
    //fcfs 
    //loop until list is empty
    while (head != NULL) {
        //gets the first element in last
        struct node* tempNode = head;
        struct task* tempTask = tempNode->task;

        //runs first job and removes from list
        run(tempTask, tempTask->burst);
        delete(&head, tempTask);
    }

}