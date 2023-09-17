#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "models/task/Task.h"
#include "helpers/helpers.h"

void generate_menu() {
    printf("::::::::: MENU :::::::::\n");
    printf(":: 1 - Create task\n");
    printf("::::::::::::::::::::::::\n");
}

#define FILE_NAME "task"
#define FILE_NOT_FOUND_ERROR ":: ERROR :: File not found\n"

int task_len(const Task t[]) {
    return sizeof(*t) / sizeof(t[0]);
}

void print_tasks(Task tasks[], const int size) {
    for (int i=0; i <= size; i++) {
        printf("TASK ID: %d\n", i);
        printf("TASK PRIORITY: %d\n",  tasks[i].priority);
        printf("TASK DESCRIPTION: %s\n", tasks[i].description);
        printf("TASK CATEGORY: %s\n\n", tasks[i].category);
    }
}

void write_file(const Task task[]) {
    FILE *file = fopen(FILE_NAME, "wb+");
    if (!file) {
        printf("%s", FILE_NOT_FOUND_ERROR);
        exit(-1);
    }
    fseek(file, 0, SEEK_END);
    fwrite(task, sizeof(Task), 1, file);
    fclose(file);
}

void read_file(Task task[]) {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        printf("%s", FILE_NOT_FOUND_ERROR);
        exit(-1);
    }
    fread(task, sizeof(Task), 100, file);
    fclose(file);
}


int main() {
    int count = 0;
    while (true) {
        generate_menu();

        const int input = read_int("\nWhat you want to do? ");

        const int is_create_menu_option = input == 1;
        if (is_create_menu_option) {
            const int task_priority = read_int("Choose the task priority: ");

            char task_description[TASK_DESCRIPTION_SIZE];
            read_str("Choose the task description: ", task_description);

            char task_category[TASK_CATEGORY_SIZE];
            read_str("Choose the task category: ", task_category);

            const Task *task = init_task(task_priority, task_description, task_category);
            if (!task) exit(-1);

            Task all_tasks[TOTAL_TASKS];

            if (count > 0) {
                read_file(all_tasks);
                all_tasks[count] = *task;
                write_file(all_tasks);
            } else {
                write_file(task);
                read_file(all_tasks);
            }

            print_tasks(all_tasks, count);

            printf("\n");
            printf("Task was added successfully!\n");

            count++;
        } else {
            printf(":: ERROR :: Choose a valid option, try again\n");
            continue;
        }
    }
    return 0;
}