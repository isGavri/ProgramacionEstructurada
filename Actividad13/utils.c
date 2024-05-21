#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void clean_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

char *get_line() {
  size_t lenmax = 256, len = lenmax;
  char *line = malloc(lenmax), *linep = line;
  int c;
  if (line == NULL)
    return NULL;
  for (;;) {
    c = fgetc(stdin);
    if (c == EOF) {
      break;
    }
    if (--len == 0) {
      len = lenmax;
      linep = realloc(linep, lenmax *= 2);
      if (linep == NULL) {
        free(linep);
        return NULL;
      }
      line = linep + (line - linep);
    }
    if ((*line++ = c) == EOF) {
      break;
    }
  }
  *line = '\0';
  return linep;
}

void concatenate(char *string) {
  clean_buffer();
  char *str = get_line();
  printf("# -- Resultado de la concatenación:\n");
  printf("%s %s", string, str);
  free(str);
}
void change_string(char *string) {
  free(string);
  printf("Ingresa la nueva string:\n");
  string = get_line();
}

char *end_of_string(char *string) {
  char *ptr = string;
  while (*ptr != '\0') {
    ptr++;
  }
  return --ptr;
}

int str_len(char *string) {
  int len = 0;
  char *ptr = string;
  while (*ptr != '\0') {
    ptr++;
    len++;
  }
  return len;
}

int par(char *string) { return str_len(string) % 2 == 0 ? 1 : 0; }

char *to_uppercase(char *string) {
  for (int i = 0; i < str_len(string); i++) {
    if (string[i] <= 122 && string[i] >= 97) {
      int change = string[i] - 32;
      string[i] = change;
    }
  }
  return string;
}

char *to_lowercase(char *string) {
  for (int i = 0; i < str_len(string); i++) {
    if (string[i] <= 90 && string[i] >= 65) {
      int change = string[i] + 32;
      string[i] = change;
    }
  }
  return string;
}

char *remove_nl(char *str) {
  char *start = str;
  while (*str != '\n') {
    str++;
  }
  *str = '\0';
  return start;
}
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
