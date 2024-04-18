#include "menus.c"
#include <stdio.h>
#include <unistd.h>
char *string;
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
    string = remove_nl(get_line());
    menuopts();
    break;
  }
  case 'c': {
    printf("# -- Ingresa la palabra o frase a concatenar\n");
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
    free(string);
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
