//
// Created by pprod on 16/09/2023.
//

#ifndef TASKS_TASK_H
#define TASKS_TASK_H

#define TASK_DESCRIPTION_SIZE 300
#define TASK_CATEGORY_SIZE 100
#define TOTAL_TASKS 100
#define FILE_NAME "task"
#define FILE_NOT_FOUND_ERROR ":: ERROR :: File not found\n"

typedef struct Task {
    int priority;
    char description[TASK_DESCRIPTION_SIZE];
    char category[TASK_CATEGORY_SIZE];
} Task;

Task *init_task(int priority, const char description[], const char category[]);

void print_tasks(Task tasks[], int size);

#endif //TASKS_TASK_H
