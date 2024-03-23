/*
 *Presentación
 *Nomre: Estefan Gabriel Partida Toalá
 *Fecha: 22 de Marzo 2024
 *Programa: main.cpp
 *CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
 *INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
 *Profesor: Sergio Franco Casillas
 *Descripción: Implementación del juego de las torres de Hanoi utilizando la
 *recusión
 */

#include "menu.cpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  cout << "Bienvenido al juego de Hanoi!" << endl;
  int opt;
  cout << "Quieres jugar?\n1.Si 2.No" << endl;
  cin >> opt;
  if (opt == 1) {
    start_game();
  } else {
    cout << "☹";
  }
  return 0;
}
