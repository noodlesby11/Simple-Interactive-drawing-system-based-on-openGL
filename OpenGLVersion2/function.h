#pragma once
#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

extern int Width ;
extern int Height ;
extern int ControlLock; //-1为可以进行绘画，1为不可以
extern float red , green, blue;
extern int graph;
extern int pointsize;
extern bool clip;
extern int clipPoints[4];
extern bool clipbegin;
//display
#define MAXGRAPH 1000				//图形的最大数量
extern struct GLintPoint {		//矩形结构
    int x, y;
    int pointsize;
    float red, green, blue;
};
void display(void);

extern struct GLintPoint point[MAXGRAPH];
extern int pointnum;

extern GLintPoint line[MAXGRAPH][2];
extern int linenum;


extern struct GLintPoint rectangle[MAXGRAPH][2];
extern int rectnum ;

extern struct GLintPoint circle[MAXGRAPH][2];
extern int circlenum;

extern GLintPoint triangle[MAXGRAPH][3];
extern int trianglenum;
extern int trianglePoint;

extern GLintPoint polygon[MAXGRAPH][50];
extern int polygonnum;
extern int polygonPoint[50];

extern int translate ;

extern float xpan ;
extern float ypan ;
extern float angle ;
extern float scalef ;
//MouseMove
void PointMotion(int x, int y);
void LineMotion(int x, int y);
void RectangleMotion(int x, int y);
void CircleMotion(int x, int y);
void TriangleMotion(int x, int y);
void ClipMotion(int x, int y);
//直线扫描转换
void putpixel(int x, int y);
void BresenhamLine(int x0, int y0, int x1, int y1);
void DDALine(int x0, int y0, int x1, int y1);
void MidBresenhamCircle(int r);
void BresenhamCircle(int x0, int y0, int r);
//贝塞尔曲线
extern class Pt3D {
public:
	GLfloat x, y;
	int pointsize;
	float red, green, blue;
};
extern Pt3D curve[MAXGRAPH][20];
extern int curvenum;
extern int curvePoint[MAXGRAPH];
void BezierCurve(GLint m, GLint ControlN, Pt3D ControlP[][20], int i);
//菜单
void CreateMyMenu();
//鼠标
void mousefunction(int button, int state, int x, int y);
//键盘
void ControlFunc(int key, int x, int y);
void keyfuction(unsigned char key, int x, int y);   
void translateKeyBorad(int key, int x, int y);