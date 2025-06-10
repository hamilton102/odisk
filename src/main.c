#include "unistd.h"
#include <stdio.h>
// #include <stdlib.h>
#include <sys/inotify.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

int main(void)
{

  int fd, wd, len, i = 0;
  char buffer[BUF_LEN];
  //char *str = argv[1];

  // init the inotify instance
  fd = inotify_init();
  // add a file watcher
  wd = inotify_add_watch(fd, "/etc", IN_MODIFY | IN_CREATE | IN_DELETE);
  // return the length, 0 for EOF, -1 for ERR, and positive integer for event length
  len = read(fd, buffer, BUF_LEN);

  // while there are still events:
  while (i < len) {
    // cast to an inotify pointer
    struct inotify_event *event = ( struct inotify_event * ) &buffer[i];
    if (event -> len) {
      if (event -> mask & IN_MODIFY) {
        printf("The %s %s was modified\n", (event -> mask & IN_ISDIR ? "directory": "file"), event -> name);
        
      }
    }
    i += EVENT_SIZE + event -> len;
  }

  inotify_rm_watch(fd, wd);
  close(fd);
  return 0;
}

