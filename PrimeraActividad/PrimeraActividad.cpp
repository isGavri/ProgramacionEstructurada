/* Presentación 
Nomre: Estefan Gabriel Partida Toalá
Fecha: 23 de Enero de 2024
Programa: PrimeraActividad.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
Profesor: Sergio Franco Casillas
Descripción: Programa para imprimir mis datos
*/
#include <iostream> //Libreria para inputs y outputs

int main(){
  std::cout.sync_with_stdio(false); //Tengo problemas con los buffers, y la terminal espera printf antes de los cout, esta funcion los desliga y me deja ejecutar 
  std::cout << "Estefan Gabriel Partida Toala" << std::endl;
  std::cout << "18" << std::endl;
  std::cout << "Tepatitlan" << std::endl;
  std::cout << "23 de Enero del 2024" << std::endl;
  std::cout << "Ingenieria en Computacion" << std::endl;
  std::cout << "2do Semestre" << std::endl;
  return 0;
}

