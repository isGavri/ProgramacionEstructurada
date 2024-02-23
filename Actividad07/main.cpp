/* Copyright (C) 1989 GNU
 *Presentación
 *Nomre: Estefan Gabriel Partida Toalá
 *Fecha: 21 de Febrero de 2024
 *Programa: main.cpp
 *CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
 *INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
 *Profesor: Sergio Franco Casillas
 *Descripción: Matrices.
 *   Llenado de matrices diferente de cero
 *   Las matrices pueden ser llenadas por el usuario
 *   Las matrices pueden ser llenadas automaticamente
 *   Se realiza la operacion que indique el usuario
 *   Borrado y edicion de matrices
 *   Vaciado de matrices
 */
#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

void fill(int s, int *m, int *ma);
void fillAuto(int s, int *m, int *ma);
void print(int s, int *m);
void printSet(int s, int *m, int *ma);
void suma(int s, int *m, int *ma);
void resta(int s, int *m, int *ma);
void mult(int s, int *m, int *ma);
void edit(int s, int i, int j, int *m);
void del(int s, int i, int j, int *m);
void clean(int s, int *m);

int main() {
  int size{};
  int fillOpt{};
  int opt{};
  cout << "Indica el tamaño de tus matrices cuadradas, minimo 2 maximo 10"
       << endl;
  cin >> size;
  int m[size][size];
  int ma[size][size];
  cout << "0. Llenado automatico\t1. Llenado manual" << endl;
  cin >> fillOpt;
  if (fillOpt != 0 && fillOpt != 1) {
    cout << "Opcion invalida" << endl;
  } else if (fillOpt == 1) {
    fill(size, (int *)m, (int *)ma);
  } else {
    fillAuto(size, (int *)m, (int *)ma);
  }
  int zen = 1;
  cout << "\nDeseas realizar alguna operacion?\t0.No 1.Si\n";
  cin >> zen;
  while (zen == 1) {
    cout << "Que operacion deseas realizar?" << endl;
    cout << "0.Suma\t1.Resta\t2.Multiplicacion\n3.Edicion\t4.Borrado\t5."
            "Vaciado\t6.Listado" << endl;
    cin >> opt;
    switch (opt) {
    case 0: {
      suma(size, (int *)m, (int *)ma);
      break;
    }
    case 1: {
      resta(size, (int *)m, (int *)ma);
      break;
    }
    case 2: {
      mult(size, (int *)m, (int *)ma);
      break;
    }
    case 3: {
      int i;
      int j;
      int nm;
      printSet(size, (int *)m, (int *)ma);
      cout << "Ingresa el numero matriz que quieres editar\t1.Primera "
              "2.Segunda\n";
      cin >> nm;
      cout << "Ingresa la fila del elemento que deseas editar" << endl;
      cin >> i;
      cout << "Ingresa la columna del elemento que deseas editar" << endl;
      cin >> j;
      if (nm == 1) {
        edit(size, i, j, (int *)m);
      } else if (nm == 2) {
        edit(size, i, j, (int *)ma);
      } else {
        cout << "Opcion invalida" << endl;
      }
      break;
    }
    case 4: {
      int i;
      int j;
      int nm;
      printSet(size, (int *)m, (int *)ma);
      cout << "Ingresa el numero matriz que quieres editar\t1.Primera "
              "2.Segunda\n";
      cin >> nm;
      cout << "Ingresa la fila del elemento que deseas eliminar" << endl;
      cin >> i;
      cout << "Ingresa la columna del elemento que deseas eliminar\n" << endl;
      cin >> j;
      if (nm == 1) {
        del(size, i, j, (int *)m);
      } else if (nm == 2) {
        del(size, i, j, (int *)ma);
      } else {
        cout << "Opcion invalida" << endl;
      }
      break;
    }
    case 5: {
      int nm;
      printSet(size, (int *)m, (int *)ma);
      cout << "Ingresa el numero matriz que quieres vaciar\t1.Primera "
              "2.Segunda\n";
      cin >> nm;
      if (nm == 1) {
        clean(size, (int *)m);
      } else if (nm == 2) {
        clean(size, (int *)ma);
      } else {
        cout << "Opcion invalida" << endl;
      }
      break;
    }
    case 6: {
      printSet(size, (int *)m, (int *)ma);
      break;
    }
    default: {
      cout << "Opcion invalida";
      break;
    }
    }
    cout << "\nDeseas realizar otra operacion?\t0.No 1.Si\n";
    cin >> zen;
  }
}

