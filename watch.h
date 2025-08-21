#ifndef WATCH_H
#define WATCH_H

#include <sys/inotify.h>

#ifndef EVENT_SIZE
#define EVENT_SIZE (sizeof(struct inotify_event))
#endif

#ifndef BUF_LEN
#define BUF_LEN (1024 * (EVENT_SIZE + 16))
#endif

#endif
