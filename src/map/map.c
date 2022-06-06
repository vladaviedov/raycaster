#include "map.h"

#include <stdlib.h>

#include "../util.h"

typedef struct {
	mp_cell_val **data;
	int xdim;
	int ydim;
	int spawnx;
	int spawny;
} map2d;

static map2d map = { NULL, 0, 0, 0, 0 };

int map_new(int xdim, int ydim, int spawnx, int spawny) {
	if (xdim < 0 || ydim < 0) {
		return -1;
	}

	map.data = ualloc(sizeof(mp_cell_val *) * xdim);
	for (int i = 0; i < xdim; i++) {
		map.data[i] = ualloc(sizeof(mp_cell_val) * ydim);
	}

	map.spawnx = spawnx;
	map.spawny = spawny;

	return 0;
}

int map_del(void) {
	if (map.data != NULL) {
		for (int i = 0; i < map.xdim; i++) {
			free(map.data[i]);
		}
		free(map.data);
		map.data = NULL;
		return 0;
	}

	return -1;
}

int map_set_cell(int x, int y, mp_cell_val val) {
	if (map.data == NULL) {
		return -1;
	}
	if (x < 0 || y < 0) {
		return -1;
	}
	if (x >= map.xdim || y >= map.ydim) {
		return -1;
	}

	map.data[x][y] = val;
	return 0;
}

void map_draw(void) {

}
