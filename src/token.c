#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

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
  int key;
  char* value;
};

struct ini* parse_line(char* input) {
  printf("Start of function parse_line\n");
  struct ini* pair = malloc(sizeof(struct ini));
  if (pair == NULL) {
    error("Malloc failed\n");
  }

  int count = 0, buf_count = 0;
  char current = input[count];
  char header_buf[MAX_HEADER_LEN];
  char line_buf[MAX_LINE_LEN];
  while(current != NEWLINE && current != EOL) {
    printf("start of while loop \n");
    /* this is where we'll actually parse the tokens out */

    /* First, parse headers */
    if (current == LEFT_BRACKET) {
        /* increment the left bracket */
        printf("count is: %d\n", count);
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
      printf("returning header\n");
      header_buf[buf_count] = EOL;
      pair -> header = strdup(header_buf);
      }
    else if (current == RIGHT_BRACKET)
    {
      /* right bracket without a left bracket is an error */
      error("Unopened character ]!");
    }
    ++count;
    current = input[count];
  }
  return pair;
}

void error(char* input) {
  printf("ERROR: %s", input);
  exit(1);
}

int main(void) {
  struct ini* ini = parse_line("[Header]\n");
  printf("The parsed header in this line is %s", ini -> header);
  free(ini -> header);
  return 0;
}
