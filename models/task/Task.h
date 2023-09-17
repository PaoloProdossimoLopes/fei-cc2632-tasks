//
// Created by pprod on 16/09/2023.
//

#ifndef TASKS_TASK_H
#define TASKS_TASK_H

#define TASK_DESCRIPTION_SIZE 300
#define TASK_CATEGORY_SIZE 100

typedef struct Task {
    int priority;
    char *description;
    char *category;
} Task;

Task *init_task(int priority, char *description, char *category);

void print_task(Task task);

#endif //TASKS_TASK_H
