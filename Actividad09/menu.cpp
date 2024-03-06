#include "setHandling.cpp"
#include "setOperation.cpp"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void mainMenu();
void handlingMenu(vector<char> &v1, vector<char> &v2);
void clearMenu(vector<char> &v1, vector<char> &v2);
void fillingMenu(vector<char> &v1, vector<char> &v2);
void listMenu(vector<char> &v1, vector<char> &v2);
void editMenu(vector<char> &v1, vector<char> &v2);
void operationMenu(vector<char> &v1, vector<char> &v2);

void mainMenu() {
  vector<char> A;
  vector<char> B;
  cout << "Tenemos dos conjuntos A y B" << endl;
  char fill;
  cout << "Quieres iniciar el proceso de llenado? (Y)es (N)o" << endl;
  cin >> fill;
  if (fill == 'Y' || fill == 'y') {
    fillingMenu(A, B);
  } else {
    cout << "Warning: Saltando llenado inicial" << endl;
  }
  handlingMenu(A, B);
}
void handlingMenu(vector<char> &v1, vector<char> &v2) {
  int opt;
  cout << "Que deseas hacer con tus conjuntos?\n"
          "1.Vaciar\t2.Rellenar\t3.Listar\t4.Editar\t5.Operaciones\t6.Salir"
       << endl;
  cin >> opt;
  switch (opt) {
  case 1: {
    clearMenu(v1, v2);
    break;
  }
  case 2: {
    fillingMenu(v1, v2);
    break;
  }
  case 3: {
    listMenu(v1, v2);
    break;
  }
  case 4: {
    editMenu(v1, v2);
    break;
  }
  case 5: {
    operationMenu(v1, v2);
    break;
  }
  case 6: {
    cout << "Saliendo del programa..." << endl;
    exit(1);
    break;
  }
  default: {
    cout << "Opcion inexsistente" << endl;
  }
  }
}
void clearMenu(vector<char> &v1, vector<char> &v2) {
  int opt;
  cout << "Deseas limpiar ambos(2) conjuntos o solo uno(1)?" << endl;
  cin >> opt;
  if (opt == 1) {
    char set;
    cout << "Que conjunto deseas limpiar? (A) (B)" << endl;
    cin >> set;
    if (set == 'A') {
      clear(v1);
    } else if (set == 'B') {
      clear(v2);
    } else {
      cout << "Conjuto inexistente" << endl;
    }
  } else if (opt == 2) {
    clearSet(v1, v2);
  } else {
    cout << "Opcion invalida" << endl;
  }
  handlingMenu(v1, v2);
}
void fillingMenu(vector<char> &v1, vector<char> &v2) {
  v1.clear();
  v2.clear();
  int sizeA;
  int sizeB;
  cout << "Iniciaremos llenado de conjuntos" << endl;
  cout << "Cuantos elementos desea agregar al conjunto A?" << endl;
  cin >> sizeA;
  fill(v1, sizeA);
  cout << "Cuantos elementos desea agregar al conjunto B?" << endl;
  cin >> sizeB;
  fill(v2, sizeB);
  handlingMenu(v1, v2);
}
void listMenu(vector<char> &v1, vector<char> &v2) {
  int opt;
  cout << "Deseas listar (2)ambos conjuntos o (1)solo uno?" << endl;
  cin >> opt;
  if (opt == 1) {
    char setOpt;
    cout << "Que conjunto deseas imprimir? (A) (B)" << endl;
    cin >> setOpt;
    if (setOpt == 'A') {
      print(v1);
    } else if (setOpt == 'B') {
      print(v2);
    } else {
      cout << "Conjunto inexsistente" << endl;
    }
  } else if (opt == 2) {
    printSet(v1, v2);
  } else {
    cout << "Opcion invalida" << endl;
  }

  handlingMenu(v1, v2);
}
void editMenu(vector<char> &v1, vector<char> &v2) {
  char set;
  cout << "Que conjunto deseas editar? (A) (B)" << endl;
  ;
  printSet(v1, v2);
  cin >> set;
  if (set == 'A') {
    int opt;
    cout << "Deseas (1)editar un elemento o (2)eliminar un elemento?" << endl;
    cin >> opt;
    if (opt == 1) {
      edit(v1);
    } else if (opt == 2) {
      del(v1);
    } else {
      cout << "Opcion inexsistente" << endl;
    }
  } else if (set == 'B') {
    int opt;
    cout << "Deseas (1)editar un elemento o (2)eliminar un elemento?" << endl;
    cin >> opt;
    if (opt == 1) {
      edit(v2);
    } else if (opt == 2) {
      del(v2);
    } else {
      cout << "Opcion inexsistente" << endl;
    }
  } else {
    cout << "Conjunto inexsistente" << endl;
  }
  handlingMenu(v1, v2);
}
void operationMenu(vector<char> &v1, vector<char> &v2) {
  int opt;
  cout << "Que operacion deseas realizar\n"
       << "4.Interseccion\t5.Union\t6.Diferencia\t7.Complemento" << endl;
  cin >> opt;
  switch (opt) {
  case 4: {
    print(inter(v1, v2));
    break;
  }
  case 5: {
    print(uni(v1, v2));
    break;
  }
  case 6: {
    int opt;
    cout << "1.A-B\t2.B-A" << endl;
    cin >> opt;
    if (opt == 1) {
      print(dif(v1, v2));
    } else if (opt == 2) {
      print(dif(v2, v1));
    } else {
      cout << "Opcion invalida" << endl;
    }
    break;
  }
  case 7: {
    char v;
    cout << "De que conjunto deseas hacer el complemento? 'A' - 'B'" << endl;
    cin >> v;
    if (v == 'A') {
      print(comp(v1, v2));
    } else if (v == 'B') {
      print(comp(v2, v1));
    } else {
      cout << "Opcion invalida" << endl;
    }
    break;
  }
  default: {
    cout << "Opcion invalida" << endl;
    break;
  }
  }
  handlingMenu(v1, v2);
}
