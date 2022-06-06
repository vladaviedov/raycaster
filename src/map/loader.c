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

	if (csv_load_meta(csv, &meta) < 0) {
		return -1;
	}
	if (csv_load_player(csv, &player) < 0) {
		return -1;
	}

	glutSetWindowTitle(meta.name);

	if (map_new(meta.sizex, meta.sizey, player.spawnx, player.spawny) < 0) {
		return -1;
	}

	return 0;
}
