#include "render.h"

#include <math.h>
#include <GL/gl.h>

#include "../util.h"
#include "../config.h"
#include "../map/map.h"
#include "raycast.h"

void render_3d(double px, double py, double pth) {
	double start_th = pth - (FOV / 2.0) * DEG;
	for (int i = 0; i < RAYS; i++) {
		double th = start_th + i * DEG * (FOV / RAYS);
		if (th < 0) th += TAU;
		if (th > TAU) th -= TAU;
		ray_type rt;
		double dth = pth - th;
		double dist = cast_ray(px, py, th, &rt) * cos(dth);

		double height = MAP_SCALE * LENGTH / dist;
		if (dist > LENGTH) dist = LENGTH;
		double offset = map_2d_end() + 50;
		double width = floor((WIDTH - offset) / RAYS);

		if (rt == HORZ) glColor3d(0.7, 0, 0);
		else glColor3d(0.9, 0, 0);
		glLineWidth(width);
		glBegin(GL_QUADS);
		glVertex2d(offset + width * i, LENGTH / 2.0 - height / 2.0);
		glVertex2d(offset + width * (i + 1), LENGTH / 2.0 - height / 2.0);
		glVertex2d(offset + width * (i + 1), LENGTH / 2.0 + height / 2.0);
		glVertex2d(offset + width * i, LENGTH / 2.0 + height / 2.0);
		glEnd();
	}
}
