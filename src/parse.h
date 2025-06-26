#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>

struct ini* parse_line(char* input);

void error(char* input);

char* read_line(FILE* fd);

#endif
