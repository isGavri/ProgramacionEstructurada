#include <stdio.h>
typedef struct estudiantes {
  int id1;
  int id2;
  char a;
  char b;
  float porcentaje;
} estudiantes;

typedef struct estudiantes2 {
  int id1;
  char a;
  int id2;
  char b;
  float porcentaje;
} estudiantes2;

int main() {

  estudiantes estudiante1 = {1, 2, 'A', 'B', 90.5};
  printf("Tamaño de la struct: %lu\n", sizeof(estudiante1));
  printf("Address de la struct  = %p\n", &estudiante1);

  printf("\nAddress de id1        = %p", &estudiante1.id1);
  printf("\nAddress de id2        = %p", &estudiante1.id2);
  printf("\nAddress de a          = %p", &estudiante1.a);
  printf("\nAddress de b          = %p", &estudiante1.b);
  printf("\nAddress de porcentaje = %p\n", &estudiante1.porcentaje);

  estudiantes2 estudiante2 = {1, 2, 'A', 'B', 90.5};
  printf("\nTamaño de la struct: %lu\n", sizeof(estudiante2));
  printf("Address de la struct  = %p\n", &estudiante2);

  printf("\nAddress de id1        = %p", &estudiante2.id1);
  printf("\nAddress de a          = %p", &estudiante2.a);
  printf("\nAddress de id2        = %p", &estudiante2.id2);
  printf("\nAddress de b          = %p", &estudiante2.b);
  printf("\nAddress de porcentaje = %p\n", &estudiante2.porcentaje);
  return 0;
}
