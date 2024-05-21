#include "database_operations.cpp"
#include "utils.cpp"
#include <cstdio>
#include <cstdlib>
#include <string>

#define opti "¿Que operacion deseas realizar?\n"
#define wait sleep(1)

void main_menu();
void list_menu();

// *** Menus para modificaciones en la db ***

// Menu para modificar registro

void fill_student_data(int id) {
  system("clear");
  printf("*** Datos del estudiante ***\n"
         "Ingrese el nombre del estudiante: ");
  std::string name = get_line(50);
  printf("Ingrese la edad del estudiate: ");
  unsigned short int age;
  scanf("%hu", &age);
  fgetc(stdin);
  printf("Ingrese el grupo del estudiante: ");
  std::string group = get_line(1);
  system("clear");
  printf("*** Datos de familiar ***\n"
         "Ingrese el nombre del familiar: ");
  std::string family_name = get_line(50);
  printf("Ingrese la relacion del familiar con el estudiante: ");
  std::string family_relation = get_line(50);
  printf("Ingrese el numero telefonico del familiar: ");
  std::string family_num = get_line(10);
  std::unordered_map<std::string, double> map;
  char opt = 'a';
  while (opt == 'a') {
    system("clear");
    printf("*** Ingreso de calificaciones ***\n"
           "Nombre de la materia: ");
    std::string materia = get_line(50);
    printf("Calificacion de la materia: ");
    double calif = 0;
    scanf("%lf", &calif);
    fgetc(stdin);
    map[materia] = calif;
    printf("Añadir otra materia (a) Terminar el registro (C): ");
    opt = fgetc(stdin);
    fgetc(stdin);
  }

  Family datos_familia(family_name, family_relation, family_num);

  Student new_student(name, age, map, datos_familia, group);

  insert(&new_student, id);
  system("clear");
  main_menu();
}

// Menu para crear un nuevo registro

void fill_student_data() {
  printf("ID y calificaciones son inputs numericas\n");
  wait;
  wait;
  system("clear");
  printf("*** Datos del estudiante ***\n"
         "Ingrese el nombre del estudiante: ");
  std::string name = get_line(50);
  printf("Ingrese la edad del estudiate: ");
  unsigned short int age;
  scanf("%hu", &age);
  fgetc(stdin);
  printf("Ingrese el grupo del estudiante: ");
  std::string group = get_line(1);
  system("clear");
  printf("*** Datos de familiar ***\n"
         "Ingrese el nombre del familiar: ");
  std::string family_name = get_line(50);
  printf("Ingrese la relacion del familiar con el estudiante: ");
  std::string family_relation = get_line(50);
  printf("Ingrese el numero telefonico del familiar: ");
  std::string family_num = get_line(10);
  std::unordered_map<std::string, double> map;
  char opt = 'a';
  while (opt == 'a') {
    system("clear");
    printf("*** Ingreso de calificaciones ***\n"
           "Nombre de la materia: ");
    std::string materia = get_line(50);
    printf("Calificacion de la materia: ");
    double calif = 0;
    scanf("%lf", &calif);
    fgetc(stdin);
    map[materia] = calif;
    printf("Añadir otra materia (a) Terminar el registro (C): ");
    opt = fgetc(stdin);
    fgetc(stdin);
  }

  Family datos_familia(family_name, family_relation, family_num);

  Student new_student(name, age, map, datos_familia, group);

  insert(&new_student);
  system("clear");
  main_menu();
}

// Menu para modificar un registro

void modify_registry_menu() {
  list_all();
  printf("(f) Filtrar\t(i) Ingresar el ID\n");
  char opt = fgetc(stdin);
  fgetc(stdin);
  if (opt == 'f') {
    list_menu();
  }
  printf("Ingrese el ID del estudiante a modificar: ");
  int id = 0;
  scanf("%d", &id);
  fgetc(stdin);
  fill_student_data(id);
}

// Menu para dar de baja un alumno

