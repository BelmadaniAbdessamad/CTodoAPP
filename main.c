#include <stdio.h>
#include <stdlib.h>
#include "todoapp.h"

int main()
{
    int MAX_TODOS = 20;
    Todo *todos = malloc(MAX_TODOS * sizeof(Todo));
    if(todos == NULL) {
        printf("\nERROR allocating memory in main.c\n");
        return 1;
    }

    todo_app(todos,MAX_TODOS);
    free(todos);

    return 0;
}