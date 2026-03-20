#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "parse.h"

#define DEFAUlT_CONFIG_LINUX '/config/odisk.ini'
#define DEFAULT_CONFIG_WIN '\\config\odisk.ini'

/* open file, do logic to extrapolate headers and key/values, store them in struct */
struct ini* parse_config(char* input_config_path) {
  char str[MAX_LINE_LEN];
  struct ini* ini_buf;
  struct ini* ini = malloc(sizeof(struct ini));
  FILE* fd = fopen(input_config_path, "r");
  if (fd == NULL) {
    error("Config file not able to be opened!");
  }
  while (fgets(str, MAX_LINE_LEN, fd)) {
    ini_buf = parse_line(str);
    if (ini_buf -> header != NULL) {
      ini -> header = strdup(ini_buf -> header);
    }
    if (ini_buf -> key != NULL && ini_buf -> value != NULL) {
      ini -> key = strdup(ini_buf -> key);
      ini -> value = strdup(ini_buf -> value);
    }
  }
  fclose(fd);
  free(ini_buf);
  return ini;
}
