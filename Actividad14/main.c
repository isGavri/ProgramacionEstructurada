// Tener un banco de al menos 20 palabras
// La computadora va a elegir una al azar y el usuario debe adivinar el
// resultado Si el usuario elige una vocal, se debe penalizar con 1 intento, es
// decir, tendrá una oportunidad menos Contar el número de intentos por jugador
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char banco[20][10] = {
    {"diferencia"}, {"presidente"}, {"transporte"}, {"desarrollo"},
    {"resultados"}, {"entrevista"}, {"fotografia"}, {"encuentran"},
    {"estructura"}, {"representa"}, {"conciencia"}, {"diferentes"},
    {"relaciones"}, {"importante"}, {"encontraba"}, {"influencia"},
    {"cualquiera"}, {"siguientes"}, {"referencia"}, {"nacionales"}};
char const *word;
char guess[10] = {
    '_', '_', '_', '_', '_', '_', '_', '_', '_', '_',
};
int vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
         (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
  ;
}
int equals() {
  for (int i = 0; i < 10; i++) {
    if (word[i] != guess[i]) {
      return 0;
    }
  }
  return 1;
}
void print_guess() {
  for (int i = 0; i < 10; i++) {
    printf("%c", guess[i]);
  }
  printf(" -");
}
int next_try(int a) {
  printf("%d\n", a);
  print_guess();
  int error = 0;
  printf("Ingresa un caracter: ");
  char c = fgetc(stdin);
  fgetc(stdin);
  for (int i = 0; i < 10; i++) {
    if (word[i] == c) {
      if (vowel(c)) {
        error = 0;
      } else {
        error = 1;
      }
      guess[i] = word[i];
    }
  }
  return error;
}
int main(int argc, char *argv[]) {
  //Copiado de stackoverflow
  srand(time(NULL));
  int nRandonNumber = rand() % (10) + 1;

  word = banco[nRandonNumber];

  printf("\n### ----- Bienvenido al juego del ahorcado!   ----- ###\n\n");
  printf(
      "# Debes adivinar la palabra ingresando letras que creas estan "
      "contenidas en la palabra.\n# Tienes 10 vidas.\n# Cada error te "
      "resta una "
      "vida.\n# Cada vocal ingreasada tambien resta una vida\n# Si ingresas un "
      "numero o caracter especial se te tomara como error, por bobo  \n\n");
  printf("Listo para empezar? (S)i (S)i\n");
  char opt = fgetc(stdin);
  fgetc(stdin);
  if (opt == 's') {
    printf("Es en mayusculas, bobo\n\n");
  } else if (opt != 'S') {
    printf(">:(\n");
    exit(0);
  }
  printf("\n### ----- Buena suerte! ----- ###\n");
  sleep(2);
  int move_count = 0;
  while (move_count < 10 && !equals()) {
    system("clear");
    if (!(next_try(move_count))) {
      move_count++;
    }
  }
  if (move_count >= 10) {
    system("clear");
    printf("Has excedido la cantidad de intentos :(\nLoser\n");
  } else {
    system("clear");
    print_guess();
    printf(" %d\n", move_count);
    printf("\nFelicidades  ! Ganaste  \n");
  }
  return 0;
}
