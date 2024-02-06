/* Presentación 
Nomre: Estefan Gabriel Partida Toalá
Fecha: 6 de Febrero del 2024
Programa: CuartaActividad.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
Profesor: Sergio Franco Casillas
Descripción: Elaborar la serie Fibonacci utilizando los 3 ciclos básicos (for, while y do-while)

Solicitar al usuario un valor, y la serie debe llegar a un valor igual o menor al indicado por el usuario

El usuario va a elegir con qué ciclo debe trabajar
El programa debe salir cuando el usuario lo indique
*/
// Biblioteca de funciones
#include <iostream>

void fib_for(int num);
void fib_while(int num);
void fib_do_while(int num);

int main(){

  std::cout.sync_with_stdio(false); 

  int flag;
  int num;

  std::cout << "Ingresa un valor maximo para la serie fibonacci" << std::endl;
  std::cin >> num;

  std::cout << "Que ciclo deseas utilizar? \n1: For \n2: While \n3: Do While" << std::endl;
  std::cin >> flag;
  std::cout << std::endl;

  switch(flag){
    case 1:
      fib_for(num);
      break;
    case 2:
      fib_while(num);
      break;
    case 3:
      fib_do_while(num);
      break;
    default: 
      std::cout << "Opcion invalida" << std::endl;
      break;
  }
  return 0;
}


void fib_for(int num){
  int prevNum = 1;
  int prevPrevNum = 0;
  for(int i = 0; i <= num; i = prevNum + prevPrevNum){
    std::cout << i << std::endl;
    prevPrevNum = prevNum;
    prevNum = i;
  }
};
void fib_while(int num){
  int prevNum = 1;
  int prevPrevNum = 0;
  int i = 0;
  while(i <= num){
    std::cout << i << std::endl;
    prevPrevNum = prevNum;
    prevNum = i;
    i = prevNum + prevPrevNum;
  }
};
void fib_do_while(int num){
  int prevNum = 1;
  int prevPrevNum = 0;
  int i = 0;
  do{
    std::cout << i << std::endl;
    prevPrevNum = prevNum;
    prevNum = i;
    i = prevNum + prevPrevNum;
  } while(i <= num);
};

