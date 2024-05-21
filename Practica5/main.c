#include <stdio.h>
int main(int argc, char *argv[]) {
  int y;
  scanf("%d", &y);
  if (y % 4 == 0) {
    if (y >= 100 && y % 100 == 0) {
      if (y >= 100 && y % 400 == 0) {
        printf("BISIESTO");
      } else {
        printf("NO BISIESTO");
      }
    } else {
      printf("BISIESTO");
    }
  } else {
    printf("NO BISIESTO");
  }
  return 0;
}
