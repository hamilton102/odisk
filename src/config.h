#ifndef CONFIG_H
#define CONFIG_H

#ifndef MAX_LINE_LEN
#define MAX_LINE_LEN 256
#endif

#ifndef MAX_HEADER_LEN
#define MAX_HEADER_LEN 256
#endif

#include <stdio.h>

void parse_config(FILE* input_config);

#endif
