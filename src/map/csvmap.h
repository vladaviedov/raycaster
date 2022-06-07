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

enum wall_type {
	HWALL,
	VWALL
};
typedef struct {
	int startx;
	int starty;
	enum wall_type type;
	int length;
} csv_wall;

int csv_load_meta(FILE *fp, csv_meta *buf);
int csv_load_player(FILE *fp, csv_player *buf);
int csv_goto_walls(FILE *fp);
int csv_next_wall(FILE *fp, csv_wall *buf);

#endif // RC_MAP_CSVMAP_H
