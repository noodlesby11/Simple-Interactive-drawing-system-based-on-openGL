#include<iostream>
#include<GL/glut.h>
#include "function.h"
using namespace std;

void ColorMenu(int value) {

    switch (value)
    {
    case 1:red = 1.0; green = 0.0; blue = 0.0; cout << "设置颜色为：红色" << endl; break;
    case 2:red = 0.0; green = 1.0; blue = 0.0; cout << "设置绘制图形为：绿色" << endl; break;
    case 3:red = 0.0; green = 0.0; blue = 1.0; cout << "设置绘制图形为：蓝色" << endl; break;
    case -1:red = 0.0; green = 0.0; blue = 0.0; cout << "设置绘制图形为：黑色" << endl; break;
    case 0:red = 1.0; green = 1.0; blue = 1.0; cout << "设置绘制图形为：白色" << endl; break;
    default:break;
    }
}

void GraphicMenu(int value) {
    graph = value;
    switch (value)
    {
    case 0:cout << "设置绘制图形为：点" << endl; break;
    case 1:cout << "设置绘制图形为：直线" << endl; break;
    case 2:cout << "设置绘制图形为：曲线" << endl; break;
    case 3:cout << "设置绘制图形为：多边形" << endl; break;
    case 4:cout << "设置绘制图形为：圆" << endl; break;
    case 5:cout << "设置绘制图形为：矩形" << endl; break;
    case 6:cout << "设置绘制图形为：三角形" << endl; break;
    default:
        break;
    }
}

void transform(int value) {
    switch (value)
    {
    case 1:translate = 1; cout << "目前为平移变换 参数：" << translate << endl; break;
    case 2:translate = 2; cout << "目前为旋转变换 参数：" << translate << endl; break;
    case 3:translate = 3; cout << "目前为缩放变换 参数：" << translate << endl; break;
    default:
        break;
    }
}

void sizeofpoint(int value) {
    if (value == 1) {
        cout << "画笔大小设置为：小" << endl;
        pointsize = 2;
    }
    else if (value == 2) {
        cout << "画笔大小设置为：中" << endl;
        pointsize = 6;
    }
    else if (value == 3) {
        cout << "当前画笔大小设置为：大" << endl;
        pointsize = 10;
    }
}

void myMenu(int value)
{
    if (value == 0)
    {
        cout << "退出程序" << endl;
        exit(0);
    }
    else if (value == 1) {
        cout << "开始屏幕裁剪" << endl;
        clip = true;
    }
    else if (value == -1) {
        cout << "屏幕已清空" << endl;
        memset(point, 0, sizeof(point)); pointnum = 0;
        memset(line, 0, sizeof(line)); linenum = 0;
        memset(rectangle, 0, sizeof(rectangle)); rectnum = 0;
        memset(circle, 0, sizeof(circle)); circlenum = 0;
        memset(triangle, 0, sizeof(triangle)); trianglenum = 0; trianglePoint = 0;
        memset(polygon, 0, sizeof(polygon)); memset(polygonPoint, 0, sizeof(polygonPoint)); polygonnum = 0;
        memset(curve, 0, sizeof(curve)); memset(curvePoint, 0, sizeof(curvePoint)); curvenum = 0;
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void CreateMyMenu() {
    int clear_menu = glutCreateMenu(ColorMenu);
    glutAddMenuEntry("black", -1);
    glutAddMenuEntry("white", 0);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);

    int graph_menu = glutCreateMenu(GraphicMenu);
    //Point,Straight line, curve, triangle, polygon, circle
    glutAddMenuEntry("Point", 0);
    glutAddMenuEntry("line", 1);
    glutAddMenuEntry("curve", 2);
    glutAddMenuEntry("triangle", 6);
    glutAddMenuEntry("rectangle", 5);
    glutAddMenuEntry("polygon", 3);
    glutAddMenuEntry("circle", 4);

    int transform_menu = glutCreateMenu(transform);
    glutAddMenuEntry("pan", 1);
    glutAddMenuEntry("rotate", 2);
    glutAddMenuEntry("scale", 3);

    int size_menu = glutCreateMenu(sizeofpoint);
    glutAddMenuEntry("small", 1);
    glutAddMenuEntry("medium", 2);
    glutAddMenuEntry("big", 3);

    //注册菜单回调函数
    glutCreateMenu(myMenu);
    glutAddSubMenu("Color", clear_menu);
    glutAddSubMenu("Graph", graph_menu);
    glutAddSubMenu("transform", transform_menu);
    glutAddSubMenu("pointsize", size_menu);
    glutAddMenuEntry("clip", 1);
    glutAddMenuEntry("clear", -1);
    glutAddMenuEntry("exit", 0);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}