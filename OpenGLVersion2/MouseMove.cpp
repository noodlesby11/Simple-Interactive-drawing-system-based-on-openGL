#include"function.h"

void PointMotion(int x, int y) {}

void LineMotion(int x, int y)
{
    line[linenum][1].x = x;
    line[linenum][1].y = Height - y;
    glutPostRedisplay();
}

void RectangleMotion(int x, int y)
{
    rectangle[rectnum][1].x = x;
    rectangle[rectnum][1].y = Height - y;
    glutPostRedisplay();
}

void CircleMotion(int x, int y) 
{
    circle[circlenum][1].x = x;
    circle[circlenum][1].y = Height - y;
    glutPostRedisplay();
}

void  TriangleMotion(int x, int y) {
    if (trianglePoint == 2) {
        triangle[trianglenum][2].x = x;
        triangle[trianglenum][2].y = Height - y;
        glutPostRedisplay();
    }
}

void ClipMotion(int x, int y) {
    clipPoints[2] = x;
    clipPoints[3] = Height - y;
    glutPostRedisplay();
}