#include "palindrom.c"
#include <unistd.h>

void verify_palindrom(char *string) {
  if (string == NULL) {
    printf("\a## -- La frase o palabra es invalida\n");
    return;
  }
  printf("# -- La frase/palabra ingresada fue:\n");
  printf("%s\n", string);
  if (palindrome(string)) {
    printf("# -- La frase/palabra ingresada es un palindromo\n");
  } else {
    printf("# -- La frase/palabra no es un palindromo\n");
  }
}
