#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "models/task/Task.h"
#include "helpers/helpers.h"
#include "core/create_task.h"

#define LIST_TASKS_OPTION 1
#define CREATE_TASKS_OPTION 2

void generate_menu() {
    printf("::::::::: MENU :::::::::\n");
    printf(":: %d - List tasks\n", LIST_TASKS_OPTION);
    printf(":: %d - Create task\n", CREATE_TASKS_OPTION);
    printf("::::::::::::::::::::::::\n");
}

int main() {
    int count = 0;
    while (true) {
        generate_menu();

        const int input = read_int("\nWhat you want to do? ");

        if (input == LIST_TASKS_OPTION) {
            Task all[TOTAL_TASKS];
            read_file(all);
            print_tasks(all, count);
        } else if (input == CREATE_TASKS_OPTION) {
            const int task_priority = read_int("Choose the task priority: ");

            char task_description[TASK_DESCRIPTION_SIZE];
            read_str("Choose the task description: ", task_description);

            char task_category[TASK_CATEGORY_SIZE];
            read_str("Choose the task category: ", task_category);

            const int create_status = create_task(task_priority, task_description, task_category, count);
            if (create_status < 0) exit(create_status);

            count++;
        } else {
            printf(":: ERROR :: Choose a valid option, try again\n");
            continue;
        }
    }
    return 0;
}