/*
  chapter 3: exercise 3-1

  our binary search makes two tests inside the loop, when one would
  suffice (at the price of more tests outside). Write a version with only one
  test inside the loop and measure the difference in run-time.
*/

#include <stdio.h>

int binsearch(int x, int v[], int n) // n is length of v[]
{
  int low, high, mid;

  low = 0;
  high = n - 1;

  mid = (low + high) / 2; // break array in half
  while (low <= high && x != v[mid])
  {
    // if x is less than middle element, drop the higher half of array
    if (x < v[mid])
    {
      high = mid - 1;
    }
    else if (x > v[mid])
    {
      low = mid + 1;
    }
    mid = (low + high) / 2; // break array in half at the end of each iteration
  }
  if (x == v[mid])
  {
    return mid; // found
  }
  else
  {
    return -1; // not found
  }
}

int main()
{
  // tests
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {10, 34, 42, 56, 79, 91, 98, 105, 106, 1045};
  int len1 = sizeof(arr1)/sizeof(arr1[0]);
  int len2 = sizeof(arr2)/sizeof(arr2[0]);

  // test arr1
  printf("arr1\n");
  printf("location of %d: %d\n", 4, binsearch(4, arr1, len1));
  printf("location of %d: %d\n", 10, binsearch(10, arr1, len1));
  printf("location of %d: %d\n", 11, binsearch(11, arr1, len1)); // returns -1
  printf("location of %d: %d\n", 194736, binsearch(194736, arr1, len1)); // returns -1

  // test arr2
  printf("arr2\n");
  printf("location of %d: %d\n", 79, binsearch(79, arr2, len2));
  printf("location of %d: %d\n", 34, binsearch(34, arr2, len2));
  printf("location of %d: %d\n", 4, binsearch(4, arr2, len2)); // returns -1
  printf("location of %d: %d\n", 194736, binsearch(194736, arr2, len2)); // returns -1

  return 0;
}
