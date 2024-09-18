/*
    Remove trailing blanks and tabs from each line of input.
    Delete entirely blank lines.
*/

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int lim);
int remove(char s[]);

int main() {
  char line[MAXLINE];

  while (getline(line, MAXLINE) > 0) {
    if (remove(line) > 0) {
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

int remove(char s[]) {
  int i;

  i = 0;
  while (s[i] != '\n') {
    i++;
  }

  i--;
  while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
    i--;
  }

  if (i >= 0) {
    i++;
    s[i] = '\n';
    i++;
    s[i] = '\0';
  }

  // if the line is blank, returns -1
  return i;
}