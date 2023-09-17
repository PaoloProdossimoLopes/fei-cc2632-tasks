//
// Created by pprod on 16/09/2023.
//

#include "Task.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOWER_BOUND 0
#define UPPER_BOUND 10

int is_valid_priority(int priority) {
    return priority >= LOWER_BOUND && priority <= UPPER_BOUND;
}

Task *init_task(int priority, const char description[], const char category[]) {
    if (!is_valid_priority(priority)) {
        printf(":: ERROR :: The task received an invalid priority value, must be between %d and %d", LOWER_BOUND, UPPER_BOUND);
        return NULL;
    }

    const int is_valid_description_size = strlen(description) < TASK_DESCRIPTION_SIZE;
    if (!is_valid_description_size) {
        printf(":: ERROR :: The task received an invalid description size, must be lower than %d characters", TASK_DESCRIPTION_SIZE);
        return NULL;
    }

    const int is_valid_category_size = strlen(category) < TASK_CATEGORY_SIZE;
    if (!is_valid_category_size) {
        printf(":: ERROR :: The task received an invalid category size, must be lower than %d characters", TASK_CATEGORY_SIZE);
        return NULL;
    }

    Task *task = malloc(sizeof(Task));
    task->priority = priority;
    for (int i=0; i<strlen(description); i++) task->description[i] = description[i];
    for (int i=0; i<strlen(category); i++) task->category[i] = category[i];
    return task;
}

void print_tasks(Task tasks[], int size) {
    printf("\n");
    for (int i=0; i <= size; i++) {
        printf("TASK ID: %d\n", i);
        printf("TASK PRIORITY: %d\n",  tasks[i].priority);
        printf("TASK DESCRIPTION: %s\n", tasks[i].description);
        printf("TASK CATEGORY: %s\n", tasks[i].category);
    }
    printf("\n");
}