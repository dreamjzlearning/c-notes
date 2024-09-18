/*
    Write a loop equivalent to the for loop above
    without using && or ||
*/

// for (int i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; i++)

// enum loop { NO, YES }
// enum loop ok_loop = YES;

// int i = 0;
// while (ok_loop == YES) {
//     if (i >= lim - 1) {
//         ok_loop = NO;
//     }
//     else if ((c = getchar()) == '\n') {
//         ok_loop = NO;
//     }
//     else if (c == EOF) {
//         ok_loop = NO;
//     }
//     else {
//         s[i] = c;
//         i++
//     }
// }