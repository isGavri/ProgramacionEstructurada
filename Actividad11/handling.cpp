#include <iostream>
using std::cout;
// Top level declaration
bool valid(int *m, int s, int n);
void insert(int *m, int n, int s, int indx);
int position_insert(int *m, int n, int indx);
void print(int *m, int s);

// Function implementation
bool valid(int *m, int s, int n) {
  bool flag = true;
  for (int i = 0; i < s; i++) {
    if (n == m[i]) {
      flag = false;
      break;
    }
  }
  return flag;
}

int position_insert(int *m, int n, int indx) {
  int position = 0;
  for (int i = 0; i < indx; i++) {
    if (n > m[i]) {
      position++;
    }
  }
  return position;
}

void insert(int *m, int n, int s, int indx) {
  int i = s;
  int index = position_insert(m, n, indx);
  while (i > index) {
    if (m[i] == 0) {
      m[i] = m[i - 1];
      m[i - 1] = 0;
    }
    i--;
  }
  m[index] = n;
}
void print(int *m, int s) {
  for (int i = 0; i < s; i++) {
    cout << "Elemento " << i << ": " << m[i] << std::endl;
  }
}
