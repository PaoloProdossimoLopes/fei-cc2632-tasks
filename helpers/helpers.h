//
// Created by pprod on 17/09/2023.
//

#ifndef TASKS_HELPERS_H
#define TASKS_HELPERS_H

void read_str(char *message, char *str);
int read_int(char *message);
int write_file(const Task task[]);
int read_file(Task *task[]);

#endif //TASKS_HELPERS_H
