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

Task *init_task(int priority, char *description, char *category) {
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