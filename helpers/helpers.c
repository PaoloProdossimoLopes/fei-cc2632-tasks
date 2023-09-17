//
// Created by pprod on 17/09/2023.
//

#include <stdio.h>
#include <strings.h>

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