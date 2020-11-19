/* Small main program to test linked list functions.
 * Feel free to copy to a new file and edit to test more scenarios.
 * (The auto-tests will cover more cases than what are covered here,
 * so you need to test your own code!!)
 */

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

char* bool2str(bool b);

int main() {
  Node* L = NULL;

  char str[128];
  printf("Enter 5 words in reverse order: ");
  fflush(stdout);
  for (int i=0; i<5; ++i) {
    scanf(" %s", str);
    L = add2front(str, L);
  }

  printf("\n");
  printf("Contents in order:\n");
  print_fwd(L);

  printf("\n");
  printf("contains orange: %s\n", bool2str(contains("orange", L)));
  printf("contains brown: %s\n", bool2str(contains("brown", L)));

  printf("\n");
  printf("the string at index 2 is %s\n", get_ith(2, L));

  printf("\n");
  printf("the total number of characters is %d\n", num_chars(L));

  /* uncomment once you get to these!
  printf("\n");
  printf("Contents in reverse order:\n");
  print_rev(L);

  printf("\n");
  printf("Contents after removing index 3:\n");
  L = remove_ith(3, L);
  print_fwd(L);
  */

  free_list(L);

  return 0;
}

char* bool2str(bool b) {
  if (b) return "true";
  else return "false";
}
