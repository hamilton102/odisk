#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "timer.h"

int parse_time(const char* amount) {
  int value = atoi(amount);
  char type = amount[strlen(amount) - 1];
  switch(type) {
    case 's':
      return value;
    case 'm':
      return value * 60;
    case 'h':
      return value * 3600;
    case 'd':
      return value * 86400;
    /* honestly anything more than a day is kinda goofy, just have it check every 
      5-10 seconds like a normal person */
    default:
      return value * -1;
  }
  return value;
}

void run_timer(const int time) {
  if (time <= 0) {
      printf("The value of time cannot be less than or equal to 0.");
      exit(1);
    }
  sleep(time);
}
