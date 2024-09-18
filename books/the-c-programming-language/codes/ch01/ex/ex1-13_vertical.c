/*
    Print a histogram of the length of words in its input
    Vertical
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

  for (i = MAXHIST; i > 0; i--) {
    for (int j = 1; j < MAXWORD; j++) {
      printf("   ");
      if (wl[j] / maxvalue * MAXHIST >= i) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    putchar('\n');
  }
  for (i = 1; i < MAXWORD; i++) {
    printf("%4d", i);
  }
  putchar('\n');
  for (i = 1; i < MAXWORD; i++) {
    printf("%4d", wl[i]);
  }
  putchar('\n');

  if (ovflow > 0) {
    printf("There are %d words >= %d\n", ovflow, MAXWORD);
  }

  return 0;
}