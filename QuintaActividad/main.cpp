/* Copyright [2024] gnu
Presentación
Nomre: Estefan Gabriel Partida Toalá
Fecha: 13 de febrero del 2024
Programa: main.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
Profesor: Sergio Franco Casillas
Descripción: Arreglos
*/
 
#include <iostream>

int arr[10];

void listar();
void suma();
void del();
void edit();
void clean();

int main() {
  bool zen = true;
  std::cout << "Tenemos un arreglo de 10 espacios" << std::endl;
  // Ingreso de datos al arreglo
  for (int i = 0; i < 10; i++) {
    bool flag = false;
    std::cout << "Deseas ingresar un elemento en la posicion: " << i
              << std::endl;
    std::cout << "1: Si 0: No" << std::endl;
    std::cin >> flag;
    if (flag) {
      int num;
      std::cout << "Ingresa el numero deseado:" << std::endl;
      std::cin >> num;
      arr[i] = num;
    }
  }
  // Menu de opciones
  while (zen) {
    unsigned int opt;
    std::cout << "1.Listar \v2.Suma \v3.Borrar \v4.Editar \v5.Limpiar"
              << std::endl;
    std::cin >> opt;
    switch (opt) {
    case 1:
      listar();
      break;
    case 2:
      suma();
      break;
    case 3:
      del();
      break;
    case 4:
      edit();
      break;
    case 5:
      clean();
      break;
    default:
      std::cout << "Opcion invalida" << std::endl;
    }
    std::cout << "Quieres realizar otra operacion?\t1.Si\t0.No " << std::endl;
    std::cin >> zen;
  }
  return 0;
}
// Lista los valores con su posicion
void listar() {
  std::cout << "Lista de Valores:" << std::endl;
  for (int i = 0; i < 10; i++) {
    if (arr[i] != 0) {
      std::cout << i << ". " << arr[i] << std::endl;
    }
  }
}
// Suma de los elementos
void suma() {
  int sum = 0;
  std::cout << "Suma de los elementos del arreglo" << std::endl;
  for (int i = 0; i < 10; i++) {
    if (arr[i] != 0) {
      sum += arr[i];
    }
  }
  std::cout << sum << std::endl;
}
// Borra elemento seleccionado
void del() {
  int elem;
  std::cout << "Que elemento desea eliminar?" << std::endl;
  listar();
  std::cin >> elem;
  arr[elem] = 0;
}
// Edita elemento seleccionado
void edit() {
  int elem;
  int newElem;
  std::cout << "Que elemento desea editar?" << std::endl;
  listar();
  std::cin >> elem;
  std::cout << "Ingresa el nuevo valor" << std::endl;
  std::cin >> newElem;
  arr[elem] = newElem;
}
// Limpia los valores del arreglo
void clean() {
  for (int i = 0; i < 10; i++) {
    arr[i] = 0;
    std::cout << arr[i] << std::endl;
  }
}



