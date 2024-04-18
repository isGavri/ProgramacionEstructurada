#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  char *name;
  struct Node *next;
} list;

void sort(list **head){

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
void delete_end(list **head){
  if(*head == NULL){
    printf("Lista vacia");
    return;
  }
  list *current = *head;
  while (current->next->next != NULL){
    current = current->next;
  }
  current->next = NULL;
  free(current->next);
}
void print_recursion(list **head){
  if(*head == NULL){
    printf("Fin de la lista\n");
    return;
  } else {
    printf("El nombre de la persona numero %d es %s\n", (*head)->id, (*head)->name);
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
