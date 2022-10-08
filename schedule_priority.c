#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedulers.h"
#include "list.h"
#include "CPU.h"

/* Priority scheduler
 * Looks at the priority number and
 * sends the highest priority jobs to the 
 * cpu first.
*/

struct node* head;

void add(char *name, int priority, int burst) {
    struct task* temp = malloc(sizeof(struct task));
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;
    insert(&head, temp);
}

void schedule() {
    // loop until list is empty
    while (head != NULL) {
        struct node* tempNode = head;
        struct task* tempTask = head->task;
        struct task* highestPriority = tempTask;

        // find the highest priority job
        while (tempNode->next != NULL) {
            tempNode = tempNode->next;
            tempTask = tempNode->task;
            if (tempTask->priority > highestPriority->priority) {
                highestPriority = tempTask;
            }
        }

        // run the highest priority job & remove from list
        run(highestPriority, highestPriority->priority);
        delete(&head, highestPriority);
    }
}