#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define debug(c, n) printf("%s %d\n", (char*)c, (int)n)
#include"list.h"
//done is 0 if task is not completed, and 1 if completed.
// struct Todo {
//   int done;
//   char event[128];
//   struct Todo* next;
//   struct Todo* prev;
// };
//
// typedef struct Todo Todo;
//
// struct List {
//   Todo* head;
//   Todo* tail;
// };

void help();
void add(char add_todo[]);
int number_of_tasks = 0;
List *tasks;

int main(int argc, char const *argv[]) {
  char add_todo[128];
  tasks = (List*)malloc(1 * sizeof(List));
  init(tasks);
  if(argc == 1 || !strcmp(argv[1], "help") || argv[1] == NULL) {
    help();
    return 0;
  }
  //TODO: .\todo add #add a new todo..
  if(!strcmp(argv[1], "add")) {
    // debug("Inside strcmp", 2);
    strcpy(add_todo, argv[2]);
    add(add_todo);
  }
  return 0;
}

void help() {
  char usage[] = "Usage :-";
  char first_line[] = "./todo add \"todo item\"         # Add a new todo";
  char second_line[] = "./todo ls                      # Show remaining todos";
  char third_line[] = "./todo del NUMBER              # Delete a todo";
  char fourth_line[] = "./todo done NUMBER             # Complete a todo";
  char fifth_line[] = "./todo help                    # Show usage";
  char sixth_line[] = "./todo report                  # Statistics";
  printf("%s\n", usage);
  printf("%s\n", first_line);
  printf("%s\n", second_line);
  printf("%s\n", third_line);
  printf("%s\n", fourth_line);
  printf("%s\n", fifth_line);
  printf("%s\n", sixth_line);
}

void add(char add_todo[]) {
  // debug("Inside add()", 3);
  if(check(tasks, add_todo)) {
    printf("Already in the todo list\n");
    return ;
  }
  // tasks[number_of_tasks]->event = add_todo;
  // debug("After checking", 4);
  addTodo(tasks, add_todo);
  number_of_tasks++;
  printf("Added todo: \"%s\"\n", add_todo);
}
