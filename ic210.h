/* Simple C typedefs and helper functions for strings and I/O
 * IC210 Fall 2020, USNA
 */

/* Make sure nothing bad happens if you #include this file twice */
#ifndef IC210_H
#define IC210_H

/* Standard header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Define a special type "cstring" which is just a char array
 * of a predetermined, fixed length.
 * XXX: If you change this, be sure to update CSTRINGSCAN below also. */
#define CSTRINGLEN 128
typedef char cstring[CSTRINGLEN];

/* The scanf argument for a cstring.
 * The size must be one less than CSTRINGLEN,
 * to leave space for the null byte at the end.
 */
#define CSTRINGSCAN "%127s"

/* Typedef for stream, which is the same as FILE* */
typedef FILE* stream;

/* Function prototypes defined here.
 * Note: they are declared "static" because the implementations are
 * below, not in a separately-compiled file.
 */
static char readchar(stream in);
static void readstring(cstring s, stream in);
static double readnum(stream in);
static void writenum(double x, stream out);
static bool stringeq(cstring a, cstring b);

/* These two lines prevent some compiler warnings in case you don't
 * use every function here in your own code. */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

/* Function definitions below */

char readchar(stream in) {
  char c;

  /* when reading from stdin, make sure all pending stdout output
   * is written first */
  if (in == stdin) fflush(stdout);

  /* The fscanf is the most important part!
   * It returns the number of items successfully read. */
  if (fscanf(in, " %c", &c) != 1) {
    fprintf(stderr, "\nERROR in readchar. Maybe end-of-file?\n");
    abort();
  }

  return c;
}

void readstring(cstring s, stream in) {
  /* when reading from stdin, make sure all pending stdout output
   * is written first */
  if (in == stdin) fflush(stdout);

  /* The fscanf is the most important part!
   * It returns the number of items successfully read. */
  if (fscanf(in, CSTRINGSCAN, s) != 1) {
    fprintf(stderr, "\nERROR in readstring. Maybe end-of-file?\n");
    abort();
  } else if (strlen(s) >= CSTRINGLEN - 1) { /* Note, using strnlen would be "safer". */
    fprintf(
        stderr,
        "\nERROR: Input string is too long (must be at most %d characters).\n",
        CSTRINGLEN - 2);
    abort();
  }
}

double readnum(stream in) {
  double x;

  /* when reading from stdin, make sure all pending stdout output
   * is written first */
  if (in == stdin) fflush(stdout);

  /* The fscanf is the most important part!
   * It returns the number of items successfully read. */
  if (fscanf(in, "%lf", &x) != 1) {
    char c = fgetc(in);
    if (feof(in)) fprintf(stderr, "\nERROR in readnum: Maybe end-of-file?\n");
    else fprintf(stderr, "\nERROR in readnum: Number cannot start with '%c'.\n", c);
    abort();
  }

  return x;
}

void writenum(double x, stream out) {
  /* The fprintf is the most important part!
   * It returns the number of characters actually printed. */
  if (fprintf(out, "%g", x) <= 0) {
    fprintf(stderr, "\nERROR on writenum. Maybe the stream is invalid?\n");
    abort();
  }
}

bool stringeq(cstring a, cstring b) {
  /* Note, using strncmp would be "safer". */
  return strcmp(a, b) == 0;
}

/* End the warning-free zone for unused functions. */
#pragma GCC diagnostic pop

#endif /* ifdef IC210_H */
