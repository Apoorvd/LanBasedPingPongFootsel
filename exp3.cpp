#include <GL/gl.h>
#include <GL/glut.h>

void init(void){
        glClearColor(0.0,0.0,0.0,0.0);
        glShadeModel(GL_SMOOTH);
}

void display(void){
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3f(0.25,0.1,0.0);
                glColor3f(0.0,1.0,0.0);
                glVertex3f(0.75,0.1,0.0);
                glColor3f(0.0,0.0,1.0);
                glVertex3f(0.5,0.9,0.0);
        glEnd();
        glFlush();
}

int main(int argc,char **argv){
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_ALPHA|GLUT_DEPTH);
        glutInitWindowSize(640,480);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Output");
        init();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(0.0,1.0,0.0,2.0,-1.0,1.0);
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
}