#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "config.h"
#include "util.h"
#include "input.h"
#include "player.h"
#include "map/map.h"
#include "map/loader.h"

void init(void);
void loop(void);

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH, LENGTH);
	glutCreateWindow(WIN_NAME);
	glutIgnoreKeyRepeat(1);
	glutSetCursor(GLUT_CURSOR_NONE);
	init();

	glutDisplayFunc(&loop);
	glutKeyboardFunc(&i_keydown);
	glutKeyboardUpFunc(&i_keyup);
	glutPassiveMotionFunc(&i_mouse);
	glutMotionFunc(&i_mouse);
	glutMainLoop();

	return 0;
}

void init(void) {
	glClearColor(0.3, 0.3, 0.3, 0);
	gluOrtho2D(0, WIDTH, LENGTH, 0);
	load_csv("../maps/test.csv");
}

void loop(void) {
	if (key_q) {
		render_2d = !render_2d;
		key_q = 0;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	if (render_2d)
		map_draw();
	plr_update();
	if (render_2d)
		plr_draw();
	glutSwapBuffers();
	glutPostRedisplay();
}
