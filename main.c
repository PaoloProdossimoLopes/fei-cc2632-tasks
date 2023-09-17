#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "models/task/Task.h"

int read_int(char *message) {
    int input;
    printf("%s", message);
    int status = scanf("%d", &input);
    if (status < 0)
        return status;
    return input;
}

void read_str(char *message, char *str) {
    fflush(stdin);
    printf("%s", message);
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
}

void generate_menu() {
    printf("::::::::: MENU :::::::::\n");
    printf(":: 1 - Create task\n");
    printf("::::::::::::::::::::::::\n");
}

int main() {
    while (true) {
        generate_menu();

        const int input = read_int("\nWhat you want to do? ");

        const int is_create_menu_option = input == 1;
        if (is_create_menu_option) {
            const int task_priority = read_int("Choose the task priority: ");

            char task_description[100];
            read_str("Choose the task description: ", task_description);

            char task_category[100];
            read_str("Choose the task category: ", task_category);

            Task *task = init_task(task_priority, task_description, task_category);
            if (!task) exit(-1);

            FILE *file = fopen("tasks.json", "w");
            if (!file) {
                printf(":: ERROR :: File not found\n");
                exit(-1);
            }

            fprintf(file, "{");
            fprintf(file, "\"tasks\": [");
            fprintf(file, "{");
            fprintf(file, "\"priority\": %d,", task->priority);
            fprintf(file, "\"description\": \"%s\",", task->description);
            fprintf(file, "\"category\": \"%s\"", task->category);
            fprintf(file, "}");
            fprintf(file, "]");
            fprintf(file, "}");

            fclose(file);

            printf("Task was added successfully!\n");
        } else {
            printf(":: ERROR :: Choose a valid option, try again\n");
            continue;
        }
    }
    return 0;
}
