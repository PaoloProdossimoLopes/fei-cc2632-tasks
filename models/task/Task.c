//
// Created by pprod on 16/09/2023.
//

#include "Task.h"
#include <stdio.h>
#include <stdlib.h>

Task *init_task(int priority, char *description, char *category) {
    Task *task = malloc(sizeof(Task));
    task->priority = priority;
    task->description = description;
    task->category = category;
    return task;
}

void print_task(Task task) {
    printf(":::: TASK ::::\n");
    printf("Priority: %d\n", task.priority);
    printf("Description: %s\n", task.description);
    printf("Category: %s\n", task.category);
    printf("==============\n");
}