#include <stdio.h>
#include "algorithms.h"

#define ARRAYSIZE(arr) sizeof((arr)) / sizeof(arr[0]) 

int comp_i(int i, int j) {
  if (i == j)
    return 0;
  else if (i < j)
    return -1;
  else
    return 1;
}

LOWER_BOUND_FN(lower_bound_ii, int *, int);

int main()
{
  int arr[] = {11, 21, 33, 44, 55, 61, 147, 158, 911, 1000};
  int *end = arr + ARRAYSIZE(arr);
  int *lb = lower_bound_ii(arr, end, 56, comp_i);

  printf("%d\n", *lb);

  return 0;
}
