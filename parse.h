#ifndef PARSE_H
#define PARSE_H

#ifndef MAX_LINE_LEN
#define MAX_LINE_LEN 256
#endif

#ifndef MAX_HEADER_LEN
#define MAX_HEADER_LEN 256
#endif

#include <stdio.h>

struct ini {
  char* header;
  char* key;
  char* value;
};

struct ini* parse_line(char* input);

void error(char* input);

#endif
