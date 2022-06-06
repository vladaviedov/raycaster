#ifndef RC_UTIL_H
#define RC_UTIL_H

#include <stddef.h>

void fatal(int code, char *format, ...);
void *ualloc(size_t bytes);

#endif // RC_UTIL_H
