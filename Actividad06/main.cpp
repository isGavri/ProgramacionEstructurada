/* Copyright (C) 1989 GNU
 *Presentación
 *Nombre: Estefan Gabriel Partida Toalá
 *Fecha: 20 de febrero del 2024
 *Programa: main.cpp
 *CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
 *INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
 *Profesor: Sergio Franco Casillas
 *Descripción: Actividad 5 usando vectores
 */

//Declaracion de bibliotecas
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

//Declaracion de funciones
void listar(std::vector<int> v);

//Implementacion de funciones
int main() {
  std::vector<int> arr; //Declaracion de arreglo
  //Llenado de arreglo
  std::cout << "Iniciaremos proceso de llenado del vector\n" << std::endl;
  int zen = 1;
  while (zen == 1) {
    int num;
    std::cout << "Deseas ingresar un nuevo valor\t1.Si 0.No" << std::endl;
    std::cin >> zen;
    if (zen == 1) {
      std::cout << "Ingrese el valor deseado" << std::endl;
      std::cin >> num;
      arr.push_back(num);
    }
  }
  //Operaciones a realizar con el vector
  int zen1 = 1;
  while (zen1 == 1) {
    int opt;
    std::cout << "Deseas realizar alguna operacion. 1.Si 0.No" << std::endl;
    std::cin >> zen1;
    if (zen1 == 1) {
      std::cout << "1.Suma 2.Borrar 3.Editar 4.Vaciar 5.Listar" << std::endl;
      std::cin >> opt;
      switch (opt) {
      //Sumar los elementos del vector
      case 1: {
        int suma{};
        std::for_each(arr.begin(), arr.end(), [&suma](int n) { suma += n; });
        std::cout << suma << std::endl;
        break;
      }
      case 2: {
      //Borrar algun elemento del vector
        listar(arr);
        int index{};
        std::cout << "Numero de elemento que deseas eliminar" << std::endl;
        std::cin >> index;
        index--;
        arr.erase(arr.begin() + index);
        break;
      }
      case 3: {
      //Editar algun elemento del vector
        listar(arr);
        int index{};
        int neonum{};
        std::cout << "Numero de elemento que deseas modificar" << std::endl;
        std::cin >> index;
        index--;
        std::cout << "Nuevo numero" << std::endl;
        std::cin >> neonum;
        arr[index] = neonum;
        break;
      }
      case 4: {
      //Vaciar el vector y liberar memoria
        arr.clear();
        arr.shrink_to_fit();
        break;
        }
      case 5: {
      //Listar el vector
        listar(arr);
        break;
      }
      }
    }
  }
}

void listar(std::vector<int> v) {
  std::for_each(v.begin(), v.end(), [](int n) { std::cout << n << std::endl; });
}
