%: %.c rss.c rss.h
	gcc `xml2-config --cflags` -Wall -Wextra -O2 -g $< rss.c `xml2-config --libs` -lm -o $@
