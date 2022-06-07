#include "input.h"

int key_w;
int key_s;
int key_a;
int key_d;
int key_k;
int key_l;

void chg_key(unsigned char key, int state);

void i_keydown(unsigned char key, int x, int y) {
	chg_key(key, 1);
}

void i_keyup(unsigned char key, int x, int y) {
	chg_key(key, 0);
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
