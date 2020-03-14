#include <stdio.h>

/*
exercise 1-3
modify the temperature conversion program to print a heading above the table
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
  printf(" F    C\n");
  
  while (fahr <= upper)
  {
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