void deregister_menu() {
  list_all();
  printf("(f) Filtrar\t(i) Ingresar el ID\n");
  char opt = fgetc(stdin);
  fgetc(stdin);
  if (opt == 'f') {
    list_menu();
  }
  printf("Ingrese el ID del estudiante a modificar: ");
  int id = 0;
  scanf("%d", &id);
  fgetc(stdin);
  deregister(id);
  system("clear");
  main_menu();
}

// Menu para modificaciones en la base de datos

void modify_menu() {
  printf(opti "(C) Dar de alta un nuevo alumno\n(M) Modificar registro\n(B) "
              "Dar de baja a un alumno\n");
  char opt = fgetc(stdin);
  fgetc(stdin);
  switch (opt) {
  case 'C': {
    fill_student_data();
    break;
  }
  case 'M': {
    modify_registry_menu();
    break;
  }
  case 'B': {
    deregister_menu();
    break;
  }
  }
}
// *** Funciones de listado ***

// Menu de listado por materia

void list_by_materia_menu() {
  printf("Ingrese el nombre de la materia: ");
  std::string materia = get_line(50);
  list_by_materia(materia);
}

// Menu de listado por grupo

void list_by_group_menu() {
  printf("Selecciona el grupo del que deseas listar los "
         "estudiantes\nGrupo: ");
  std::string grupo = get_line(10);
  list_by_group(grupo);
  printf("Presiona enter para continuar: ");
}

//  Menu de listado por id

void list_by_id_menu() {
  printf("Ingresa el id del estudiante: \n");
  unsigned int id = 0;
  scanf("%u", &id);
  fgetc(stdin);
  if (id <= 0) {
    printf("ID invalido");
  }
  list_by_id(id);
}

// Menu para opcion de listado

void list_menu() {
  printf(opti "(A) Listar todos los alumnos\n(I) Listar por ID\n(G) Listar por "
              "grupo\n(M) Listar por materia\nOpcion: ");
  char opt = fgetc(stdin);
  fgetc(stdin);
  switch (opt) {
  case 'A': {
    system("clear");
    list_all();
    printf("Pulsa enter para continuar ");
    fgetc(stdin);
    system("clear");
    main_menu();
    break;
  }
  case 'I': {
    list_by_id_menu();
    printf("Pulsa enter para continuar ");
    fgetc(stdin);
    system("clear");
    main_menu();
    break;
  }
  case 'G': {
    list_by_group_menu();
    printf("Pulsa enter para continuar ");
    fgetc(stdin);
    system("clear");
    main_menu();
    break;
  }
  case 'M': {
    list_by_materia_menu();
    printf("Pulsa enter para continuar ");
    fgetc(stdin);
    system("clear");
    main_menu();
    break;
  }
  default: {
    printf("Opcion inexistente");
    sleep(2);
    system("clear");
    list_menu();
  }
  }
}

// *** Funciones de borrado de db ***

// Menu de confirmacion para borrar los datos de la db

void delete_menu() {
  printf("Estas seguro de querer eliminar la base de datos? (S)si (X)no\n");
  char opt = fgetc(stdin);
  fgetc(stdin);
  if (opt == 'S') {
    delete_database();
  }
  system("clear");
  main_menu();
}

// *** Funcinoes de menu principal ***

// Menu de opciones iniciales

void option_menu() {
  printf(opti "(M) Modificar base de datos de alumnos\n(L) Listar en base de "
              "datos\n(E) Eliminar la base de datos\n(S) Salir\nOpcion: ");
  char opt = fgetc(stdin);
  fgetc(stdin);
  switch (opt) {
  case 'M': {
    modify_menu();
    wait;
    break;
  }
  case 'L': {
    list_menu();
    wait;
    break;
  }
  case 'E': {
    delete_menu();
    wait;
    break;
  }
  case 'S': {
    printf("Nos vemos :)\n");
    exit(EXIT_SUCCESS);
  }
  default: {
    printf("Opcion invalida\n");
    sleep(2);
    system("clear");
    option_menu();
  }
  }
}

// Menu de inicio

void main_menu() {
  printf("*** *** *** SIIAU *** *** ***\nInicio del registro de "
         "alumnos\n");
  option_menu();
}
