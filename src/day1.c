#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(int argc, char *argv[]) {

  Input *input = open_input(argv[1]);
  if (input == NULL) {
    perror("Failed to open input");
    ;
  }

  int list1[input->lines];
  int list2[input->lines];
  char ch;
  for (int i = 0; i < input->lines; i++) {
    fscanf(input->file, "%d %d", &list1[i], &list2[i]);
  }
  qsort(list1, sizeof(list1) / sizeof(list1[0]), sizeof(list1[0]), comp);
  qsort(list2, sizeof(list2) / sizeof(list2[0]), sizeof(list2[0]), comp);

  int sum = 0;
  for (int i = 0; i < input->lines; i++) {
    sum += abs(list1[i] - list2[i]);
    printf("%d %d %d\n", i, list1[i], list2[i]);
  }
  printf("Part 1: %d\n", sum);

  sum = 0;
  for (int i = 0; i < input->lines; i++) {
    int sim = 0;
    for (int c = 0; c < input->lines; c++) {
      if (list1[i] == list2[c]) {
        sim++;
      }
    }
    sum += list1[i] * sim;
  }
  printf("Part 2: %d\n", sum);
}
