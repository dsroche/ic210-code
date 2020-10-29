/* YOU MAY NOT CHANGE THIS FILE.
 * (Any changes will be ignored when you submit.)
 */

#include <stdio.h>
#include "vote_functions.h"

typedef char cstring[128];

int main() {
  cstring candidate1;
  cstring candidate2;

  get_names(candidate1, candidate2);

  int count1 = 0;
  int count2 = 0;

  printf("Enter votes, ending with \"END\":\n");

  cstring selection;
  scanf(" %s", selection);
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) {
    scanf(" %s", selection);
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}
