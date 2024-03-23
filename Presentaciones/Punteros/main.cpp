/*
 *Presentación
 *Nombre: Estefan Gabriel Partida Toalá
 *Fecha: 15 de Febrero del 2024
 *Programa: main.cpp
 *CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
 *INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
 *Profesor: Sergio Franco Casillas
 *Descripción: Ejercicios sobre la presentacions de punteros
 */

// Variable que guarda la direccion de la memoria de otra variable.
// Fundamentables para la gestion de memoria dinamica en c++.
// Optimizan el acceso a la memoria.

//************Operaciones con punteros*************
// Declaracion de punteros
//
// int *punt;
//
// Operador de direccion, &, se utiliza para obtener la direccion de memoria de
// una variable.
//
// Desreferenciacion
//
// Se aplica a variables puntero, devuelve el valor del contenido apuntado por
// el operando
//
//
// Diferencia de punteros, distancia que seoara las direcciones.
// La resta de punteros nos da la cantidad de elementos que separa a estos
// punteros.
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void factorial(int *a);

int main() {
  // Ejemplo práctico 1
  int a, *b;
  cin >> a;
  b = &a;
  cout << "El valor de a es: " << a << endl;
  cout << "El valor almacenado en b es: " << b << endl;
  cout << "La posicion de b: " << &b << endl;
  cout << "La valor almacenado en b es: " << *b << endl;

  // Ejemplo practico 2
  int fact;
  cout << "Introduce un numero para calcular su factorial" << endl;
  cin >> fact;
  factorial(&fact);
  cout << fact << endl;

  // Ejemplo practico 3
  int tam;
  int *ptr = new int[tam];
  cout << "Que size deseas que el puntero tenga?" << endl;
  cin >> tam;
  for (int i = 0; i < tam; i++) {
    ptr[i] = i;
    cout << ptr[i] << endl;
  }
  delete [] ptr;
  return 0;
}

void factorial(int *a) {
  int res = 1;
  for (int i = 1; i <= *a; i++) {
    res *= i;
  }
  *a = res;
}
