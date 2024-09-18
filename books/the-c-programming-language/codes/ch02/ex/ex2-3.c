/*
    Write the function htio(s) to convert a string of hexadecimal digits
    (including 0x, 0X) into ints equivalent value.
*/
#include <stdio.h>

#define YES 1
#define NO 0

int htoi(char s[]);

int main() {
    int x = 0x200;
    char xs[] = "0X200";
    printf("string: %s\n", xs);
    int n = htoi(xs);
    printf("htoi: %d, %x\n", n, n);
    printf("val: %d, %x\n", x, x);

    return 0;
}

int htoi(char s[]) {
    int hexdigit, i, inhex, n;

    i = 0;
    if (s[i] == '0') { // skip 0x, 0X
        i++;
        if (s[i] == 'x' || s[i] == 'X') {
            i++;
        }
    }

    n = 0;
    inhex = YES;
    for (; inhex == YES; i++) {
        char c = s[i];
        if (s[i] >= '0' && s[i] <= '9') {
            hexdigit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            hexdigit = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            hexdigit = s[i] - 'A' + 10;
        }
        else {
            inhex = NO;
        }

        if (inhex == YES) {
            n = 16 * n + hexdigit;
        }
    }

    return n;
}