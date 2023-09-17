//
// Created by pprod on 17/09/2023.
//

#include "../../models/task/Task.h"
#include "../../helpers/helpers.h"

void list_tasks(int size) {
    Task all[TOTAL_TASKS];
    read_file(all);
    print_tasks(all, size);
}