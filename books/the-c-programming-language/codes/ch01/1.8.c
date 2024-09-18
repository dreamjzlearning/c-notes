/*
    Print the longest input line.
*/

#include <stdio.h>

#define MAXLINE 1000  // maximum input line size

// function definitions
int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;                // current line length
  int max;                // maximum length
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0) {
    printf("%d, %s", len, line);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("Longest: %s \n", longest);
  }

  return 0;
}

// getline: read a line into s, return length
int getline(char s[], int lim) {
  int i, c;

  for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';  //  end of the string
  return i;
}

// copy: copy from into to; assume to is big enough
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}
