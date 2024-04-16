#include "menus.c"
#include <stdio.h>
#include <unistd.h>
char *string;
// 65 a 90 abecedario en mayusculas
// 97 a 122 abecedatio en minusculas
// 32 espacio
int vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
         (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
int vowels(char *str) {
  int count = 0;
  for (int i = 0; i < str_len(str); i++) {
    if (vowel(str[i])) {
      count++;
    }
  }
  return count;
}

int spaces(char *str) {
  int count = 0;
  for (int i = 0; i < str_len(str); i++) {
    if (str[i] == 32) {
      count++;
    }
  }
  return count;
}

int non_vowels_nor_spaces(char *str) {
  int count = 0;
  for (int i = 0; i < str_len(str); i++) {
    if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
      if (!(vowel(str[i]))) {
        count++;
      }
    }
  }
  return count;
}

void menuopts() {
  printf("\n# ---- Menu de opciones ---- #\n");
  printf("- Reingresar string (r)\n");
  printf("- Concatenar nueva string(c)\n");
  printf("- Contar numero de vocales, consonantes y espacios(C)\n");
  printf("- Determinar si es un palindromo(p)\n");
  printf("- Convertir a minusculas(m)\n");
  printf("- Convertir a mayusculas(M)\n");
  printf("- Salir del programa(S)\n");
  char opt = fgetc(stdin);
  switch (opt) {
  case 'r': {
    clean_buffer();
    printf("# -- Ingresa la nueva palabra o frase\n");
    string = get_line();
    menuopts();
    break;
  }
  case 'c': {
    concatenate(string);
    menuopts();
    break;
  }
  case 'C': {
    printf("# -- Tu palabra/frase cuenta con %d vocales %d consonantes y %d "
           "espacios\n",
           vowels(string), non_vowels_nor_spaces(string), spaces(string));
    menuopts();
    break;
  }
  case 'p': {
    clean_buffer();
    verify_palindrom(string);
    menuopts();
    break;
  }
  case 'm': {
    printf("Palabra o frase a minusculas:\n");
    printf("%s", to_lowercase(string));
    menuopts();
    break;
  }
  case 'M': {
    printf("Palabra o frase a mayusculas:\n");
    printf("%s", to_uppercase(string));
    menuopts();
    break;
  }
  case 'S': {
    printf("Gracias por jugar  \n");
    break;
  }
  }
}

int main(int argc, char *argv[]) {
  printf("Ingresa una frase o palabra (Maximo 256 caracteres) sin caracteres "
         "especiales ni digitos\n");
  string = remove_nl(get_line());
  menuopts();
  return 0;
}
