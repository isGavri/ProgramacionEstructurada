#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  char *name;
  struct Node *next;
} list;

list *merge(list *a, list *b) {
  list* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->id <= b->id) {
        result = a;
        result->next = merge(a->next, b);
    }
    else {
        result = b;
        result->next = merge(a, b->next);
    }
    return (result);
  return a;
}

void split(list *head, list **a, list **b) {
  list *slow;
  list *fast;
  fast = head->next;
  slow = head;

   while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
  
  *a = head;
  *b = slow->next;
  slow->next = NULL;
}
void sort(list **head) {
  list *node = *head;
  list *a;
  list *b;

  if ((node == NULL) || (node->next == NULL)) {
    return;
  }

  split(node, &a, &b);

  sort(&a);
  sort(&b);

  *head = merge(a, b);
}

void add_end(list **head, int id, char *name) {
  if (*head == NULL) {
    *head = malloc(sizeof(list));
    (*head)->id = id;
    (*head)->name = name;
    (*head)->next = NULL;
    return;
  }
  list *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = malloc(sizeof(list));
  current->next->id = id;
  current->next->name = name;
  current->next->next = NULL;
}

void add_start(list **head, int id, char *name) {
  if (*head == NULL) {
    *head = malloc(sizeof(list));
    (*head)->id = id;
    (*head)->name = name;
    (*head)->next = NULL;
    return; 
  }
  list *new_head = malloc(sizeof(list));
  new_head->name = name;
  new_head->id = id;
  new_head->next = *head;
  *head = new_head;
}

void delete_start(list **head) {
  if (*head == NULL) {
    return;
  }
  list *remove = *head; 
  *head = (*head)->next;
  free(remove);
}

void delete_end(list **head) {
  if (*head == NULL) {
    return;
  }
  list *current = *head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  list *remove = current->next;
  current->next = NULL;
  free(remove);
}

void print_recursion(list **head) {
  if (*head == NULL) {
    return;
  } else {
    printf("El nombre de la persona numero %d es %s\n", (*head)->id,
           (*head)->name);
    print_recursion(&(*head)->next);
  }
}

void print_list(list *head) {
  list *current = head;
  while (current != NULL) {
    printf("El nombre de la persona numero %d es %s\n", current->id,
           current->name);
    current = current->next;
  }
}
