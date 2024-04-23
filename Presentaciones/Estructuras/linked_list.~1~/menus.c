#include "utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

list *head;

void delete(int opt) {
  if (opt) {
    delete_start(&head);
    return;
  }
  delete_end(&head);
}

void print(int opt) {
  system("clear");
  if (opt) {
    printf("Impresion recursiva:\n\n");
    print_recursion(&head);
  } else {
    printf("Impresion con loops:\n\n");
    print_list(head);
  }
  printf("\n\nContinuar (enter)\n");
  fgetc(stdin);
  return;
}

void add(int opt) {
  int id;
  printf("ID de la persona a ingresar: ");
  scanf("%d", &id);
  printf("Nombre de la persona a ingresar: ");
  fgetc(stdin);
  char *name = get_line();
  if (opt) {
    add_start(&head, id, name);
    return;
  }
  add_end(&head, id, name);
}

void menu_opts() {
  system("clear");
  printf("Ingresa letra que se encuentra entre parentesis despues de la "
         "opcion que quieras realizar\n");

  printf("1. Añadir elemento al final de la lista (a)\n2. Añadir elemento al "
         "inicio de la lista (i)\n3. Eliminar elemento al final de la lista "
         "(d)\n4. Eliminar elemento al inicio de la lista (D)\n5. Ordenar la "
         "lista (o)\n6. Imprimir con loops (p)\n7. Imprimir con recursividad "
         "(P)\n8. Salir del programa (S)\n");
  char opt = fgetc(stdin);
  clean_buffer();
  switch (opt) {
  case 'a': {
    add(0);
    menu_opts();
    break;
  }
  case 'i': {
    add(1);
    menu_opts();
    break;
  }
  case 'd': {
    delete (0);
    menu_opts();
    break;
  }
  case 'D': {
    delete (1);
    menu_opts();
    break;
  }
  case 'o': {
    sort(&head);
    menu_opts();
    break;
  }
  case 'p': {
    print(0);
    menu_opts();
    break;
  }
  case 'P': {
    print(1);
    menu_opts();
    break;
  }
  case 'S': {
    printf("Hasta luego!\n");
    break;
  }
  }
}
void main_menu() {
  printf("### ----- Bienvenido al programa de lista enlazada ----- ###\n");
  printf("# --- Se ha inicializado una lista vacia\n");
  printf("# --- ¿Que deseas hacer con la lista?\n");
  sleep(2);
  menu_opts();
}
