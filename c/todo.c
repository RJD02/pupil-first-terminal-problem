#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"todo.h"
#define debug(c, n) printf("%s %d\n", (char*)c, (int)n)

int main(int argc, char const *argv[]) {
  if((argc == 2 && !strcmp(argv[1], "help")) || argc == 1) {
    help();
    return 0;
  }
  FILE* fptr = fopen("todo.txt", "r+");
  if(fptr == NULL) {
    printf("Error!\n");
    exit(1);
  }
  if(!strcmp(argv[1], "ls")) {
    display(fptr);
    return 0;
  }
  if(!strcmp(argv[1], "add")) {
    char event[128];
    strcpy(event, argv[2]);
    add(fptr, event);
    return 0;
  }
  if(!strcmp(argv[1], "del")) {
    char event[2];
    strcpy(event, argv[2]);
    int event_number = event[0] - '0';
    // debug("event_number =", event_number);
    delete(fptr, event_number);
    return 0;
  }
  // if(!strcmp(argv[1], "done")) {
  //   char event[1];
  //   strcpy(event, argv[2]);
  //   int todo_completed = event[0] - '0';
  //   done(fptr, todo_completed);
  //   return 0;
  // }
  // if(!strcmp(argv[1], "report")) {
  //   status(fptr);
  //   return 0;
  // }
  fclose(fptr);
  return 0;
}
