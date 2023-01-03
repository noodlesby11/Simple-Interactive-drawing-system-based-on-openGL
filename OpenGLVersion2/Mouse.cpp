#include"function.h"

void pointmouse(int button, int state, int x, int y);
void linemouse(int button, int state, int x, int y);
void curvemouse(int button, int state, int x, int y);
void rectmouse(int button, int state, int x, int y);
void circlemouse(int button, int state, int x, int y);
void trianglemouse(int button, int state, int x, int y);
void polygonmouse(int button, int state, int x, int y);

void clipmouse(int button, int state, int x, int y);

void mousefunction(int button,int state,int x,int y) {
    if (clip) {
        clipmouse(button, state, x, y);
    }else if (ControlLock == -1) {
        switch (graph)
        {
        case 0: pointmouse(button, state, x, y); break;
        case 1: linemouse(button, state, x, y); break;
        case 2: curvemouse(button, state, x, y); break;
        case 3: polygonmouse(button, state, x, y); break;
        case 4: circlemouse(button, state, x, y); break;
        case 5: rectmouse(button, state, x, y); break;
        case 6: trianglemouse(button, state, x, y); break;
        default:
            break;
        }
    }else glutMotionFunc(PointMotion);
}

void pointmouse(int button, int state, int x, int y) {
    glutMotionFunc(PointMotion);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP )
    {
        point[pointnum].x = x;
        point[pointnum].y = Height - y;
        point[pointnum].pointsize = pointsize;
        point[pointnum].red = red;
        point[pointnum].green = green;
        point[pointnum].blue = blue;
        //cout << pointnum << "x:" << point[pointnum].x << "y:" << point[pointnum].y << "pointsize:" << point[pointnum].pointsize << endl;
        pointnum++;
        glutPostRedisplay();
    }
}

void linemouse(int button, int state, int x, int y) {
    glutMotionFunc(LineMotion);
    //鼠标左键按下——确定起始点
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        line[linenum][0].x = x;
        line[linenum][0].y = Height - y;
        line[linenum][0].pointsize = pointsize;
        line[linenum][0].red = red;
        line[linenum][0].green = green;
        line[linenum][0].blue = blue;
        
    }
    //鼠标左键松开——画最后一个顶点，画线结束
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        line[linenum][1].x = x;
        line[linenum][1].y = Height - y;
        line[linenum][1].pointsize = pointsize;
        line[linenum][1].blue = blue;
        line[linenum][1].green = green;
        line[linenum][1].blue = blue;
        linenum++;
        glutPostRedisplay();
    }
}

void rectmouse(int button, int state, int x, int y) {
    glutMotionFunc(RectangleMotion);
    //鼠标左键按下——确定第一个矩形对角点
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        rectangle[rectnum][0].x = x;
        rectangle[rectnum][0].y = Height - y;
        rectangle[rectnum][0].pointsize = pointsize;
        rectangle[rectnum][0].red = red;
        rectangle[rectnum][0].green = green;
        rectangle[rectnum][0].blue = blue;
    }
    //鼠标左键松开——画下一个对角点，将矩形个数加1，画线结束
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        rectangle[rectnum][1].x = x;
        rectangle[rectnum][1].y = Height - y;
        rectangle[rectnum][1].pointsize = pointsize;
        rectangle[rectnum][1].red = red;
        rectangle[rectnum][1].green = green;
        rectangle[rectnum][1].blue = blue;
        rectnum++;
        glutPostRedisplay();
    }
}

void circlemouse(int button, int state,int x,int y) {
    glutMotionFunc(CircleMotion);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        circle[circlenum][0].x = x;
        circle[circlenum][0].y = Height - y;
        circle[circlenum][0].pointsize = pointsize;
        circle[circlenum][0].red = red;
        circle[circlenum][0].green = green;
        circle[circlenum][0].blue = blue;
    }
    //鼠标左键松开——画下一个对角点，将矩形个数加1，画线结束
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        circle[circlenum][1].x = x;
        circle[circlenum][1].y = Height - y;
        circle[circlenum][1].pointsize = pointsize;
        circle[circlenum][1].red = red;
        circle[circlenum][1].green = green;
        circle[circlenum][1].blue = blue;
        circlenum++;
        glutPostRedisplay();
    }
}

