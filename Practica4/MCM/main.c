#include <stdio.h>

int mult(int *ns, int n) {
  int cm = 1;
  for (int i = 0; i < n; i++) {
    cm *= *(ns + i);
  }
  return cm;
}
int max(int *ns, int n) {
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max < *(ns + i)) {
      max = *(ns + i);
    }
  }
  return max;
}
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int ns[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &ns[i]);
  }
  for (int i = max(&ns[0], n); i <= mult(&ns[0], n); i += max(&ns[0], n)) {
    int div = 0;
    for (int j = 0; j < n; j++){
      if(i % ns[j] == 0){
        div++;
      }
    }
    if(div == n){
      printf("%d", i);
      return 0;
    }
  }
  return 0;
}
