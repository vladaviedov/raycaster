#include "raycast.h"

#include "../util.h"
#include "../map/map.h"

#include <math.h>
#include <GL/gl.h>

#define RENDER_DISTANCE 16
#define RAY_WIDTH 3

ray_result cast_horz(double x, double y, double th);
ray_result cast_vert(double x, double y, double th);
void draw_ray(double xi, double yi, double xf, double yf);

ray_result cast_ray(double x, double y, double th) {
	ray_result horz_ray = cast_horz(x, y, th);
	ray_result vert_ray = cast_vert(x, y, th);
	
	ray_result *ray = horz_ray.distance > vert_ray.distance
		? &vert_ray
		: &horz_ray;

	if (render_2d)
		draw_ray(x, y, x + ray->distance * cos(th), y + ray->distance * sin(th));

	return *ray;
}

ray_result cast_horz(double x, double y, double th) {
	ray_result res = { HORZ, OOB, HUGE_VAL };
	if (th == 0 || th == PI) {
		return res;
	}

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
	
	while (hit_res != WALL && n_dist <= RENDER_DISTANCE) {
		n_dist++;
		ry = scale_up(gy);
		rx += scale_up(vdir) / tan(th);
		gx = scale_down(rx);
		cchecky = gy;
		gy += vdir;
		if (vdir != 1) cchecky = gy;
		hit_res = map_get_cell(gx, cchecky);
	}
	
	if (n_dist != RENDER_DISTANCE) {
		res.hit_result = hit_res;
		res.distance = sqrt(((rx - x) * (rx - x)) + ((ry - y) * (ry - y)));
	}

	return res;
}

ray_result cast_vert(double x, double y, double th) {
	ray_result res = { VERT, OOB, HUGE_VAL };
	if (th == PI / 2 || th == 3 * PI / 2) {
		return res;
	}

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
	
	while (hit_res != WALL && n_dist < RENDER_DISTANCE) {
		n_dist++;
		rx = scale_up(gx);
		ry += scale_up(hdir) * tan(th);
		gy = scale_down(ry);
		ccheckx = gx;
		gx += hdir;
		if (hdir != 1) ccheckx = gx;
		hit_res = map_get_cell(ccheckx, gy);
	}

	if (n_dist != RENDER_DISTANCE) {
		res.hit_result = hit_res;
		res.distance = sqrt(((rx - x) * (rx - x)) + ((ry - y) * (ry - y)));
	}

	return res;
}

void draw_ray(double xi, double yi, double xf, double yf) {
	glColor3d(1.0, 0.0, 0.0);
	glLineWidth(RAY_WIDTH);
	glBegin(GL_LINES);
	glVertex2d(xi, yi);
	glVertex2d(xf, yf);
	glEnd();
}
