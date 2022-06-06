#include "map.h"

#include <stdlib.h>

typedef enum {
	VOID,
	WALL
} cell;

static cell **map;

int map_new(int xdim, int ydim) {
	if (xdim < 0 || ydim < 0) {
		return -1;
	}

	map = calloc(xdim, sizeof(cell *));
	if (map == NULL) {
		return -1;
	}

	for (int i = 0; i < xdim; i++) {

	}

	return 0;
}

int map_del(void) {
	return 0;
}

void map_draw(void) {

}
