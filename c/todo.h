#ifndef TODO_H
#define TODO_H
void help();
void display(FILE* fptr);
void add(FILE* fptr, char event[]);
int count(FILE* fptr);
void delete(FILE* fptr, int event_number);

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
  fprintf(fptr, "[%d] %s\n", count(fptr), event);
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

void display(FILE* fptr) {
  char c[50][128];
  int count = 0;
  while(fgets(c[count], 128, fptr) != NULL) {
    // printf("%s\n", c[count]);
    count++;
  }
  for (size_t i = 0; i < count; i++) {
    printf("%s", c[count - i - 1]);
  }
  printf("\n");
}
//
// void delete(FILE* fptr_original, int event_number) {
//   if(event_number > count(fptr_original)) {
//     printf("Error: todo #%d does not exist. Nothing deleted.\n", event_number);
//   }
//   char temp[] = "temp.txt";
//   char c[128];
//   int curr_line = 0;
//   FILE* fptr_temp = fopen(temp, "w");
//   if(fptr_temp == NULL) {
//     printf("Error!\n");
//     exit(1);
//   }
//   while (fgets(c, 128, fptr_original) != NULL) {
//     char *str = (char*)c[3];
//     curr_line++;
//     if(curr_line != event_number) {
//       curr_line--;
//       add(fptr_temp, str);
//     }
//   }
//   display(fptr_temp);
//   fclose(fptr_original);
//   if(remove("todo.txt") == 0)
//     printf("Deleted Successfully!\n");
//   fclose(fptr_temp);
//   rename("temp.txt", "todo.txt");
//   // fptr_original = fopen("todo.txt", "r+");
//   fclose(fptr_temp);
// }

void delete(FILE* fptr_original, int event_number) {
  if(event_number > count(fptr_original)) {
    printf("Error: todo #%d does nor exit. Nothing deleted\n", event_number);
  }
  char temp[] = "temp.txt";
  char c[256];
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
  fptr_original = fopen("todo.txt", "w");
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
