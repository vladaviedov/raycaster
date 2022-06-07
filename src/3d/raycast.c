#include "raycast.h"

#include "../util.h"
#include "../map/map.h"

#include <math.h>
#include <GL/gl.h>

#define RENDER_DISTANCE 4

double cast_horz(double x, double y, double th);
double cast_vert(double x, double y, double th);
void draw_ray(double xi, double yi, double xf, double yf);

double cast_ray(double x, double y, double th) {
	double horz_dist = HUGE_VAL;
	double vert_dist = HUGE_VAL;

	if (th != 0 && th != PI) {
		horz_dist = cast_horz(x, y, th);
	}
	
	if (th != (PI / 2) && th != (3 * PI / 2)) {
		vert_dist = cast_vert(x, y, th);
	}

	return (horz_dist > vert_dist)
		? vert_dist
		: horz_dist;
}

double cast_horz(double x, double y, double th) {
	int n_dist = 0;
	int vdir = (th > PI) ? 1 : -1;
	double cy = scale_down(y);

	int gy = (vdir == 1)
		? floor(cy)
		: ceil(cy);
	double ry = scale_up(gy);
	double rx = x + (ry - y) / tan(th);
	int gx = scale_down(rx);

	if (vdir != 1) gy--;
	else gy++;
	mp_cell_val hit_res = map_get_cell(gx, gy);
	
	double distance = sqrt(((rx - x) * (rx - x)) + ((ry - y) * (ry - y)));
	draw_ray(x, y, rx, ry);
	return distance;
}

double cast_vert(double x, double y, double th) {
	return HUGE_VAL;
}

void draw_ray(double xi, double yi, double xf, double yf) {
	glColor3d(1.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2d(xi, yi);
	glVertex2d(xf, yf);
	glEnd();
}
