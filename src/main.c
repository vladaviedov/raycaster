#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "input.h"
#include "player.h"

#define WIDTH 512
#define LENGTH 512
#define WIN_NAME "rc"

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
}

void loop(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	plr_update();
	plr_draw();
	glutSwapBuffers();
	glutPostRedisplay();
}
