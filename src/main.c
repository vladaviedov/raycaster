#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

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
	init();

	glutDisplayFunc(&loop);
	glutMainLoop();

	return 0;
}

void init(void) {
	glClearColor(0.3, 0.3, 0.3, 0);
	gluOrtho2D(0, WIDTH, LENGTH, 0);
}

void loop(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glutSwapBuffers();
}
