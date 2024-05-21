
#include <stdio.h>
float extraextra(int hours, float salary) {
  float realSalary = salary * 2;
  return hours * realSalary;
}
float extra(int hours, float salary) {
  float realSalary = salary * 1.5;
  return hours * realSalary;
}
float base(int hours, float salary) { return hours * salary; }
int main(int argc, char *argv[]) {
  int x;
  float y;
  float sum = 0;
  scanf("%d %f", &x, &y);
  if (x > 50) {
    int hours = x - 50;
    sum += extraextra(hours, y);
    x -= hours;
  }
  if (x > 40) {
    int hours = x - 40;
    sum += extra(hours, y);
    x -= hours;
  }
  sum += base(x, y);
  printf("%.1f", sum);
  return 0;
}
