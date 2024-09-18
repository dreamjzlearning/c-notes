/*
    Verify that the expression getchar() != EOF is 0 or 1
*/

#include <stdio.h>

int main() {
  int a, c;

  c = getchar();
  a = c != EOF;

  printf("%c != EOF: %d", c, a);

  return 0;
}