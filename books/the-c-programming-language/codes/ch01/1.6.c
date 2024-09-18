/*
    Count digits, white space, others
*/

#include <stdio.h>

int main() {
  int c, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (int i = 0; i < 10; i++) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ndigit[c - '0']++;
    } else if (c == ' ' || c == '\n' || c == '\t') {
      nwhite++;
    } else {
      nother++;
    }
  }

  printf("digits:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", i);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    printf("%d ", ndigit[i]);
  }
  printf("\n");

  printf("white space = %d, other = %d\n", nwhite, nother);

  return 0;
}