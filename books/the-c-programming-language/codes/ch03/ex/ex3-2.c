/*
    Write a function escape(s,t) that converts characters like
    newline and tab into visible escape sequences.
*/

#include <stdio.h>

#define STR_SIZE 5

void escape(char s[], char t[]);

int main() {
    char t[STR_SIZE] = "1\t\n2";
    char s[STR_SIZE];

    printf("T: %s, S: %s\n", t, s);
    escape(s, t);
    printf("T: %s, S: %s\n", t, s);

    return 0;
}

void escape(char s[], char t[]) {
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
        }
    }

    s[j] = '\0';
}