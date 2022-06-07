#include "loader.h"

#include <GL/freeglut_std.h>
#include <stdio.h>
#include <GL/glut.h>

#include "map.h"
#include "csvmap.h"

int load_csv(char *file) {
	FILE *csv = fopen(file, "r");	

	csv_meta meta;
	csv_player player;
	csv_wall wall;

	if (csv_load_meta(csv, &meta) < 0) {
		return -1;
	}
	if (csv_load_player(csv, &player) < 0) {
		return -1;
	}

	glutSetWindowTitle(meta.name);

	if (map_new(meta.sizex, meta.sizey) < 0) {
		return -1;
	}
	if (map_set_spawn(player.spawnx, player.spawny) < 0) {
		return -1;
	}

	if (csv_goto_walls(csv) < 0) {
		return -1;
	}
	while (csv_next_wall(csv, &wall) == 0) {
		if (wall.type == HWALL) {
			for (int i = 0; i < wall.length; i++) {
				map_set_cell(wall.startx + i, wall.starty, WALL);
			}
		} else {
			for (int i = 0; i < wall.length; i++) {
				map_set_cell(wall.startx, wall.starty + i, WALL);
			}
		}
	}
	
	return 0;
}
