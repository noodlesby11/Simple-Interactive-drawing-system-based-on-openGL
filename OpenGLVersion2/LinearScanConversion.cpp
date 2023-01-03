#include<GL/glut.h>
#include"function.h"
void putpixel(int x, int y) {
	glPointSize(pointsize);
	glColor3f(red, green, blue);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void BresenhamLine(int x0, int y0, int x1, int y1) {
	int dx, dy, d, UpIncre, DownIncre, x, y;
	float k = abs((y1 - y0) / (x1 - x0));
	int p;
	if (k > 1) {
		p = x0;
		x0 = y0;
		y0 = p;

		p = x1;
		x1 = y1;
		y1 = p;
	}

	if (x0 > x1) {
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	x = x0; y = y0;
	dx = x1 - x0; dy = y1 - y0; d = dx - 2 * dy;
	UpIncre = 2 * dx - 2 * dy;
	DownIncre = -2 * dy;
	while (x <= x1)
	{
		if(k<1)
			putpixel(x , y );
		else
			putpixel(y , x );
		x++;
		if (d < 0) {
			y++;
			d += UpIncre;
		}
		else {
			d += DownIncre;
		}
	}
}
void DDALine(int x0, int y0, int x1, int y1) {
    glPointSize(pointsize);
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);

	int k, i;
	float x, y, dx, dy;
	k = abs(x1 - x0);
	if (abs(y1 - y0) > k)
		k = abs(y1 - y0);
	//直线被划分为每一小段的长度
	dx = float(x1 - x0) / k;
	dy = float(y1 - y0) / k;
	x = float(x0);
	y = float(y0);
	for (i = 0; i < k; i++) {
		glVertex2i(int(x + 0.5), int(y + 0.5));
		x = x + dx;
		y = y + dy;
	}
    glEnd();
    glFlush();
}

//辅助画圆算法
void CirclePoints(int x, int y, int x0, int y0)
{
    glVertex2i(x + x0, y + y0); glVertex2i(y + x0, x + y0);
    glVertex2i(-x + x0, y + y0); glVertex2i(y + x0, -x + y0);
    glVertex2i(x + x0, -y + y0); glVertex2i(-y + x0, x + y0);
    glVertex2i(-x + x0, -y + y0); glVertex2i(-y + x0, -x + y0);
}


void BresenhamCircle(int x0, int y0, int r)
{
    int x = 0, y = r;
    int delta, delta1, delta2;
    int direction; //表明选取的点，1为H,2为D，3为V
    delta = 2 * (1 - r); //初始值
    int Limit = 0;

    while (y >= Limit) {
        glBegin(GL_POINTS);
        CirclePoints(x, y, x0, y0);
        if (delta < 0) {
            delta1 = 2 * (delta + y) - 1;
            if (delta1 < 0) { //取H点
                direction = 1;
            }
            else direction = 2; //取D点
        }
        else if (delta > 0) {
            delta2 = 2 * (delta - x) - 1;
            if (delta2 < 0) {
                direction = 2; //取D点
            }
            else
                direction = 3; //取V点
        }
        else
            direction = 2;//取D点	

        switch (direction)
        {
        case 1:
            x++;
            delta += 2 * x + 1;
            break;
        case 2:
            x++; y--;
            delta += 2 * x - 2 * y + 1;
            break;
        case 3:
            y--;
            delta += -2 * y + 1;
            break;
        }
    }

    glEnd();
}

void MidBresenhamCircle(int r) {
	int x, y, d;
	x = 0; y = r; d = r - 1;
	while (x < y) {
		putpixel(x, y);
		putpixel(y , x );
		putpixel(-y , x );
		putpixel(-x , y );
		putpixel(-x , -y );
		putpixel(-y , -x );
		putpixel(y , -x );
		putpixel(x , -y );
		if (d < 0) {
			d += 2 * x + 3;
		}
		else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}