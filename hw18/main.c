// DO NOT CHANGE THIS FILE!
// Your code should be in two new files, countdown.h and countdown.c

#include <stdio.h>
#include "countdown.h"

int main() {
  int n;
  do {
    printf("Enter n: ");
    fflush(stdout);
  } while (scanf(" %d", &n) != 1);

  // this calls the function YOU have to write!
  countdown(n);

  return 0;
}
