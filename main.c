#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
    int priority;
    char *description;
    char *category;
} Task;

Task *init_task(int priority, char *description, char *category) {
    Task *task = malloc(sizeof(Task));
    task->priority = priority;
    task->description = description;
    task->category = category;
    return task;
}

void print_task(Task task) {
    printf(":::: TASK ::::\n");
    printf("Priority: %d\n", task.priority);
    printf("Description: %s\n", task.description);
    printf("Category: %s\n", task.category);
    printf("==============\n");
}

int main() {
    Task *task = init_task(0, "any description", "any category");
    print_task(*task);
    return 0;
}
