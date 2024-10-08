/*
    Remove all comments from a C program.
    Don't forget to handle quoted strings and character constants properly.
*/

#include <stdio.h>

void rcomment(int c);
void in_comment();
void echo_quote(int c);

int main() {
  int c, d;

  while ((c = getchar()) != EOF) {
    rcomment(c);
  }

  return 0;
}

// rcomment: read each character, remove the comments
void rcomment(int c) {
  int d;

  if (c == '/') {
    if ((d = getchar()) == '*') {
      in_comment();  // beginning comment
    } else if (d == '/') {
      putchar(c);
      rcomment(d);
    } else {
      putchar(c);  // not a comment
      putchar(d);
    }
  } else if (c == '\'' || c == '"') {
    echo_quote(c);  // quote begin
  } else {
    putchar(c);  // not a comment
  }
}

// in_comment: inside of a valid comment
void in_comment() {
  int c, d;

  c = getchar();
  d = getchar();
  while (c != '*' || d != '/') {  // search for end
    c = d;
    d = getchar();
  }
}

// echo_quote: echo characters within quotes
void echo_quote(int c) {
  int d;

  putchar(c);
  while ((d = getchar()) != c) {  // search for end
    putchar(d);
    if (d == '\\') {
      putchar(getchar());  // ignore escape seq
    }
  }
  putchar(d);
}