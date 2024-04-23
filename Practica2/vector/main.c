#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  int flag = 1;
  for(int i = 0; i < n; i++){
    if(a[i] <= b[i]){
      flag = 0;
      break;
    }
  }
  printf("%d", flag);
  return 0;
}
