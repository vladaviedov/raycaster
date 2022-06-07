#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "config.h"
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
	init();

	glutDisplayFunc(&loop);
	glutKeyboardFunc(&i_keydown);
	glutKeyboardUpFunc(&i_keyup);
	glutMainLoop();

	return 0;
}

void init(void) {
	glClearColor(0.3, 0.3, 0.3, 0);
	gluOrtho2D(0, WIDTH, LENGTH, 0);
	load_csv("../maps/test.csv");
}

void loop(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	map_draw();
	plr_update();
	plr_draw();
	glutSwapBuffers();
	glutPostRedisplay();
}
