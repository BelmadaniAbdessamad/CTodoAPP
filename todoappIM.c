// Todo APP persisted in memory
// Author : Abdessamad Belmadani
#include "todoapp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int todos_count = 0;
static int last_id = 0;

void to_string(Todo *todo, int order)
{
    printf("| %-5d | %-5d | %-35.35s | %-12s |\n", order+1, todo->id, todo->value, todo->done == 1 ? "Done" : "In progress");
}

void list_todos(Todo *todos)
{
    // printf("list todos function call\n");

    if (todos_count == 0)
    {
        printf("|                    No todos yet.                                  |\n");
        return;
    }
    printf("\n");
    printf("+-------+-------+-------------------------------------+--------------+\n");
    printf("| Order | ID    | Task                                | Status       |\n");
    printf("+-------+-------+-------------------------------------+--------------+\n");

    for (int i = 0; i < todos_count; ++i)
    {
        to_string(&todos[i], i);
    }
}
void display_header()
{
    printf("################# TODO-APP %s #################\n", APP_VERSION);
}
void display_menu()
{
    printf("\nActions : A(dd) D(one) R(emove) Q(uit) : ");
}

Todo init_todo(char value[255])
{
    // printf("init todo function call\n");
    Todo todo;
    todo.id = last_id++;
    todo.done = 0;
    strcpy(todo.value, value);
    return todo;
}
Todo *find_todo(Todo *todos, int id)
{

    for (int i = 0; i < todos_count; i++)
    {
        if (todos[i].id == id)
            return &todos[i];
    }
    return NULL;
}
int add_todo(Todo *todos, Todo *todo, int max_todos)
{
    // printf("add todo function call\n");
    // if we hit the limit of max_todos we must expand the todos list
    //printf("\nmax todos = %d\n", max_todos);
    if (todos_count >= max_todos)
    {
        printf("\nYou hit the todos limit\n");
        return 1;
    }

    todos[todos_count] = *todo;
    todos_count++;
    //printf("todos count = %d\n", todos_count);
    return 0;
}
int done_todo(Todo *todos, int id)
{

    Todo *found_todo = find_todo(todos, id);

    if (found_todo == NULL)
    {
        printf(" [Todo[id:%d] is not found]", id);
        return FAIL;
    }

    found_todo->done = 1;
    return SUCCESS;
}
int remove_todo(Todo *todos, int id)
{

    Todo *found_todo = find_todo(todos, id);
    if (found_todo == NULL)
    {
        printf(" [Todo[id:%d] is not found]", id);
        return FAIL;
    }

    for (int i = id; i < todos_count; i++)
    {
        todos[i] = todos[i + 1];
    }
    todos_count--;
    return SUCCESS;
}

void todo_app(Todo *todos, int max_todos)
{
    display_header();
    while (1)
    {

        list_todos(todos);
        display_menu();

        char option;
        scanf(" %c", &option);
        getchar();

        switch (option)
        {
        case 'a':
        case 'A':
            char value[255];
            printf("Todo value : ");
            fgets(value, sizeof(value), stdin);
            value[strcspn(value, "\n")] = '\0';
            Todo new_todo = init_todo(value);
            add_todo(todos, &new_todo, max_todos);
            break;
        case 'd':
        case 'D':
            int id;
            printf("\nEnter todo Id(entifier) : ");
            scanf(" %d", &id);
            if (done_todo(todos, id) == SUCCESS)
            {
                printf("\n This TODO[id:%d] is set DONE\n", id);
            }
            else
            {
                printf("\n Failed Doning This TODO[id:%d]\n", id);
            }

            break;
        case 'r':
        case 'R':
            int id_r;
            printf("\nEnter todo Id(entifier) : ");
            scanf(" %d", &id_r);
            if (remove_todo(todos, id_r) == SUCCESS)
            {
                printf("\n This TODO[id:%d] is removed\n", id_r);
            }
            else
            {
                printf("\n Failing removing this TODO[id:%d]\n", id_r);
            }
            break;
        case 'q':
        case 'Q':
            printf("\nQuiting TODOAPP %s - Author : Abdessamad Belmadani\n", APP_VERSION);
            return;

        default:
            printf("\nInvalid action\n");
            break;
        }
    }
}