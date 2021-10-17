#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>

void drawSinglePixel(int x, int y)
{
    glPointSize(5.0);
    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(x, y);
    glEnd();
}



void drawPointInCircle(int x, int y)
{
    drawSinglePixel(+x, +y);
    drawSinglePixel(-x, +y);
    drawSinglePixel(+x, -y);
    drawSinglePixel(-x, -y);

    drawSinglePixel(+y, +x);
    drawSinglePixel(-y, +x);
    drawSinglePixel(+y, -x);
    drawSinglePixel(-y, -x);
}

void drawCircle(int r)
{
    int x = 0;
    int y = r;
    int d = 3 -  2 * r;

    drawPointInCircle(x, y);
    while(y > x) {
        x++;
        if(d > 0) {
            y--;
            d = d + 4 * (x-y) + 10;
        }else {
            d = d + 4 * x + 6;
        }
        drawSinglePixel(x, y);
        printf("%d, %d\n", x, y);
    }


}

static void display()
{
    glPushMatrix();
    drawCircle(10);
    glPopMatrix();
    glutSwapBuffers();
}

int main()
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle Draw");
    glClearColor(0, 0, 0, 0);
    glOrtho(-200, 200, -200, 200, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
