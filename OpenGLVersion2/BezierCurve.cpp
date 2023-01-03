#include<stdlib.h>
#include"function.h"
//�����ά���������ݽṹ 
Pt3D curve[MAXGRAPH][20];
int curvenum = 0;
int curvePoint[MAXGRAPH];

//�������ʽ��ϵ��
void GetCnk(GLint n, GLint* c) {
	GLint i, k;
	for (k = 0; k <= n; k++)
	{
		c[k] = 1;
		for ( i = n; i >= k+1; i--)
		{
			c[k] = c[k] * i;
		}
		for ( i = n-k; i >=2; i--)
		{
			c[k] = c[k] / i;
		}
	}
}
//���㱴���������ϵ������
void GetPointPr(GLint* c, GLfloat t, Pt3D* Pt, int ControlN, Pt3D ControlP[][20], int i) {
	GLint k, n = ControlN - 1;
	GLfloat Bernstein;
	Pt->x = 0.0; Pt->y = 0.0;
	for (k = 0; k < ControlN; k++) {
		Bernstein = c[k] * pow(t, k) * pow(1 - t, n - k);
		Pt->x += ControlP[i][k].x * Bernstein;
		Pt->y += ControlP[i][k].y * Bernstein;
	}
}
//���ݿ��Ƶ��������ϵ�m����
void BezierCurve(GLint m, GLint ControlN, Pt3D ControlP[][20], int i) {
	GLint* C, j;
	Pt3D CurvePt;

	C = new GLint[ControlN];
	GetCnk(ControlN - 1, C);

	glBegin(GL_POINTS);
	for (j = 0; j <= m; j++) {
		GetPointPr(C, (GLfloat)j / (GLfloat)m, &CurvePt, ControlN, ControlP, i);
		glVertex2f(CurvePt.x, CurvePt.y);
	}
	glEnd();
	delete[] C;
}