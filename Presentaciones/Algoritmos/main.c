#include <stdio.h>

void bubble_sort() {
  int espacios, i, j, aux;
  printf("Ingrese los espacios a usar\n");
  scanf("%d", &espacios);
  int ordenar[espacios];
  printf("Ingresa los numeros a ordenar\n");
  for (i = 0; i < espacios; i++) {
    printf("Elemento %d :", i + 1);
    scanf("%d", &ordenar[i]);
  }
  for (i = 0; i < espacios; i++) {
    for (j = 0; j < espacios; j++) {
      if (ordenar[j] > ordenar[j + 1]) {
        aux = ordenar[j];
        ordenar[j] = ordenar[j + 1];
        ordenar[j + 1] = aux;
      }
    }
  }
  printf("\n");
  for (i = 0; i < espacios; i++) {
    printf("Elemento %d:", i + 1);
    printf(" %d\n", ordenar[i]);
  }
}

void merge_sort(){

}
int main(int argc, char *argv[]) { 
  
  return 0; }

