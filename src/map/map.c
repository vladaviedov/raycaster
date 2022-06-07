#include "map.h"

#include <stdlib.h>
#include <GL/gl.h>

#include "../config.h"
#include "../util.h"
#include "../player.h"

typedef struct {
	mp_cell_val **data;
	int xdim;
	int ydim;
	int spawnx;
	int spawny;
} map2d;

static map2d map = { NULL, 0, 0, 0, 0 };

int map_new(int xdim, int ydim) {
	if (xdim < 0 || ydim < 0) {
		return -1;
	}

	map.data = ualloc(sizeof(mp_cell_val *) * xdim);
	for (int i = 0; i < xdim; i++) {
		map.data[i] = ualloc(sizeof(mp_cell_val) * ydim);
	}

	map.ydim = ydim;
	map.xdim = xdim;

	return 0;
}

int map_set_spawn(int x, int y) {
	if (map.data == NULL) {
		return -1;
	}

	map.spawnx = x;
	map.spawny = y;
	plr_moveto(scale_up(x), scale_up(y));

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
	for (int x = 0; x < map.xdim; x++) {
		int xs = scale_up(x);
		for (int y = 0; y < map.ydim; y++) {
			int ys = scale_up(y);
			switch (map.data[x][y]) {
				case VOID:
					glColor3d(0.3, 0.5, 0.3);
					break;
				case WALL:
					glColor3d(0.0, 0.0, 0.0);
					break;
			}
			glBegin(GL_QUADS);
			glVertex2i(xs + 1, ys + 1);
			glVertex2i(xs + 1, ys + MAP_SCALE - 1);
			glVertex2i(xs + MAP_SCALE - 1, ys + MAP_SCALE - 1);
			glVertex2i(xs + MAP_SCALE - 1, ys + 1);
			glEnd();
		}
	}
}
