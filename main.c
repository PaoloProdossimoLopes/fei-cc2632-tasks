#include <stdio.h>
#include <stdlib.h>

#include "models/task/Task.h"

int main() {
    Task *task = init_task(0, "any description", "any category");
    print_task(*task);
    return 0;
}
