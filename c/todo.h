#ifndef TODO_H
#define TODO_H
#define debug(c, n) printf("%s %d\n", (char*)c, (int)n)
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

void add(FILE* fptr, char event[]) {
  //TODO: IMPLEMENT CHECK FUNCTION TO CHECK WHETHER THE EVENT OF THE SAME NAME EXISTS IN THE TEXT FILE.
  // fprintf(fptr, "[%d] %s\n" /*" %s\n"*/, countTodo(fptr), event);
  fprintf(fptr, "%s\n" /*" %s\n"*/, event);
  // fprintf(fptr, "%s\n", event);
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
  char c[50][128];
  int count = 0;
  // debug("Checking c", 1);
  // strcpy(c[count], "\0");
  while(fgets(c[count], 128, fptr) != NULL) {
    // printf("%s\n", c[count]);
    count++;
    // strcpy(c[count], "\0");
  }
  // debug("After checking c", 1);
  debug("Count =", count);
  for (int i = 0; i < count; i++) {
    printf("[%d] %s", count - i, c[count - i - 1]);
  }
  printf("\n");
}

void delete(FILE* fptr_original, int event_number) {
  if(event_number > countTodo(fptr_original)) {
    printf("Error: todo #%d does nor exit. Nothing deleted\n", event_number);
  }
  char temp[] = "temp.txt";
  char c[128];
  int curr_line = 0;
  FILE* fptr_temp = fopen(temp, "w");
  if(fptr_temp == NULL) {
    printf("Error!\n");
    exit(1);
  }
  while(fgets(c, 128, fptr_original) != NULL) {
    fprintf(fptr_temp, "%s", c);
  }
  fclose(fptr_original);
  remove("todo.txt");
  fptr_original = fopen("todo.txt", "r+");
  while (fgets(c, 128, fptr_temp) != NULL) {
    curr_line++;
    if(curr_line != event_number) {
      fprintf(fptr_original, "%s", c);
    }
  }
  fclose(fptr_temp);
  remove("temp.txt");
}

#endif