void fill(int s, int *m, int *ma) {
  int *ptr;
  int *ptra;
  cout << "Llenado de la primera matriz" << endl;
  for (int i = 0; i < s; i++) {
    ptr = m + i * s;
    for (int j = 0; j < s; j++) {
      cin >> ptr[j];
    }
  }
  cout << "Llenado de la segunda matriz" << endl;
  for (int i = 0; i < s; i++) {
    ptra = ma + i * s;
    for (int j = 0; j < s; j++) {
      cin >> ptra[j];
    }
  }
  cout << "Matrices resultantes:" << endl;
  printSet(s, m, ma);
}

void fillAuto(int s, int *m, int *ma) {
  int *ptr;
  int *ptra;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> rand(-100, 100);
  for (int i = 0; i < s; i++) {
    ptr = m + i * s;
    for (int j = 0; j < s; j++) {
      ptr[j] = rand(gen);
    }
  }
  for (int i = 0; i < s; i++) {
    ptra = ma + i * s;
    for (int j = 0; j < s; j++) {
      ptra[j] = rand(gen);
    }
  }
  cout << "Matrices resultantes:" << endl;
  printSet(s, m, ma);
}
void print(int s, int *m) {
  int *ptr;
  int flag{};
  for (int i = 0; i < s; i++) {
    ptr = m + i * s;
    for (int j = 0; j < s; j++) {
      if (flag == i) {
        cout << "\n";
        flag++;
      }
      printf("%d\t", ptr[j]);
    }
  }
  cout << "\n";
}
void printSet(int s, int *m, int *ma) {
  print(s, m);
  print(s, ma);
}
void suma(int s, int *m, int *ma) {
  int rm[s][s];
  int *ptr;
  int *ptra;
  for (int i = 0; i < s; i++) {
    ptr = m + i * s;
    ptra = ma + i * s;
    for (int j = 0; j < s; j++) {
      rm[i][j] = ptr[j] + ptra[j];
    }
  }
  print(s, (int *)rm);
}
void resta(int s, int *m, int *ma) {
  int rm[s][s];
  int *ptr;
  int *ptra;
  for (int i = 0; i < s; i++) {
    ptr = m + i * s;
    ptra = ma + i * s;
    for (int j = 0; j < s; j++) {
      rm[i][j] = ptr[j] - ptra[j];
    }
  }
  print(s, (int *)rm);
}
void mult(int s, int *m, int *ma) {
  int rm[s][s];
  int *ptr;
  int *ptra;
  for (int i = 0; i < s; i++) {
    ptr = m + i * s;
    for (int j = 0; j < s; j++) {
      ptra = ma + j * s;
      rm[i][j] = ptr[j] * ptra[i];
    }
  }
  print(s, (int *)rm);
}
void edit(int s, int i, int j, int *m) {
  int nNum;
  int *ptr;
  ptr = m + (i - 1) * s;
  cout << "Ingresa el numero nuevo" << endl;
  cin >> nNum;
  ptr[j - 1] = nNum;
}
void del(int s, int i, int j, int *m) {
  int *ptr;
  ptr = m + (i - 1) * s;
  ptr[j - 1] = 0;
}
void clean(int s, int *m) {
  int *ptr;
  for (int i = 0; i < s; i++) {
    ptr = m + i * s;
    for (int j = 0; j < s; j++) {
      ptr[j] = 0;
    }
  }
}
