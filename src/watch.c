#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/inotify.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

int main(void)
{
  int fd, wd, len, i = 0;
  char buffer[BUF_LEN];

while(1) {
    /* init the inotify instance */
    fd = inotify_init();
    /* add a file watcher */
    wd = inotify_add_watch(fd, "/", IN_ALL_EVENTS);
    /* return the length, 0 for EOF, -1 for ERR, and positive integer for event length */
    len = read(fd, buffer, BUF_LEN);
    /* while there are still events: */
    while (i < len) {
      /* cast to an inotify pointer */
      struct inotify_event *event = ( struct inotify_event * ) &buffer[i];
      uint32_t mask = event -> mask;
      if (event -> len) {
        if (mask & IN_ACCESS) printf("IN_ACCESS %s\n", event -> name);
        if (mask & IN_ATTRIB) printf("IN_ATTRIB %s\n", event -> name);
        if (mask & IN_CLOSE_WRITE) printf("IN_CLOSE_WRITE %s\n", event -> name);
        if (mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE %s\n", event -> name);
        if (mask & IN_CREATE) printf("IN_CREATE %s\n", event -> name);
        if (mask & IN_DELETE) printf("IN_DELETE %s\n", event -> name);
        if (mask & IN_DELETE_SELF) printf("IN_DELETE_SELF %s\n", event -> name);
        if (mask & IN_MODIFY) printf("IN_MODIFY %s\n", event -> name);
        if (mask & IN_MOVE_SELF) printf("IN_MOVE_SELF %s\n", event -> name);
        if (mask & IN_MOVED_FROM) printf("IN_MOVED_FROM %s\n", event -> name);
        if (mask & IN_MOVED_TO) printf("IN_MOVED_TO %s\n", event -> name);
        if (mask & IN_OPEN) printf("IN_OPEN %s\n", event -> name);
        if (mask & IN_OPEN) printf("IN_OPEN %s\n", event -> name);
      }
      i += EVENT_SIZE + event -> len;
    }
    inotify_rm_watch(fd, wd);
    close(fd);
  }

  return 0;
}

