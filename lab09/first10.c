/* first10.c: Print out the first 10 episodes in an rss file
 * Remember, type "make first10" to compile this program
 */

#include <stdio.h>
#include "rss.h"

int main() {
  printf("RSS filename: ");
  fflush(stdout);
  char fname[128];
  scanf(" %s", fname);

  // Notice, we call open_rss instead of fopen.
  RssFile* rss = open_rss(fname);
  if (!rss) {
    printf("ERROR: invalid rss file\n");
    return 1;
  }

  printf("First 10 episodes in the file are below.\n");

  // Declare strings to hold the info for each episode
  // Note, we expects titles and urls to (possibly) be very long,
  // but dates won't be as long.
  char title[256];
  char url[256];
  char date[64];

  int episode_index = 1;
  // loop through the first 10 episodes using next_episode()
  while (episode_index <= 10 && next_episode(rss)) {
    // call functions from rss.h to get episode information
    episode_title(rss, title);
    episode_date(rss, date);
    episode_url(rss, url);

    // display the information we just looked up
    printf("\n%d. %s\n", episode_index, title);
    printf("  date: %s\n", date);
    printf("  url: %s\n", url);

    ++episode_index;
  }

  // It's always good to clean up after yourself.
  close_rss(rss);

  return 0;
}
