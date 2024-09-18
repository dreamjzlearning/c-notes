/*
    Revise the main routine of the longest-line program
    so it will correctly print the print length of text.
*/

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int max, len;
  char line[MAXLINE], longest[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    printf("%d, %s", len, line);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("longest: %s", longest);
  }

  return 0;
}

int getline(char line[], int lim) {
  char c;
  int i, j;
  j = 0;

  /*
    i < lim-1 is not a condition for termination
    because getline() returns the length of arbitrary long input lines
    and saves as much as possible.
  */
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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}