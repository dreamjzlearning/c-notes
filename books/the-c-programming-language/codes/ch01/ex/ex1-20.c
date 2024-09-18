/*
    Replace tabs in the input with the proper number of blanks
    to space to the next tab stop.
*/

#include <stdio.h>

#define TABINC 8  // tab increment size

int main() {
  int c, nb, pos;

  nb = 0;
  pos = 1;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      nb = TABINC - ((pos - 1) % TABINC);  // calculate the number of blanks
      while (nb > 0) {
        putchar(' ');
        pos++;
        nb--;
      }
    } else if (c == '\n') {
      putchar(c);
      pos = 1;
    } else {
      putchar(c);
      pos++;
    }
  }
}