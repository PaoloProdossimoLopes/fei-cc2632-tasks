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

void write_file(const Task *task) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file) {
        printf("%s", FILE_NOT_FOUND_ERROR);
        exit(-1);
    }
    fwrite(task, sizeof(Task), 1, file);
    fclose(file);
}

void read_file(Task *task) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("%s", FILE_NOT_FOUND_ERROR);
        exit(-1);
    }
    fread(task, sizeof(Task), 1, file);
    fclose(file);
}

int main() {
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

            write_file(task);

            Task registered_tasks;
            read_file(&registered_tasks);

            printf("DESCRICAO: %s\n", registered_tasks.description);
            printf("Task was added successfully!\n");
        } else {
            printf(":: ERROR :: Choose a valid option, try again\n");
            continue;
        }
    }
    return 0;
}
