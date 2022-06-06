#ifndef RC_MAP_CSVMAP_H
#define RC_MAP_CSVMAP_H

#include <stdio.h>

typedef struct {
	char *name;
	int sizex;
	int sizey;
} csv_meta;

typedef struct {
	int spawnx;
	int spawny;
} csv_player;

int csv_load_meta(FILE *fp, csv_meta *buf);
int csv_load_player(FILE *fp, csv_player *buf);

#endif // RC_MAP_CSVMAP_H
