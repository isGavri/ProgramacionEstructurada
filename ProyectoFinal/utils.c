#include <stdio.h>
#include <stdlib.h>
char *get_line() {
  size_t lenmax = 25, len = lenmax;
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
    if(c == '\n'){
      break;
    }
    if ((*line++ = c) == '\n') {
      break;
    }
  }
  *line = '\0';
  return linep;
}

