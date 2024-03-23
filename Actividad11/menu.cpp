// Libraries
#include "handling.cpp"
#include <iostream>

// Namespaces for specific function
using std::cin;
using std::cout;
using std::endl;

// Top level declaration
void insertionMenu(int *a, int s);

// Top level declaration and implementation
void menu() {
  cout << "De que tamano deseas tu arreglo numerico(max 50)" << endl;
  int size{};
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++){
    arr[i] = 0;
  }
  insertionMenu((int *)arr, size);
}

// Functions Implementations
void insertionMenu(int *a, int s) {
  int elem{};
  int opt{};
  for (int i = 0; i < s; i++) {
    cout << "Deseas insertar nuevo valor" << "\n1.Si 0.No" << endl;
    cin >> opt;
    if (opt == 1) {
      cin >> elem;
      while (!valid(a, s, elem)) {
        cout << "Numero repetido, ingrese otro numero" << endl;
        cin >> elem;
      }
      insert(a, elem, s, i);
    }
  }
  print(a, s);
}
