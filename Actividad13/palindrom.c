#include "utils.c"
int palindrome(char *string) {
  char *ptrStart = string;
  char *ptrEnd = end_of_string(string);
  int flag = 1;
  if (par(string)) {
    for (int i = 0; i < str_len(string) / 2; i++) {
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
