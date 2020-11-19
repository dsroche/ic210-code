# Makefile for GPS tracks project

# These lines indicate the flags used when compiling and linking.
CFLAGS = -Wall -Wextra -Wno-unused -Wno-sign-compare -O2 -g $(shell pkg-config --cflags libxml-2.0 gtk+-3.0 cairo)
LDLIBS = $(shell pkg-config --libs libxml-2.0 gtk+-3.0 cairo) -lm

# These are variables to say what are the .h and the main-less .c files in this directory.
HEADER_FILES = gps.h
IMPLEMENTATION_FILES = gps.c

track:

%: %.c $(HEADER_FILES) $(IMPLEMENTATION_FILES)
	gcc $(CFLAGS) $< $(IMPLEMENTATION_FILES) $(LDLIBS) -o $@
