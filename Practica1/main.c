#include <stdio.h>

int main(int argc, char *argv[]) {
  int n, k;
  scanf("%d", &n);
  int enes[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &enes[i]);
  }
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    if (enes[i] % k == 0) {
      printf("%d ", enes[i]);
    } else {
      printf("X ");
    }
  }
  return 0;
}
