/*
    Print a histogram of the frequencies of different characters in its input.
*/

#include <ctype.h>
#include <stdio.h>

#define MAXHIST 15
#define MAXCHAR 128

int main() {
  int c;
  int len;          // length of each bar
  int maxvalue;     // maximum value of cc[]
  int cc[MAXCHAR];  // character counters

  for (int i = 0; i < MAXCHAR; i++) {
    cc[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c < MAXCHAR) {
      cc[c]++;
    }
  }

  maxvalue = 0;
  for (int i = 1; i < MAXCHAR; i++) {
    if (cc[i] > maxvalue) {
      maxvalue = cc[i];
    }
  }

  for (int i = 1; i < MAXCHAR; i++) {
    if (isprint(i)) {  // printable character
      printf("%5d - %c - %5d : ", i, i, cc[i]);
    } else {
      printf("%5d - - %5d : ", i, cc[i]);
    }

    // calculate the length of bar
    if (cc[i] > 0) {
      len = cc[i] / maxvalue * MAXHIST;
      if (len <= 0) {
        len = 1;
      }
    } else {
      len = 0;
    }

    while (len > 0) {
      putchar('*');
      len--;
    }
    putchar('\n');
  }

  return 0;
}