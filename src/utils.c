#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

Input *open_input(char *path) {
  Input *input = malloc(sizeof(Input));
  input->file = malloc(sizeof(FILE*));
  input->file = fopen(path, "r");
  if (input->file == NULL) {
    free(input);
    return NULL;
  }
  char c;
  input->lines=0;
  input->total_chars=0;
  while (fscanf(input->file, "%c", &c) != -1) {
    input->total_chars++;
    if (c == '\n') {
      input->lines++;
    }
  }
  printf("%d\n", ftell(input->file));
  rewind(input->file);
  printf("%d\n", ftell(input->file));
  return input;
}
