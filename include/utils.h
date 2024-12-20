#include <stdio.h>

#ifndef UTILS_H
#define UTILS_H

typedef struct {
  FILE* file;
  int lines;
  int total_chars;
  char* content;
} Input;

Input* open_input(char* path);

#endif
