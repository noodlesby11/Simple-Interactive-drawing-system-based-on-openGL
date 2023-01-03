#include"function.h"
int linenum = 0;
int rectnum = 0;
int pointnum = 0;
int circlenum = 0;
int trianglenum = 0, trianglePoint = 0;
int polygonnum = 0;
int polygonPoint[50];
bool clipbegin = false;

float xpan = 0.0;
float ypan = 0.0;

float angle = 0.0;

float scalef = 1.0;

GLintPoint point[MAXGRAPH];
GLintPoint line[MAXGRAPH][2];
GLintPoint rectangle[MAXGRAPH][2];
GLintPoint circle[MAXGRAPH][2];
GLintPoint triangle[MAXGRAPH][3];
GLintPoint polygon[MAXGRAPH][50];

int translate = 1;

void drawpoint() {
    for (int i = 0; i < pointnum; i++) {
        glPointSize(point[i].pointsize);
        glColor3f(point[i].red, point[i].green, point[i].blue);
        glBegin(GL_POINTS);
        glVertex2i(point[i].x, point[i].y);
        glEnd();
    }
}

void drawlines() {
    for (int i = 0; i <= linenum; i++) {
        glLineWidth(line[i][0].pointsize);
        glColor3f(line[i][0].red, line[i][0].green, line[i][0].blue);
        glBegin(GL_LINES);
        glVertex2f(line[i][0].x, line[i][0].y);
        glVertex2f(line[i][1].x, line[i][1].y);
        glEnd();
    }
}

void drawRects() {
    for (int i = 0; i <= rectnum; i++) {
        glLineWidth(rectangle[i][0].pointsize);
        glColor3f(rectangle[i][0].red, rectangle[i][0].green, rectangle[i][0].blue);
        glBegin(GL_LINE_LOOP);
        glVertex2f(rectangle[i][0].x, rectangle[i][0].y);		//x0,y0
        glVertex2f(rectangle[i][0].x, rectangle[i][1].y);		//x0,y1
        glVertex2f(rectangle[i][1].x, rectangle[i][1].y);		//x1,y1
        glVertex2f(rectangle[i][1].x, rectangle[i][0].y);		//x1,y0
        glEnd();
    }
}

void drawCircle() {
    for (int i = 0; i <= circlenum; i++) {
        glPointSize(circle[i][0].pointsize);
        glColor3f(circle[i][0].red, circle[i][0].green, circle[i][0].blue);
        int r = sqrt((pow(circle[i][0].x- circle[i][1].x,2)+ pow(circle[i][0].y - circle[i][1].y, 2)));
        BresenhamCircle(circle[i][0].x, circle[i][0].y, r);
    }
}

void drawTriangle() {
    for (int i = 0; i <= trianglenum; i++) {
        glLineWidth(triangle[i][0].pointsize);
        glColor3f(triangle[i][0].red, triangle[i][0].green, triangle[i][0].blue);
        glBegin(GL_LINE_LOOP);
        if (triangle[i][0].x != 0 || triangle[i][0].y != 0)
            glVertex2f(triangle[i][0].x, triangle[i][0].y);

        if (triangle[i][1].x != 0 || triangle[i][1].y != 0)
            glVertex2f(triangle[i][1].x, triangle[i][1].y);

        if(triangle[i][2].x!=0 || triangle[i][2].y!=0)
            glVertex2f(triangle[i][2].x, triangle[i][2].y);
        glEnd();
    }
}

void drawPolygon() {
    for (int i = 0; i <= polygonnum; i++) {
        glLineWidth(polygon[i][0].pointsize);
        glColor3f(polygon[i][0].red, polygon[i][0].green, polygon[i][0].blue);
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j <= polygonPoint[i]; j++) {
            glVertex2i(polygon[i][j].x, polygon[i][j].y);
        }
        glEnd();
    }
}

void drawCurve() {
    for (int i = 0; i <= curvenum; i++) {
        if (i == curvenum) {
            glBegin(GL_LINE_STRIP);	//绘制控制多边形
            for (GLint j = 0; j <= curvePoint[i]; j++)
            {
                glColor3f(1.0, 0.0, 0.0);
                glVertex2f(curve[i][j].x, curve[i][j].y);
            }
        }
	    glEnd();
        glPointSize(curve[i][0].pointsize);
        glColor3f(curve[i][0].red, curve[i][0].green, curve[i][0].blue);
        BezierCurve(5000, curvePoint[i]+1,curve,i);
    }
}

void RenderScene() {
    if (clipbegin) {
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

        glScissor(0, 0, clipPoints[0], Height);
        glEnable(GL_SCISSOR_TEST);
        glClear(GL_COLOR_BUFFER_BIT);

        glScissor(clipPoints[2], 0, Width, Height);
        glEnable(GL_SCISSOR_TEST);
        glClear(GL_COLOR_BUFFER_BIT);

        glScissor(clipPoints[0], 0, clipPoints[2]- clipPoints[0], clipPoints[3]);
        glEnable(GL_SCISSOR_TEST);
        glClear(GL_COLOR_BUFFER_BIT);

        glScissor(clipPoints[0], clipPoints[1], clipPoints[2] - clipPoints[0], Height);
        glEnable(GL_SCISSOR_TEST);
        glClear(GL_COLOR_BUFFER_BIT);

        glDisable(GL_SCISSOR_TEST);
        glutPostRedisplay();
    }
}

void transform() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(xpan, ypan, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scalef, scalef, scalef);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    transform();
    drawlines();
    drawRects();
    drawpoint();
    drawCircle();
    drawTriangle();
    drawCurve();
    drawPolygon();
    RenderScene();
    glutSwapBuffers();
}