/*
    Determine the ranges of char, short, int, and long variables,
    both signed and unsigned.
*/

#include <limits.h>
#include <stdio.h>

int main() {
    // signed
    // char
    printf("size of char: %d\n", sizeof(char));
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    // short
    printf("size of short: %d\n", sizeof(short));
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    // int
    printf("size of int: %d\n", sizeof(int));
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    // long
    printf("size of long: %d\n", sizeof(long));
    printf("signed long min = %d\n", LONG_MIN);
    printf("signed long max = %d\n", LONG_MAX);

    // unsigned
    // char
    printf("size of unsigned char: %d\n", sizeof(unsigned char));
    printf("signed char max = %d\n", UCHAR_MAX);
    // short
    printf("size of unsigned short: %d\n", sizeof(unsigned short));
    printf("signed char max = %d\n", USHRT_MAX);
    // int
    printf("size of unsigned int: %d\n", sizeof(unsigned int));
    printf("signed char max = %d\n", UINT_MAX);
    // long
    printf("size of unsigned long: %d\n", sizeof(unsigned long));
    printf("signed char max = %d\n", ULONG_MAX);

    return 0;
}