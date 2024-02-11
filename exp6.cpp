#include <GL/glut.h>
#include <stdio.h>

int x1, y_1, x2, y2;
void draw_pixel(int x, int y);
void Bresenham(int x1, int x2, int y_1, int y2) {
	int dx, dy, i, e;
	int xi=1, yi=1, xi1, yi1;
	int x,y;

	dx = x2-x1;
	dy = y2-y_1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	if (x2 < x1) xi = -1;
	if (y2 < y_1) yi = -1;
	x = x1; y = y_1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		xi1 = 2*(dy-dx);
		yi1 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += yi;
				e += xi1;
			}
			else
				e += yi1;
			x += xi;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		xi1 = 2*(dx-dy);
		yi1 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += xi;
				e += xi1;
			}
			else
				e += yi1;
			y += yi;
			draw_pixel(x, y);
		}
	}
}

void myDisplay() {
	Bresenham(x1, x2, y_1, y2);
	glFlush();
}

void Init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
int main(int argc, char **argv) {

	printf( "Enter (x1, y_1, x2, y2)\n");
	scanf("%d %d %d %d", &x1, &y_1, &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	Init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}