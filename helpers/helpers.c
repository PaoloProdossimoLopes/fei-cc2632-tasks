//
// Created by pprod on 17/09/2023.
//

#include <stdio.h>
#include <strings.h>
#include "../models/task/Task.h"

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

int write_file(const Task task[]) {
    FILE *file = fopen(FILE_NAME, "wb+");
    if (!file) {
        printf("%s", FILE_NOT_FOUND_ERROR);
        return -1;
    }
    fseek(file, 0, SEEK_END);
    fwrite(task, sizeof(Task), 1, file);
    fclose(file);

    return 0;
}

int read_file(Task task[]) {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        printf("%s", FILE_NOT_FOUND_ERROR);
        return -1;
    }
    fread(task, sizeof(Task), 100, file);
    fclose(file);

    return 0;
}