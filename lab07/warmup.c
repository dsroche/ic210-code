/* Warmup program to practice int array functions.
 * YOUR NAME HERE
 * Note, you should not change main(), just write the definitions for
 * these functions.
 */

#include <stdio.h>
#include <stdbool.h>

// fills in the array with integers read from stdin
void read(int* array, int size);

// prints the array to stdout, lined up with dashes and
// corresponding capital letters underneath
void print(int* array, int size);

// returns 1 if the array elements are in ascending (non-decreasing)
// order, and otherwise returns 0.
bool is_ordered(int* array, int size);

int main() {
  int size;
  scanf(" N = %i :", &size);

  int arr[size];
  read(arr, size);

  print(arr, size);

  if (is_ordered(arr, size)) {
    printf("Is in order!\n");
  } else {
    printf("Is not in order!\n");
  }

  return 0;
}
