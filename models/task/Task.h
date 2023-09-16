//
// Created by pprod on 16/09/2023.
//

#ifndef TASKS_TASK_H
#define TASKS_TASK_H

typedef struct Task {
    int priority;
    char *description;
    char *category;
} Task;

Task *init_task(int priority, char *description, char *category);

void print_task(Task task);

#endif //TASKS_TASK_H
