/*
    Replace strings of blanks by the minimum number of tabs and blanks
    to chive the same spacing.
*/
#include <stdio.h>

#define TABINC 8

int main() {
  int c, nb, nt, pos;

  nb = 0;
  nt = 0;
  for (pos = 1; (c = getchar()) != EOF; pos++) {
    if (c == ' ') {  // white space
      if (pos % TABINC != 0) {
        nb++;
      } else {  // replace blanks with tab
        nb = 0;
        nt++;
      }
    } else {
      for (; nt > 0; nt--) {
        putchar('\t');
      }
      if (c == '\t') {
        nb = 0;
      } else {
        for (; nb > 0; nb--) {
          putchar(' ');
        }
      }

      putchar(c);
      if (c == '\n') {
        pos = 0;
      } else if (c == '\t') {
        pos = pos - 1 + (TABINC - ((pos - 1) % TABINC));
      }
    }
  }
}