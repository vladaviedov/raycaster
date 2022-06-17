#ifndef RC_UTIL_H
#define RC_UTIL_H

#include <stddef.h>

#include "config.h"

#define PI 3.1415926
#define TAU (2 * PI)
#define DEG (PI / 180)

#define scale_up(x) (x * MAP_SCALE)
#define scale_down(x) (x / MAP_SCALE)

extern int render_2d;

void fatal(int code, char *format, ...);
void *ualloc(size_t bytes);

#endif // RC_UTIL_H
