#include <stdio.h>

/*
exercise 1-4
write a program to print the corresponding celsius to fahrenheit table
*/

void main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; // lower limit of the temp table
  upper = 300; // upper limit
  step = 20; // step size

  fahr = lower;

  printf("Temperature Conversion program\n");
  printf("     C    F\n");

  while (fahr <= upper)
  {
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("%6.1f  %3.0f\n", celsius, fahr);
    fahr = fahr + step;
  }
}
