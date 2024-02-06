/* Presentación 
Nomre: Estefan Gabriel Partida Toalá
Fecha: 6 de Febrero de 2024
Programa: RequisitosTareas.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
Profesor: Sergio Franco Casillas
Descripción: Si el número es mayor a 0 y menor a 500, subir de 5 en 5, 100 veces.
Si el número es mayor a 500 y menor a 1000, subir el número de 10 en 10, 50 veces
Si el número es mayor a 1000, “No se puede calcular el valor”.
Debe hacer un ciclo en donde pregunte si desea terminar el programa.
Contar con las veces que realizó una operación.
En todo momento mostrar valores
Elaborar diagrama de flujo.
*/
#include <iostream>
int main(){
  std::cout.sync_with_stdio(false);
  unsigned int n = 0;
  int flag = 1;
  int a = 0;
  while (flag == 1){
    std::cout << "Ingrese un numero" << std::endl;
    std::cin >> n;
    if(n > 1000 || n == 0){
      std::cout << "No se puede calcular el valor" << std::endl;
    } else if (n > 500){
      for(int i = 0; i < 50; i++){
        n += 10;
        std::cout << n << std::endl;
      }
      a++;
    } else {
      for(int i = 0; i < 100; i++){
        n += 5;
        std::cout << n << std::endl;
        
      }
      a++;
    } 
    std::cout << "Quiere realizar otra operacion? Si: 1 No: cualquier otro input" << std::endl;
    std::cin >> flag;    
  }
  std::cout << "Se han realizado "<< a << " operaciones" << std::endl;
  return 0;
}