void trianglemouse(int button, int state, int x, int y) {
    glutMotionFunc(TriangleMotion);

    if (trianglePoint == 0) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            triangle[trianglenum][0].x = x;
            triangle[trianglenum][0].y = Height - y;
            triangle[trianglenum][0].pointsize = pointsize;
            triangle[trianglenum][0].red = red;
            triangle[trianglenum][0].green = green;
            triangle[trianglenum][0].blue = blue;
            //cout << "setPoint:" << trianglePoint << endl;
            //cout << triangle[trianglenum][0].x << " " << triangle[trianglenum][0].y << endl;
            glutPostRedisplay();
        }
    }
    if (trianglePoint == 1) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            triangle[trianglenum][1].x = x;
            triangle[trianglenum][1].y = Height - y;
            triangle[trianglenum][1].pointsize = pointsize;
            triangle[trianglenum][1].red = red;
            triangle[trianglenum][1].green = green;
            triangle[trianglenum][1].blue = blue;
            //cout << "setPoint:" << trianglePoint << endl;
            //cout << triangle[trianglenum][1].x << " " << triangle[trianglenum][1].y << endl;
            trianglePoint++;
            glutPostRedisplay();
        }
    }
    if (trianglePoint == 2) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            triangle[trianglenum][2].x = x;
            triangle[trianglenum][2].y = Height - y;
            triangle[trianglenum][2].pointsize = pointsize;
            triangle[trianglenum][2].red = red;
            triangle[trianglenum][2].green = green;
            triangle[trianglenum][2].blue = blue;
            //cout << "setPoint:" << trianglePoint << endl;
            //cout << triangle[trianglenum][2].x << " " << triangle[trianglenum][2].y << endl;
            trianglePoint = 0;
            //cout << "setPoint:" << trianglePoint << endl;
            trianglenum++;
            glutPostRedisplay();
        }
    }

    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
        trianglePoint++;
    }
}

void curvemouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        curve[curvenum][curvePoint[curvenum]].x = x;
        curve[curvenum][curvePoint[curvenum]].y = Height - y;
        curve[curvenum][curvePoint[curvenum]].pointsize = pointsize;
        curve[curvenum][curvePoint[curvenum]].red = red;
        curve[curvenum][curvePoint[curvenum]].green = green;
        curve[curvenum][curvePoint[curvenum]].blue = blue;

        glutPostRedisplay();
        //cout << "第" << curvenum << "个曲线的第" << curvePoint[curvenum] << "个点" << endl;
    }
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
        curvePoint[curvenum]++;
        //cout << curvePoint[curvenum] << endl;
    }
}

void polygonmouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        polygon[polygonnum][polygonPoint[polygonnum]].x = x;
        polygon[polygonnum][polygonPoint[polygonnum]].y = Height - y;
        polygon[polygonnum][polygonPoint[polygonnum]].pointsize = pointsize;
        polygon[polygonnum][polygonPoint[polygonnum]].red = red;
        polygon[polygonnum][polygonPoint[polygonnum]].green = green;
        polygon[polygonnum][polygonPoint[polygonnum]].blue = blue;

        glutPostRedisplay();
        //cout << "第" << curvenum << "个曲线的第" << curvePoint[curvenum] << "个点" << endl;
    }
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
        polygonPoint[polygonnum]++;
        //cout << curvePoint[curvenum] << endl;
    }
}

void clipmouse(int button, int state, int x, int y) {
    glutMotionFunc(ClipMotion);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        clipPoints[0] = x;
        clipPoints[1] = Height - y;
        //cout << "一：" << x << " " << Height - y << endl;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        clipPoints[2] = x;
        clipPoints[3] = Height - y;
        //cout << "二：" << x << " " << Height - y << endl;
        glutPostRedisplay();
    }
}