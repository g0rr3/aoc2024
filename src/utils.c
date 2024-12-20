#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

Input *open_input(char *path) {
  Input *input = malloc(sizeof(Input));
  input->file = malloc(sizeof(FILE *));
  input->file = fopen(path, "r");
  if (input->file == NULL) {
    free(input);
    return NULL;
  }
  fseek(input->file, 0, SEEK_END);
  input->total_chars = ftell(input->file);
  fseek(input->file, 0, SEEK_SET);
  input->content = malloc(input->total_chars);
  if (input->content) {
    fread(input->content, 1, input->total_chars, input->file);
  }

  rewind(input->file);
  return input;
}
