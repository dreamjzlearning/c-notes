/*
    Print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE 80

int getline(char line[], int lim);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    if (len > LONGLINE) {
      printf("%s", line);
    }
  }
  return 0;
}

int getline(char line[], int lim) {
  char c;
  int i, j;

  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < lim - 2) {
      line[j] = c;
      j++;
    }
  }

  if (c == '\n') {
    line[j] = c;
    i++;
    j++;
  }

  line[j] = '\0';
  return i;
}