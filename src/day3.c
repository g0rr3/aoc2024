#include "utils.h"
#include <regex.h>
#include <stdio.h>
#include <string.h>

void day1(char *content) {
  char *pos = content;
  char c;
  int x, y;
  int sum = 0;
  while ((pos = strstr(pos, "mul(")) != NULL) {
    if (sscanf(pos + 4, "%d,%d%c", &x, &y, &c) == 3) {
      if (c == ')') {
        sum += x * y;
      }
    }
    pos++;
  }
  printf("%d\n", sum);
}

void day2(char *content) {
  char *pos = content;
  char c;
  int x, y;
  int sum = 0;
  int dont = 0;
  while (pos) {
    char *pos1 = strstr(pos, "don't()");
    char *pos2 = strstr(pos, "mul(");

    if (dont) {
      pos = strstr(pos, "do()");
      if (pos == NULL) {
        break;
      }
      dont = 0;
      continue;
    }

    if (!pos1 && !pos2) {
      break;
    }

    if (pos1 && (!pos2 || (pos1 < pos2))) {
      dont = 1;
      pos = strstr(pos1 + 1, "do()");
      if (pos == NULL) {
        break;
      } else {
        dont = 0;
      }
    } else {
      if (sscanf(pos2 + 4, "%d,%d%c", &x, &y, &c) == 3) {
        if (c == ')') {
          sum += x * y;
        }
        pos = pos2 + 4;
      } else {
        pos = pos2 + 1;
      }
    }
  }
  printf("%d\n", sum);
}

int main(int argc, char *argv[]) {

  Input *input = open_input(argv[1]);
  if (input == NULL) {
    perror("Failed to open Input");
  }

  day1(input->content);
  day2(input->content);

  return 1;
}
