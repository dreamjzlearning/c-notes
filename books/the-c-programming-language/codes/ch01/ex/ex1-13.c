/*
    Print a histogram of the length of words in its input
    Horizontal
*/

#include <stdio.h>

#define MAXHIST 15  // max length of histogram
#define MAXWORD 11  // max length of a word
#define IN 1        // inside a word
#define OUT 0       // outside a word

int main() {
  int c, i, nc, state;
  int len;          // length of each bar
  int maxvalue;     // maximum value of wl[]
  int ovflow;       // number of overflow words
  int wl[MAXWORD];  // word length counters

  state = OUT;
  nc = 0;
  ovflow = 0;
  for (i = 0; i < MAXWORD; i++) {
    wl[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (nc > 0) {
        if (nc < MAXWORD) {
          wl[nc]++;
        } else {
          ovflow++;
        }
        nc = 0;
      }
    } else if (state == OUT) {
      state = IN;
      nc = 1;
    } else {
      nc++;
    }
  }

  maxvalue = 0;
  for (i = 1; i < MAXWORD; i++) {
    if (wl[i] > maxvalue) {
      maxvalue = wl[i];
    }
  }

  for (i = 1; i < MAXWORD; i++) {
    printf("%2d - %2d : ", i, wl[i]);
    if (wl[i] > 0) {
      len = wl[i] * MAXHIST / maxvalue;
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

  if (ovflow > 0) {
    printf("There are %d words >= %d\n", ovflow, MAXWORD);
  }

  return 0;
}