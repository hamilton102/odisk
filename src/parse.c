#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

#define MAX_HEADER_LEN 256
#define MAX_LINE_LEN 256

/* TOKENS */

/* Headers */
#define LEFT_BRACKET '['
#define RIGHT_BRACKET ']'

/* Key/Value tokens */
#define EQUALS '='
#define QUOTE '"'
#define NEWLINE '\n'
#define EOL '\0'

struct ini {
  /* key/value pair */
  char* header;
  char* key;
  char* value;
};

struct ini* parse_line(char* input) {
  struct ini* pair = malloc(sizeof(struct ini));
  if (pair == NULL) {
    error("Malloc failed\n");
  }

  int count = 0, buf_count = 0;
  char current = input[count];
  char header_buf[MAX_HEADER_LEN];
  char line_buf[MAX_LINE_LEN];
  while(current != NEWLINE && current != EOL) {
    /* this is where we'll actually parse the tokens out */

    /* First, parse headers */
    if (current == LEFT_BRACKET) {
        /* increment the left bracket */
        ++count;
        current = input[count];
        while (current != RIGHT_BRACKET) {
          if (current == '\n'|| current == '\0') {
            error("Unclosed character [!");
          }
        /* assume until right bracket that it all goes to one header */
        header_buf[buf_count] = current;
        ++count;
        ++buf_count;
        current = input[count];
          }
      header_buf[buf_count] = EOL;
      pair -> header = strdup(header_buf);
      }
    else if (current == RIGHT_BRACKET)
    {
      /* right bracket without a left bracket is an error */
      error("Unopened character ]!");
    }

    line_buf[buf_count] = current;
    ++buf_count;

    if (current == EQUALS)
    {
      line_buf[buf_count - 1] = EOL;
      pair -> key = strdup(line_buf);

      /* reset buf count and current string line */

      buf_count = 0;
      strcpy(line_buf, "");

      /* increment past equals sign */
      ++count;

      while (current != EOL && current != NEWLINE)
      {
        if (buf_count >= MAX_LINE_LEN || count >= MAX_HEADER_LEN)
        {
          error("Header or line size too big");
        }
        /* assume the rest of the line is the value */
        current = input[count];
        line_buf[buf_count] = current;
        ++buf_count;
        ++count;
      }
      line_buf[buf_count] = EOL;
      pair -> value = strdup(line_buf);
    }
    ++count;
    current = input[count];
  }
  return pair;
}

char* read_line(FILE* fd)
{
  
}

void error(char* input) {
  printf("ERROR: %s\n", input);
  exit(1);
}

int main(void) {
  FILE* fd = fopen("config.ini", "r");
  struct ini* ini = parse_line();
  free(ini -> header);
  return 0;
}
