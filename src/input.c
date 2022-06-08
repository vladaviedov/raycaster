#include "input.h"

#include <GL/glut.h>

#include "config.h"

int key_w;
int key_s;
int key_a;
int key_d;
int key_k;
int key_l;
double mouse_x;

void chg_key(unsigned char key, int state);

void i_keydown(unsigned char key, int x, int y) {
	chg_key(key, 1);
}

void i_keyup(unsigned char key, int x, int y) {
	chg_key(key, 0);
}

void i_mouse(int x, int y) {
	if (x == WIDTH / 2 && y == LENGTH / 2) {
		mouse_x = 0;
		return;
	}
	int dx = x - WIDTH / 2;
	mouse_x = (double)dx / WIDTH;
	glutWarpPointer(WIDTH / 2, LENGTH / 2);
}

void chg_key(unsigned char key, int state) {
	switch (key) {
		case 'w':
			key_w = state;
			break;
		case 's':
			key_s = state;
			break;
		case 'a':
			key_a = state;
			break;
		case 'd':
			key_d = state;
			break;
		case 'k':
			key_k = state;
			break;
		case 'l':
			key_l = state;
			break;
	}
}
