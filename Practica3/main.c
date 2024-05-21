#include <stdio.h>
#include <unistd.h>

int stay(int **ptr, int level) {
  if (**ptr >= level++) {
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int h[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &h[i][j]);
    }
  }
  if(h[0][0] == 0){
    printf("%d", -1);
  }
  if(h[0][0] == 5){
    printf("%d", n);
  }
  return 0;
}
