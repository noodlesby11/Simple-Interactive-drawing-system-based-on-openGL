#include"function.h"

void polygonKeyBorad(unsigned char key, int x, int y);
void curveKeyBorad(unsigned char key, int x, int y);

void keyfuction(unsigned char key,int x,int y) {
	if (ControlLock == -1) {
		switch (graph)
		{
        case 2: curveKeyBorad(key, x, y);
		case 3:	polygonKeyBorad(key, x, y);
		default:
			break;
		}
	}
	if (key == 102) {//f
		clipbegin = true;
		glutPostRedisplay();
	}
	if (key == 113) {//q
		translate = 1;
		cout << "目前为平移变换 参数："<< translate << endl;
	}
	if (key == 119) {//w
		translate = 2;
		cout << "目前为旋转变换 参数："<< translate << endl;
	}
	if (key == 101) {//e
		translate = 3;
		cout << "目前为缩放变换 参数："<< translate << endl;
	}
}

void curveKeyBorad(unsigned char key, int x, int y) {
	if (key == 32) {
		curvenum++;
		cout << "该图形绘制完成" << endl;
		//cout << " 曲线数为：" << curvenum << endl;
	}
}

void polygonKeyBorad(unsigned char key, int x, int y) {
	if (key == 32) {
		polygonnum++;
		cout << "该图形绘制完成" << endl;
	}
}

void ControlFunc(int key, int x, int y) {
	if (key == GLUT_KEY_F1) {
		ControlLock = 0 - ControlLock;
		if (ControlLock == 1) {
			cout << "控制已锁定" << endl;
			glutMotionFunc(PointMotion);
		}
		else cout << "控制已解锁" << endl;
	}
	translateKeyBorad(key, x, y);
}

void translateKeyBorad(int key, int x, int y) {
	switch (translate)
	{
	case 1: {
		if (key== GLUT_KEY_UP) {
			ypan++;
			cout << "水平方向平移：" << xpan << " ,竖直方向平移：" << ypan << endl;
		}
		else if (key == GLUT_KEY_DOWN) {
			ypan--;
			cout << "水平方向平移：" << xpan << " ,竖直方向平移：" << ypan << endl;
		}
		else if (key == GLUT_KEY_LEFT) {
			xpan--;
			cout << "水平方向平移：" << xpan << " ,竖直方向平移：" << ypan << endl;
		}
		else if (key == GLUT_KEY_RIGHT) {
			xpan++;
			cout << "水平方向平移：" << xpan << " ,竖直方向平移：" << ypan << endl;
		}
		glutPostRedisplay();
		break;
	}
	case 2: {
		if (key == GLUT_KEY_UP)
		{
			angle++;
			cout << "旋转角度为：" << angle << endl;
		}
		else if (key == GLUT_KEY_DOWN) 
		{
			angle--;
			cout << "旋转角度为：" << angle << endl;
		}
		glutPostRedisplay();
		break;
	}
	case 3: {
		if (key == GLUT_KEY_UP) {
			scalef+=0.2;
			cout << "缩放倍数为；" << scalef << endl;
		}
		else if (key == GLUT_KEY_DOWN) {
			if(scalef-0.2 > 0)
				scalef -= 0.2;
			else {
				scalef == 0.0;
			}
			cout << "缩放倍数为；" << scalef << "(缩放倍数最小为0)" << endl;
		}
		glutPostRedisplay();
		break;
	}
	default:
		break;
	}
}