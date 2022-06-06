#include "util.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

void fatal(int code, char *format, ...) {
	va_list vargs;
	va_start(vargs, format);
	vfprintf(stderr, format, vargs);

	va_end(vargs);
	exit(code);
}

void *ualloc(size_t bytes) {
	void *buf = calloc(bytes, 1);
	if (buf == NULL) {
		fatal(1, "Failed to allocate memory: %s", strerror(errno));
	}

	return buf;
}
