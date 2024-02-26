/*
*Presentación
*Nomre: Estefan Gabriel Partida Toalá
*Fecha: 24 Febrero del 2024
*Programa: main.cpp
*CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
*INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
*Profesor: Sergio Franco Casillas
*Descripción:
Inserción de valores por parte del usuario (arreglos o vectores)
Pueden ser textuales o numéricos
Borrado y edición de elementos
Vaciado de conjuntos
Operaciones de Unión, Intersección, Diferencia y complemento.
*/

// Declaracion de librerias
#include <iostream>
#include <vector>

// Declaracion de prefijos
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Declaracion de funciones para el manejo de conjuntos
void fill(vector<char> &v, int s);
void print(vector<char> const &v);
void printSet(vector<char> const &v1, vector<char> const &v2);
void edit(vector<char> &v);
void del(vector<char> &v);

// Declaracion de funciones para la operacion con conjuntos
vector<char> inter(vector<char> const &v1, vector<char> const &v2);
vector<char> uni(vector<char> const &v1, vector<char> const &v2);
vector<char> dif(vector<char> const &v1, vector<char> const &v2);
vector<char> comp(vector<char> const &v1, vector<char> const &v2);

int main() {
  // Declaracion y llenado de vectores/conjuntos
  vector<char> A;
  vector<char> B;
  int sizeA;
  int sizeB;
  cout << "Cuantos elementos desea agregar al conjunto A?" << endl;
  cin >> sizeA;
  fill(A, sizeA);
  cout << "Cuantos elementos desea agregar al conjunto B?" << endl;
  cin >> sizeB;
  fill(B, sizeB);

  // Menu de opciones
  int zen = 1;
  while (zen == 1) {
    int opt = 0;
    cout << "Que operacion deseas realizar" << endl;
    cout
        << "0.Listar conjuntos\t1.Editar conjunto\t2.Borrar elemento\t3.Vaciar "
           "Conjunto\n"
        << "4.Interseccion\t5.Union\t6.Diferencia\t7.Complemento" << endl;
    cin >> opt;
    switch (opt) {
    case 0: {
      printSet(A, B);
      break;
    }
    case 1: {
      char v;
      printSet(A, B);
      cout << "Que conjunto desea editar 'A' o 'B'";
      cin >> v;
      if (v == 'A') {
        edit(A);
      } else if (v == 'B') {
        edit(B);
      } else {
        cout << "Conjunto inexistente";
      }
      break;
    }
    case 2: {
      char v;
      printSet(A, B);
      cout << "De que conjunto desea eliminar algun elementos 'A' o 'B'";
      cin >> v;
      if (v == 'A') {
        del(A);
      } else if (v == 'B') {
        del(B);
      } else {
        cout << "Conjunto inexistente";
      }
      break;
    }
    case 3: {
      char v;
      printSet(A, B);
      cout << "Que conjunto desea vaciar 'A', 'B' o ambos '0' ";
      cin >> v;
      if (v == 'A') {
        A.clear();
      } else if (v == 'B') {
        B.clear();
      } else if (v == '0') {
        B.clear();
        A.clear();
      } else {
        cout << "Conjunto inexistente";
      }
      break;
    }
    case 4: {
      print(inter(A, B));
      break;
    }
    case 5: {
      print(uni(A, B));
      break;
    }
    case 6: {
      int opt;
      cout << "1.A-B\t2.B-A" << endl;
      cin >> opt;
      if (opt == 1) {
        print(dif(A, B));
      } else if (opt == 2) {
        print(dif(B, A));
      } else {
        cout << "Opcion invalida" << endl;
      }
      break;
    }
    case 7: {
        char v;
        cout << "De que conjunto deseas hacer el complemento? 'A' - 'B'" << endl;
        cin >> v;
        if(v == 'A'){
          print(comp(A, B));
        } else if (v == 'B'){
          print(comp(B, A));
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
    cout << "Deseas realizar otra operacion: 1.Si 2.No" << endl;
    cin >> zen;
  }
}

void fill(vector<char> &v, int s) {
  for (int i = 0; i < s; i++) {
    char input;
    cin >> input;
    v.push_back(input);
  }
  cout << "\n";
}

void print(vector<char> const &v) {
  cout << "{ ";
  for (auto n : v) {
    cout << n << " ";
  }
  cout << "}\n";
}

void printSet(vector<char> const &v1, vector<char> const &v2) {
  cout << "A = ";
  print(v1);
  cout << "B = ";
  print(v2);
}

void edit(vector<char> &v) {
  print(v);
  int i;
  char elem;
  cout << "Numero de elemento que desea editar?" << endl;
  cin >> i;
  cout << "Ingrese el nuevo elemento" << endl;
  cin >> elem;
  v[--i] = elem;
}

void del(vector<char> &v) {
  print(v);
  int i;
  cout << "Numero de elemento que desea eliminar?" << endl;
  cin >> i;
  v.erase(v.begin() + --i);
}

vector<char> inter(vector<char> const &v1, vector<char> const &v2) {
  vector<char> result;
  for (auto i : v1) {
    for (auto j : v2) {
      if (i == j) {
        result.push_back(i);
      }
    }
  }
  return result;
}
vector<char> uni(vector<char> const &v1, vector<char> const &v2) {
  vector<char> result;
  result.insert(result.begin(), v1.begin(), v1.end());
  result.insert(result.end(), v2.begin(), v2.end());
  return result;
}
vector<char> dif(vector<char> const &v1, vector<char> const &v2) {
  vector<char> result;
  vector<char> intrsc = inter(v1, v2);
  for (auto i : v1) {
    bool flag = true;
    for (auto j : intrsc) {
      if (i == j) {
        flag = false;
      }
    }
    if (flag == true) {
      result.push_back(i);
    }
  }
  return result;
}

vector<char> comp(vector<char> const &v1, vector<char> const &v2) {
  vector<char> result;
  vector<char> un = uni(v1, v2);
  result = dif(un, v1);
  return result;
}
