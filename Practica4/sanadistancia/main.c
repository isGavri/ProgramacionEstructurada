#include <stdio.h>
int main(int argc, char *argv[]) {
  int personas;
  scanf("%d", &personas);
  int reach = 1;
  int prev = personas;
  while (personas > 0) {
    reach += prev;
    prev = prev * (personas - 1);
    personas--;
  }
  printf("%d", reach);
  return 0;
}
