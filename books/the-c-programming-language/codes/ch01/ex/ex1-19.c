/*
    Reverse the character string "s".
*/

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int lim);
void reverse(char s[]);

int main() {
  char line[MAXLINE];

  while (getline(line, MAXLINE) > 0) {
    printf("Origin: %s", line);
    reverse(line);
    printf("Reversed: %s", line);
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

void reverse(char s[]) {
  // get the length of s without blank
  int i;
  for (i = 0; s[i] != '\0'; i++) {
  }

  i--;
  if (s[i] == '\n') {
    i--;
  }

  char temp;
  for (int j = 0; i >= 0 && j < i; j++, i--) {
    // swap characters
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
  }
}