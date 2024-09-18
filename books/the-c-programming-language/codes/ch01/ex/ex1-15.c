/*
    Rewrite the temperature conversion of Section 1.2 to use a function.
*/

#include <stdio.h>

float to_celsius(float fahr);

int main() {
  float fahr;
  int lower, upper, step;

  lower = 0;
  upper = 100;
  step = 10;

  for (fahr = lower; fahr <= upper; fahr += step) {
    float celsius = to_celsius(fahr);
    printf("%.2f\t%.2f\n", fahr, celsius);
  }

  return 0;
}

float to_celsius(float fahr) { return 5.0 / 9.0 * (fahr - 32.0); }