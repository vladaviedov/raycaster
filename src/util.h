#ifndef RC_UTIL_H
#define RC_UTIL_H

#include <stddef.h>

#include "config.h"

#define upscale(x) (x * MAP_SCALE)

void fatal(int code, char *format, ...);
void *ualloc(size_t bytes);

#endif // RC_UTIL_H
