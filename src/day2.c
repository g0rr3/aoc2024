#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "utils.h"

int is_safe(int *levels, int length) {
  int inc = 1, dec = 1;

  for (int i = 1; i < length; i++) {
    int diff = abs(levels[i] - levels[i - 1]);
    if (diff < 1 || diff > 3) {
      return 0;
    }
    if (levels[i] < levels[i - 1]) {
      inc = 0;
    }
    if (levels[i] > levels[i - 1]) {
      dec = 0;
    }
  }
  return (inc || dec);
}

int is_safe_with_odd(int *levels, int length) {
  for (int i = 0; i < length; i++) {
    int nl = length - 1;
    int *new_levels = malloc(nl * sizeof(int));
    for (int j = 0, k = 0; j < length; j++) {
      if (j != i) {
        new_levels[k++] = levels[j];
      }
    }

    if (is_safe(new_levels, nl)) {
      free(new_levels);
      return 1;
    }
    free(new_levels);
  }
  return 0;
}

int main(int argc, char *argv[]) {

  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int count1 = 0, count2 = 0;

  Input* input = open_input(argv[1]);
  if (input == NULL){
    perror("Failed to open input");
  }


  while ((read = getline(&line, &len, input->file)) != -1) {
    int *levels = malloc(sizeof(int) * 100);
    int length = 0;

    char *token = strtok(line, " ");
    while (token != NULL) {
      levels[length++] = atoi(token);
      token = strtok(NULL, " ");
    }

    if (is_safe(levels, length)) {
      count1++;
    }
    if (is_safe_with_odd(levels, length)) {
      count2++;
    }

    free(levels);
  }
  printf("Part1: %d\n", count1);
  printf("Part2: %d\n", count2);

  fclose(input->file);
  if (line) {
    free(line);
  }

  return 0;
}
