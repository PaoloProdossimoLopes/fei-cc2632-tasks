//
// Created by pprod on 17/09/2023.
//

#include <stdio.h>

#include "../models/task/Task.h"
#include "../helpers/helpers.h"

int create_task(int priority, const char description[], const char category[], int accumulator) {
    const Task *task = init_task(priority, description, category);
    if (!task) return -1;

    Task all_tasks[TOTAL_TASKS];

    if (accumulator > 0) {
        const int read_status = read_file(all_tasks);
        if (read_status < 0) return read_status;

        all_tasks[accumulator] = *task;

        const int write_status = write_file(all_tasks);
        if (write_status < 0) return write_status;
    } else {
        const int write_status = write_file(task);
        if (write_status < 0) return write_status;

        const int read_status = read_file(all_tasks);
        if (read_status < 0) return read_status;
    }

    print_tasks(all_tasks, accumulator);

    printf("\n");
    printf("Task was added successfully!\n");
    return 0;
}