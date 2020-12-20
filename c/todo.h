#ifndef TODO_H
#define TODO_H
void help();
void display(FILE* fptr);
void add(FILE* fptr, char event[]);
int countTodo(FILE* fptr);
int countCompleted(FILE* fptr);
void delete(FILE* fptr, int event_number);
void done(FILE* fptr, int done_number);
void status(FILE* fptr);

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

// void display(/* arguments */) {
//   FILE* fptr = fopen("todo.txt", "r+");
//   if(fptr == NULL) {
//     printf("Error!\n");
//     exit(1);
//   }
//   char c[128];
//   while(fgets(c/*[i]*/, 128, fptr) != NULL) {
//     printf("%s", c);
//   }
//   printf("\n");
//   fclose(fptr);
//   // free(c);
// }

void add(FILE* fptr, char event[]) {
  // int number_of_event = count();
  // fprintf(fptr, "\n");
  // if(check(fptr, event)) {
  //   printf("The event already exists!\n");
  //   return ;
  // }
  fprintf(fptr, "\n%s\n", event);
  printf("Added todo: \"%s\"\n", event);
}

int countTodo(FILE* fptr) {
  char c[128];
  int count = 0;
  while(fgets(c, 128, fptr) != NULL) {
    count++;
  }
  return count + 1;
}

void display(FILE* fptr) {
  if(countTodo(fptr) == 1) {
    return ;
  }
  char c[50][128];
  int count = 0;
  strcpy(c[count], "\0");
  while(fgets(c[count], 128, fptr) != NULL) {
    // printf("%s\n", c[count]);
    count++;
    strcpy(c[count], "\0");
  }
  for (int i = 0; i < count; i++) {
    printf("[%d] %s", i + 1, c[count - i - 1]);
  }
  printf("\n");
}

void delete(FILE* fptr_original, int event_number) {
  if(event_number > countTodo(fptr_original)) {
    printf("Error: todo #%d does not exist. Nothing deleted.\n", event_number);
    return ;
  }
  char temp[] = "temp.txt";
  char str[128];
  int count = 1;
  FILE* fptr_temp = fopen(temp, "w");
  if(fptr_temp == NULL) {
    printf("Error!\n");
    exit(1);
  }
  while(!feof(fptr_original)) {
    strcpy(str, "\0");
    fgets(str, 128, fptr_original);
    if(!feof(fptr_original)) {
      count++;
      if(count != event_number) {
        fprintf(fptr_temp, "%s", str);
      }
    }
  }
  fclose(fptr_original);
  fclose(fptr_temp);
  remove("todo.txt");
  rename(temp, "todo.txt");
  fptr_original = fopen("todo.txt", "w");
}

#endif
