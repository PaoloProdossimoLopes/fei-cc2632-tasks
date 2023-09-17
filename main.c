#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "models/task/Task.h"
#include "helpers/helpers.h"
#include "core/create_task.h"

void generate_menu() {
    printf("::::::::: MENU :::::::::\n");
    printf(":: 1 - Create task\n");
    printf("::::::::::::::::::::::::\n");
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