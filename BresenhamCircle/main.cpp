
#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
void drawPixel(int x, int y)
{
    glLineWidth(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);

    glVertex2d(x, y);
    glEnd();
}

void drawCirclePoint(int xc, int yc, int x, int y)
{
    drawPixel(xc+x, yc+y);
    drawPixel(xc-x, yc+y);
    drawPixel(xc+x, yc-y);
    drawPixel(xc-x, yc-y);

    drawPixel(xc+y, yc+x);
    drawPixel(xc-y, yc+x);
    drawPixel(xc+y, yc-x);
    drawPixel(xc-y, yc-x);
}


void drawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    drawCirclePoint(xc, yc, x, y);

    int p = 1 - r;

    // For each pixel we will draw all eight pixels

    while(x < y)
    {
        x++;
        if(p <= 0)
        {
            p = p + (2*x + 1);
        }
        else
        {
            y--;
            p = p + (2*x) + 1 - (2*y);
        }
        drawCirclePoint(xc, yc, x, y);
        system("Color 06");
        printf("x = %d, y = %d, xc = %d, yc = %d\n", x, y, xc, yc);
    }
}

static void display(void)
{
    glPushMatrix();
    drawCircle(10, 10, 100);
    glPopMatrix();
    glutSwapBuffers();
    glFlush ();

}

int main()
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(600, 100);
    glutCreateWindow("Mid Point Circle");
    glClearColor(0, 0,0,0);
    glOrtho(-200, 200, -200, 200,-1, 1);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
