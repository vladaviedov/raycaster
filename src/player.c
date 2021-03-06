#include "player.h"

#include <math.h>
#include <GL/gl.h>

#include "util.h"
#include "input.h"
#include "3d/render.h"

#define PLAYER_SIZE 16
#define TRACER_WIDTH 5
#define TRACER_LENGTH_SCALE 8

static double px;
static double py;
static double pth;
static double pv = 5.0;
static double pw = 0.1;

static double dx;
static double dy;

void plr_draw(void) {
	glColor3d(1.0, 1.0, 0);
	glPointSize(PLAYER_SIZE);
	glBegin(GL_POINTS);
	glVertex2d(px, py);
	glEnd();

	glLineWidth(TRACER_WIDTH);
	glBegin(GL_LINES);
	glVertex2d(px, py);
	glVertex2d(px + (dx * TRACER_LENGTH_SCALE), py + (dy * TRACER_LENGTH_SCALE));
	glEnd();
}

void plr_moveto(double x, double y) {
	px = x;
	py = y;
}

void plr_push(double x, double y) {
	px += x;
	px += y;
}

void plr_update(void) {
	dx = pv * cos(pth);
	dy = pv * sin(pth);

	if (key_w) {
		py += dy;
		px += dx;
	}
	if (key_s) {
		py -= dy;
		px -= dx;
	}
	if (key_a) {
		py -= dx;
		px += dy;
	}
	if (key_d) {
		py += dx;
		px -= dy;
	}

	if (mouse_x) {
		pth += mouse_x * MOUSE_SENS;
	}

	if (key_l) {
		pth += pw;
		if (pth >= TAU) pth = 0;
	}
	if (key_k) {
		pth -= pw;
		if (pth < 0) pth = TAU;
	}

	render_3d(px, py, pth);
}
