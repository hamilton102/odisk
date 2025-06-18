#include <stdio.h>
#include <stdlib.h>
#include "token.h"

enum Token {
  /* headers */
  LEFT_BRACKET, RIGHT_BRACKET,

  /* main config tokens */
  EQUAL, SEMICOLON, QUOTE, EOL
};

struct ini {
  /* key/value pair */
  char* header;
  int key;
  char* value;
};

struct ini* parse_line(char* input) {
  struct ini* pair;
  int count = 0;
  char current = input[count];
  while(current != '\n' && current != '\0') {
    /* this is where we'll actually parse the tokens out */
    switch(current) {
      case LEFT_BRACKET:
        /* do stuff until the right bracket */
        while (current != ']') {
          if (current == '\n' || current == '\0') {
            error("Unclosed character [!");
          }
          /* assume until right bracket that it all goes to one header */
          
        }
        break;
      case RIGHT_BRACKET:
        /* right bracket without a left bracket is an error */
        error("Unopened character ]!");
        break;
      case ' ':
        /* we just want to ignore whitespace */
        break;
      default:
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
  struct ini* ini = parse_line("\\n indicates a new line.\n");
  return 0;
}
