/*
    Check a C  program for rudimentary syntax error
    like unbalanced parentheses, brackets, and braces.
*/

#include <stdio.h>

int brace, bracket, parentheses;

void in_quote(int c);
void in_comment();
void search(int c);

int main() {
  int c;
  extern int brace, bracket, parentheses;

  while ((c = getchar()) != EOF) {
    if (c == '/') {
      if ((c = getchar()) == '*') {
        in_comment();  // inside comment
      } else {
        search(c);
      }
    } else if (c == '\'' || c == '"') {
      in_quote(c);  // inside quote
    } else {
      search(c);
    }
  }

  if (brace != 0) {
    printf("Unbalanced braces\n");
    if (brace < 0) {
      brace = 0;
    }
  }
  if (bracket != 0) {
    printf("Unbalanced brackets\n");
    if (bracket < 0) {
      bracket = 0;
    }
  }
  if (parentheses != 0) {
    printf("Unbalanced parentheses\n");
    if (parentheses < 0) {
      parentheses = 0;
    }
  }
}

// search: search for rudimentary syntax errors
void search(int c) {
  extern int brace, bracket, parentheses;

  switch (c) {
    case '{':
      brace++;
      break;
    case '}':
      brace--;
      break;
    case '[':
      bracket++;
      break;
    case ']':
      bracket--;
      break;
    case '(':
      parentheses++;
      break;
    case ')':
      parentheses--;
      break;
  }
}

//  in_comment: inside of a valid comment
void in_comment() {
  int c, d;

  c = getchar();
  d = getchar();
  while (c != '*' || d != '/') {  // search for end of comment
    c = d;
    d = getchar();
  }
}

void in_quote(int c) {
  int d;

  while ((d = getchar()) != c) {  // search for end of quote
    if (d == '\\') {              // escape sequence
      getchar();
    }
  }
}