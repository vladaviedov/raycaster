#ifndef RC_MAP_MAP_H
#define RC_MAP_MAP_H

typedef enum {
	VOID,
	WALL
} mp_cell_val;

int map_new(int xdim, int ydim);
int map_set_spawn(int x, int y);
int map_del(void);
int map_set_cell(int x, int y, mp_cell_val val);
void map_draw(void);

#endif // RC_MAP_MAP_H
