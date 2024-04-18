#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  list *head = NULL;
  printf("Lista original\n");
  add_end(&head, 1, "Fernando");
  add_end(&head, 2, "Jose");
  add_end(&head, 3, "Maria");
  add_end(&head, 5, "Diego");
  add_end(&head, 4, "Pedro");
  print_list(head);

  printf("Lista borrada\n"); 
  delete_end(&head);
  delete_end(&head);
  print_list(head);
  
  printf("Impresion con recursion\n");
  print_recursion(&head);
  return 0;
}
