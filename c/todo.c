#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void help();
void display();
void add(char event[]);
int count(FILE* fptr);

int main(int argc, char const *argv[]) {
  if((argc == 2 && !strcmp(argv[1], "help")) || argc == 1) {
    help();
    return 0;
  }
  if(!strcmp(argv[1], "ls")) {
    display();
    return 0;
  }
  if(!strcmp(argv[1], "add")) {
    char event[128];
    strcpy(event, argv[2]);
    add(event);
    return 0;
  }
  return 0;
}

void help() {
  char first_line[] = "./todo add \"todo item\"  # Add a new todo";
  char second_line[] = "./todo ls               # Show remaining todos";
  char third_line[] = "./todo del NUMBER       # Delete a todo";
  char fourth_line[] = "./todo done NUMBER      # Complete a todo";
  char fifth_line[] = "./todo help             # Show usage";
  char sixth_line[] = "./todo report           # Statistics";
  printf("Usage :-\n");
  printf("%s\n", first_line);
  printf("%s\n", second_line);
  printf("%s\n", third_line);
  printf("%s\n", fourth_line);
  printf("%s\n", fifth_line);
  printf("%s\n", sixth_line);
}

void display(/* arguments */) {
  FILE* fptr = fopen("todo.txt", "r+");
  if(fptr == NULL) {
    printf("Error!\n");
    exit(1);
  }
  char c[128];
  // *c = (char*)malloc(128 * sizeof(char));
  // **c = (char**)malloc(50 * sizeof(char));
  // c = (char*)malloc(128 * sizeof(char));
  // int number_of_lines = count(fptr);
  // int i = 0;
  while(fgets(c/*[i]*/, 128, fptr) != NULL) {
    // fgets(c, 128, fptr);
    // fscanf(fptr, "%s", c);
    printf("%s", c);
    // i++;
  }
  /*
  for(int i =  0; i < number_of_lines; i++) {
    printf("%s\n", c[number_of_lines - i - 1]);
  }
  */
  printf("\n");
  fclose(fptr);
  // free(c);
}

void add(char event[]) {
  FILE* fptr = fopen("todo.txt", "r+");
  if(fptr == NULL) {
    printf("Error!\n");
    exit(1);
  }
  // int number_of_event = count();
  // fprintf(fptr, "\n");
  fprintf(fptr, "[%d] %s\n", count(fptr), event);
  fclose(fptr);
  printf("Added todo: \"%s\"\n", event);
}

int count(FILE* fptr) {
  char c[128];
  int count = 0;
  while(fgets(c, 128, fptr) != NULL) {
    count++;
  }
  return count + 1;
}
