#include "raycast.h"

#include "../util.h"
#include "../map/map.h"

#include <math.h>
#include <GL/gl.h>

#define RENDER_DISTANCE 10
#define RAY_WIDTH 3

double cast_horz(double x, double y, double th);
double cast_vert(double x, double y, double th);
void draw_ray(double xi, double yi, double xf, double yf);

double cast_ray(double x, double y, double th, ray_type *type) {
	double horz_dist = HUGE_VAL;
	double vert_dist = HUGE_VAL;

	if (th != 0 && th != PI) {
		horz_dist = cast_horz(x, y, th);
	}
	
	if (th != (PI / 2) && th != (3 * PI / 2)) {
		vert_dist = cast_vert(x, y, th);
	}

	double dist = (horz_dist > vert_dist)
		? vert_dist
		: horz_dist;
	*type = (horz_dist > vert_dist)
		? VERT
		: HORZ;

	draw_ray(x, y, x + dist * cos(th), y + dist * sin(th));
	return dist;
}

double cast_horz(double x, double y, double th) {
	int n_dist = 0;
	int vdir = (th > PI) ? -1 : 1;
	double cy = scale_down(y);

	int gy = (vdir == 1)
		? ceil(cy)
		: floor(cy);
	double ry = scale_up(gy);
	double rx = x + (ry - y) / tan(th);
	int gx = scale_down(rx);

	int cchecky = gy;
	gy += vdir;
	if (vdir != 1) cchecky = gy;
	mp_cell_val hit_res = map_get_cell(gx, cchecky);
	
	while (hit_res == VOID && n_dist <= RENDER_DISTANCE) {
		n_dist++;
		ry = scale_up(gy);
		rx += scale_up(vdir) / tan(th);
		gx = scale_down(rx);
		cchecky = gy;
		gy += vdir;
		if (vdir != 1) cchecky = gy;
		hit_res = map_get_cell(gx, cchecky);
	}
	
	double distance = sqrt(((rx - x) * (rx - x)) + ((ry - y) * (ry - y)));
	return distance;
}

double cast_vert(double x, double y, double th) {
	int n_dist = 0;
	int hdir = (th > (PI / 2) && th < (3 * PI / 2)) ? -1 : 1;
	double cx = scale_down(x);

	int gx = (hdir == 1)
		? ceil(cx)
		: floor(cx);
	double rx = scale_up(gx);
	double ry = y + (rx - x) * tan(th);
	int gy = scale_down(ry);

	int ccheckx = gx;
	gx += hdir;
	if (hdir != 1) ccheckx = gx;
	mp_cell_val hit_res = map_get_cell(ccheckx, gy);
	
	while (hit_res == VOID && n_dist <= RENDER_DISTANCE) {
		n_dist++;
		rx = scale_up(gx);
		ry += scale_up(hdir) * tan(th);
		gy = scale_down(ry);
		ccheckx = gx;
		gx += hdir;
		if (hdir != 1) ccheckx = gx;
		hit_res = map_get_cell(ccheckx, gy);
	}

	double distance = sqrt(((rx - x) * (rx - x)) + ((ry - y) * (ry - y)));
	return distance;
}

void draw_ray(double xi, double yi, double xf, double yf) {
	glColor3d(1.0, 0.0, 0.0);
	glLineWidth(RAY_WIDTH);
	glBegin(GL_LINES);
	glVertex2d(xi, yi);
	glVertex2d(xf, yf);
	glEnd();
}
