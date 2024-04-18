#include "utils.c"
#include <stdlib.h>
#include <string.h>
char *remove_spaces(char *str) {
  char *start = str;
  while (*str != '\0') {
    if (*str == 32) {
      char *next = str++;
      *str = *next;
      *next = 32;
    }
    str++;
  }
  return start;
}
int palindrome(char *string) {
  char *str = malloc(str_len(string) + 1);
  strcpy(str, string);
  str = remove_spaces(str);
  char *ptrStart = str;
  char *ptrEnd = end_of_string(str);
  int flag = 1;
  if (par(str)) {
    for (int i = 0; i < str_len(str) / 2; i++) {
      if (*ptrStart == *ptrEnd) {
        flag = 1;
      } else {
        return 0;
      }
      ptrEnd--;
      ptrStart++;
    }
  } else {
    while (ptrStart != ptrEnd) {
      if (*ptrStart == *ptrEnd) {
        flag = 1;
      } else {
        return 0;
      }
      ptrEnd--;
      ptrStart++;
    }
  }
  return flag;
}
