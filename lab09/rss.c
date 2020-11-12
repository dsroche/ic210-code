/* rss.c: Implementation for IC220 rss feed functions.
 */

#include "rss.h"
#include <libxml/parser.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* This function attempts to open an rss file with the
 * given filename. If successful, it returns a pointer to
 * a newly-allocated RssFile object.
 * If the filename is bad or the file contents don't match the
 * rss format, it will return a NULL pointer.
 */
RssFile* open_rss(char* fname) {
  xmlDoc* doc = xmlReadFile(fname, NULL, 0);
  if (!doc) return NULL;
  xmlNode* root = xmlDocGetRootElement(doc);
  if (!root) return NULL;

  // find channel node
  xmlNode* root_child = root->children->next;
  while (root_child && strcmp((char*)root_child->name, "channel") != 0) {
    root_child = root_child->next;
  }
  if (!root_child)
    return NULL;

  RssFile* rss = calloc(1, sizeof(RssFile));
  rss->document = doc;
  rss->channel_node = root_child;

  return rss;
}

/* Closes the given rss file that was previously opened,
 * and deallocates memory that was allocated during open_rss.
 */
void close_rss(RssFile* rfile) {
  if (!rfile || !rfile->document) {
    fprintf(stderr, "ERROR in call to close_rss: ResFile is not initialized\n");
    exit(2);
  }
  xmlFreeDoc(rfile->document);
  free(rfile);
}

/* This function takes a pointer to an open RSS file object,
 * and attempts to read until the next episode in the podcast's feed.
 * If successful, it returns true. Otherwise, if there are no more
 * eposides, the function returns false.
 */
bool next_episode(RssFile* rfile) {
  if (!rfile || !rfile->channel_node) {
    fprintf(stderr, "ERROR in call to next_episode: ResFile is not initialized\n");
    exit(2);
  }

  if (rfile->current_item)
    rfile->current_item = rfile->current_item->next;
  else
    rfile->current_item = rfile->channel_node->children->next;

  while (rfile->current_item && strcmp((char*)rfile->current_item->name, "item") != 0) {
    rfile->current_item = rfile->current_item->next;
  }

  return (bool) rfile->current_item;
}

/* Takes a pointer to an open RSS file object, and a string,
 * and sets the string string to the title of the episode.
 * Note, it is up to you to allocate the string before calling
 * this function, and make sure it is long enough!
 */
void episode_title(RssFile* rfile, char* s) {
  if (!rfile || !rfile->current_item) {
    fprintf(stderr, "ERROR in call to episode_title: did you call next_episode() first?\n");
    exit(2);
  }

  xmlNode* item_child = rfile->current_item->children->next;
  while (item_child) {
    if (strcmp((char*)item_child->name, "title") == 0) {
      strcpy(s, (char*)item_child->children->content);
      return;
    }
    item_child = item_child->next;
  }

  // no title found within the item
  // better to use a default title than make an error
  strcpy(s, "NO TITLE");
}

/* Takes a pointer to an open RSS file object, and a string,
 * and changes the string to the date when the episode was released.
 * Note, it is up to you to allocate the string before calling
 * this function, and make sure it is long enough!
 */
void episode_date(RssFile* rfile, char* s) {
  if (!rfile || !rfile->current_item) {
    fprintf(stderr, "ERROR in call to episode_date: did you call next_episode() first?\n");
    exit(2);
  }

  xmlNode* item_child = rfile->current_item->children->next;
  while (item_child) {
    if (strcmp((char*)item_child->name, "pubDate") == 0) {
      strcpy(s, (char*)item_child->children->content);
      return;
    }
    item_child = item_child->next;
  }

  // no pubDate found within the item
  // better to use a default date than make an error
  strcpy(s, "Thu, 12 Nov 2020 08:00:00 -0500");
}

/* Takes a pointer to an open RSS file object, and a string,
 * and changes the string to the URL of this episode (mp3 file).
 * Note, it is up to you to allocate the string before calling
 * this function, and make sure it is long enough!
 */
void episode_url(RssFile* rfile, char* s) {
  if (!rfile || !rfile->current_item) {
    fprintf(stderr, "ERROR in call to episode_url: did you call next_episode() first?\n");
    exit(2);
  }

  xmlNode* item_child = rfile->current_item->children->next;
  while (item_child) {
    if (strcmp((char*)item_child->name, "enclosure") == 0) {
      xmlAttr* attr = item_child->properties;
      while (attr && strcmp((char*)attr->name, "url") != 0) {
        attr = attr->next;
      }
      if (attr) {
        strcpy(s, (char*)attr->children->content);
        return;
      }
    }
    item_child = item_child->next;
  }

  // no enclosure with url attribute found within the item
  // better to use a default than make an error
  strcpy(s, "https://www.codecademy.com/404-error-page");
}
