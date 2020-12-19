#ifndef TODO_LIST_H
#define TODO_LIST_H
struct Todo {
  int done;
  char *event;
  struct Todo* next;
  struct Todo* prev;
};
typedef struct Todo Todo;
struct List {
  Todo* head;
  Todo* tail;
};
typedef struct List List;

void init(List *a) {
  a->head = NULL;
  a->tail = NULL;
}

int check(List *a, char event[]) {
  // debug("Inside check()", 5);
  if(a->head == NULL) {
    // debug("inside check if condition", 8);
    return 0;
  }
  // debug("After checking the null pointer condition", 6);
  Todo *travel = (Todo*)malloc(sizeof(Todo*));
  // debug("After allocating the travel pointer", 7);
  travel = a->head;
  // debug("After travel = a->head", 9);
  while(travel != NULL) {
    if(!strcmp(travel->event, event)) {
      return 1;
    }
    travel = travel->next;
  }
  return 0;
}

void addTodo(List *a, char *event) {
  Todo* temp = (Todo*)malloc(sizeof(Todo));
  temp->event = event;
  temp->done = 0;
  temp->next = NULL;
  if(a->head == NULL) {
    a->head = temp;
    a->tail = temp;
    return;
  }
  a->tail->next = temp;
  a->tail = a->tail->next;
}

void delteTodo(List *a, char *event) {
  if(a->head == NULL) {
    return ;
  }
  Todo* trav = (Todo*)malloc(sizeof(Todo));
  Todo* prev = (Todo*)malloc(sizeof(Todo));
  trav = a->head;
  while(trav != NULL && trav->event != event) {
    prev = trav;
    trav = trav->next;
  }
  if(trav == NULL) {
    return ;
  }
  trav->prev = prev;
  trav->next = prev->next->next;
}

void deleteLastTodo(List *a) {
  if(a->head == NULL) {
    return ;
  }
  a->tail = a->tail->prev;
  a->tail->next = NULL;
}

void display(List a) {
  if(a.head == NULL) {
    return ;
  }
  Todo* trav = (Todo*)malloc(sizeof(Todo));
  trav = a.head;
  while(trav != NULL) {
    printf("Event: %s\n", trav->event);
    trav = trav->next;
  }
  printf("\n");
}

#endif
