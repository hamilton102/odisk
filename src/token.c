#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

#define MAX_HEADER_LEN 256
#define MAX_LINE_LEN 256

enum Token {
  /* headers */
  LEFT_BRACKET = '[', RIGHT_BRACKET = ']',

  /* main config tokens */
  EQUAL = '=', SEMICOLON = ';', QUOTE = '"'
};

struct ini {
  /* key/value pair */
  char* header;
  int key;
  char* value;
};

struct ini* parse_line(char* input) {
  struct ini* pair;
  int count, buf_count = 0;
  char current = input[count];
  char header_buf[MAX_HEADER_LEN];
  char line_buf[MAX_LINE_LEN];
  while(current != '\n' && current != '\0') {
    /* this is where we'll actually parse the tokens out */
    switch(current) {
      case LEFT_BRACKET:
        /* increment the left bracket */
        ++count;
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
        pair -> header = strdup(header_buf);
        break;
      case RIGHT_BRACKET:
        /* right bracket without a left bracket is an error */
        error("Unopened character ]!");
        break;
      case ' ':
        /* we just want to ignore whitespace */
        break;
      default:
        /* by default, no behavior should happen */
        /* It should break if a character is left unclosed or unopened */
        break;
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
