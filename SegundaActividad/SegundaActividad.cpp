/* Presentación 
Nomre: Estefan Gabriel Partida Toalá
Fecha: 2 de Febrero de 2024
Programa: SegundaActividad.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACIÓN / 2DO SEMESTRE
Profesor: Sergio Franco Casillas
Descripción: Utilizacion de cadenas de control y caracteres de escape
*/
#include <stdio.h> //Libreria estandar de input y output de c
#define p printf //Cambia las incidencias de p con printf
int main(){

  int numeroEntero = 17;
  float numeroFlotante = 1.2340;
  char caracter = 'c';
  char cadena[5] = "Hola";

  p("%d \t", numeroEntero); //Utiliza %d para imprimir entero decimal y \t para tabulacion
  p("%o \t", numeroEntero); //Utiliza %d para convertir a octal y \t para tabulacion
  p("%x \v", numeroEntero);  //Utiliza %x para convertir a hexadecimal y \v para tabulacion vertical
  p("%.4f \v", numeroFlotante); //Utiliza %f para flotante y \v para tabulacion vertical
  p("\'%c\' \n", caracter); //Utiliza %c para imprimir caracter, \' para single quote, \n para newline
  p("\"%s\?\"", cadena); //Utiliza %s para imprimir cadena, \? para signo de interrogacion y \" para double quotes


  return 0;
}
