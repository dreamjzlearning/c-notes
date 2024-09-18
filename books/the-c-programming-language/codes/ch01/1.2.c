#include <stdio.h>

int main() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;    // lower limit
  upper = 100;  // upper limit
  step = 20;    // step size

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 / 9 * (fahr - 32);
    printf("%d\t%d\n", fahr, celsius);
    fahr += step;
  }

  return 0;
}