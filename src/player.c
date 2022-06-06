#include "player.h"

#include <GL/gl.h>

#include "input.h"

#define PLAYER_SIZE 8

static double px = 20;
static double py = 20;
static double pv = 5.0;

void plr_draw(void) {
	glColor3d(1.0, 1.0, 0);
	glPointSize(PLAYER_SIZE);
	glBegin(GL_POINTS);
	glVertex2d(px, py);
	glEnd();
}

void plr_moveto(double x, double y) {
	px = x;
	py = y;
}

void plr_push(double dx, double dy) {
	px += dx;
	px += dy;
}

void plr_update(void) {
	if (key_w) py -= pv;
	if (key_s) py += pv;
	if (key_a) px -= pv;
	if (key_d) px += pv;
}
