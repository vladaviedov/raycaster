#ifndef RC_MAP_MAP_H
#define RC_MAP_MAP_H

typedef enum {
	VOID,
	WALL,
	OOB
} mp_cell_val;

int map_new(int xdim, int ydim);
int map_set_spawn(int x, int y);
int map_del(void);
int map_set_cell(int x, int y, mp_cell_val val);
mp_cell_val map_get_cell(int x, int y);
void map_draw(void);

#endif // RC_MAP_MAP_H
