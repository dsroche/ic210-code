/* repeat.c: printing out strings in a line.
 * YOUR NAME HERE
 */

#include <stdio.h>
typedef char cstring[128];

// Prints out the string s, count times in a row,
// in a single line.
// You must implement this using recursion!
void repeat(cstring s, int count);

// DO NOT CHANGE the main function! Just write the definition
// of repeat below.
int main() {
  printf("10 X's Xing:\n");
  repeat("X", 10);
  printf("\n");

  cstring DIAMOND = "\u2bc1";
  printf("8 diamonds dimeing:\n");
  repeat(DIAMOND, 8);
  printf("\n");

  cstring TRIANGLE = "\u25b2";
  printf("13 triangles trying:\n");
  repeat(TRIANGLE, 13);
  printf("\n");

  cstring RINGTOP = "\u250c\u2510";
  cstring RINGBOT = "\u2514\u2518";
  printf("5 pipey rings!\n");
  repeat(RINGTOP, 5);
  printf("\n");
  repeat(RINGBOT, 5);
  printf("\n");

  return 0;
}
