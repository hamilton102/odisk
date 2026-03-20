#ifndef CONFIG_H
#define CONFIG_H

#ifndef MAX_LINE_LEN
#define MAX_LINE_LEN 256
#endif

#ifndef MAX_HEADER_LEN
#define MAX_HEADER_LEN 256
#endif

#ifndef MAX_DIRECTORY_WATCH_LEN
#define MAX_DIRECTORY_WATCH_LEN 8
#endif

#include <stdio.h>

struct ini* parse_config(char* input_config);

char* read_from_directory();

#endif
