#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    //round robin

    // loop until list is empty
    while (head != NULL) {
        struct task* tempTask = head->task;
            
        if(tempTask->burst > 10){
            run(tempTask, 10);
            tempTask->burst -=10;
            delete(&head, tempTask);
            add(tempTask->name, tempTask->priority, tempTask->burst);
        }else if (tempTask->burst <= 10){
            run(tempTask, tempTask->burst);
            delete(&head, tempTask);
        } 

    }
}