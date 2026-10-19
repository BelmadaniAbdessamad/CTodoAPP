#ifndef TODO_H
#define TODO_H
#define SUCCESS 0
#define FAIL 1
#define APP_VERSION "1.0"

typedef struct
{
    int id;
    int done;
    char value[255];
}Todo;

void display_header();
void display_menu();
Todo init_todo(char value[255]);
int add_todo(Todo * todos, Todo *todo,int max_todos);
int done_todo(Todo * todos, int id);
Todo * find_todo(Todo * todos , int id);
int remove_todo(Todo * todos, int id);
void list_todos(Todo * todos);
void to_string(Todo * todo,int order);
void todo_app(Todo * todos,int max_todos);

#endif