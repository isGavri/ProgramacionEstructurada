#include <stdlib.h>
#define clean_buffer fgetc(stdin)
#define ask_opt printf("¿Que operacion deseas realizar?")
#include "student/operations.c"
#include "utils.c"
#include <stdio.h>
void add_calif_data(student_t *s) {
  int i = 0;
  while (i < 5) {
    system("clear");
    printf("-- Igreso de materias --\n");
    printf("Ingresa el nombre de la materia %d: ",i+1);
    s->calificaciones[i].nombre = get_line();
    printf("Ingresa la calificacion de %s: ", s->calificaciones[i].nombre);
    scanf("%f", &s->calificaciones[i].calificacion);
    clean_buffer;
    i++;
  }
}
void add_family_data(student_t *s) {
  system("clear");
  printf("-- Ingreso de datos personales de un familiar --\n");
  printf("Ingresa el nombre de la persona: ");
  s->family_data.name = get_line();
  printf("Ingresa la relacion de la persona con el estudiante: ");
  s->family_data.relation = get_line();
  printf("Ingresa el numero telefonico de la persona: ");
  s->family_data.num = get_line();
}
void create_menu() {
  student_t new_student;
  system("clear");
  printf("-- Ingreso de datos personales del estudiante --\n");
  printf("Ingresa el nombre del estudiante: ");
  new_student.name = get_line();
  printf("Ingresa la edad del estudiante: ");
  scanf("%d", &new_student.age);
  clean_buffer;
  printf("Ingresa el grupo del estudiante (A/B/C/D): ");
  new_student.group = get_line();
  add_family_data(&new_student);
  add_calif_data(&new_student);
  add_to_the_database(&new_student);
  read_all();
  // TODO: listar el nuevo estado de la base de datos
}
void consult_menu() {
  printf("¿Como deseas ver los datos?\n(I) Alumno individual\n(G) Registro "
         "General\n(g) Por grupos\n(M) Por materias\nOption: ");
  char opt = fgetc(stdin);
  clean_buffer;
  switch (opt) {
  case 'I': {
    // TODO:
    break;
  }
  case 'G': {
    // TODO:
    break;
  }
  case 'g': {
    // TODO:
    break;
  }
  case 'M': {
    // TODO:
    break;
  }
  }
}
void modification_menu() {
  ask_opt;
  printf("\n(E) Eliminar registro\n(M) "
         "Modificar registro\n(C) Crear registro\nOption: ");
  int opt = fgetc(stdin);
  clean_buffer;
  switch (opt) {
  case 'E': {
    // TODO:
    break;
  }
  case 'M': {
    // TODO:
    break;
  }
  case 'C': {
    create_menu();
    // TODO:
    break;
  }
  }
}
void print_opt() {
  ask_opt;
  printf("\n(C) Consultar registros\n(M) Modificar "
         "registros\nOption: ");
}
void main_menu() {
  printf("-- -- -- -- -- -- SIIAU -- -- -- -- -- --\n");
  print_opt();
  char opt = fgetc(stdin);
  clean_buffer;
  switch (opt) {
  case 'C': {
    consult_menu();
    break;
  }
  case 'M': {
    modification_menu();
    break;
  }
  }
}
