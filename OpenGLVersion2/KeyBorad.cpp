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
		cout << "ĿǰΪƽ�Ʊ任 ������"<< translate << endl;
	}
	if (key == 119) {//w
		translate = 2;
		cout << "ĿǰΪ��ת�任 ������"<< translate << endl;
	}
	if (key == 101) {//e
		translate = 3;
		cout << "ĿǰΪ���ű任 ������"<< translate << endl;
	}
}

void curveKeyBorad(unsigned char key, int x, int y) {
	if (key == 32) {
		curvenum++;
		cout << "��ͼ�λ������" << endl;
		//cout << " ������Ϊ��" << curvenum << endl;
	}
}

void polygonKeyBorad(unsigned char key, int x, int y) {
	if (key == 32) {
		polygonnum++;
		cout << "��ͼ�λ������" << endl;
	}
}

void ControlFunc(int key, int x, int y) {
	if (key == GLUT_KEY_F1) {
		ControlLock = 0 - ControlLock;
		if (ControlLock == 1) {
			cout << "����������" << endl;
			glutMotionFunc(PointMotion);
		}
		else cout << "�����ѽ���" << endl;
	}
	translateKeyBorad(key, x, y);
}

void translateKeyBorad(int key, int x, int y) {
	switch (translate)
	{
	case 1: {
		if (key== GLUT_KEY_UP) {
			ypan++;
			cout << "ˮƽ����ƽ�ƣ�" << xpan << " ,��ֱ����ƽ�ƣ�" << ypan << endl;
		}
		else if (key == GLUT_KEY_DOWN) {
			ypan--;
			cout << "ˮƽ����ƽ�ƣ�" << xpan << " ,��ֱ����ƽ�ƣ�" << ypan << endl;
		}
		else if (key == GLUT_KEY_LEFT) {
			xpan--;
			cout << "ˮƽ����ƽ�ƣ�" << xpan << " ,��ֱ����ƽ�ƣ�" << ypan << endl;
		}
		else if (key == GLUT_KEY_RIGHT) {
			xpan++;
			cout << "ˮƽ����ƽ�ƣ�" << xpan << " ,��ֱ����ƽ�ƣ�" << ypan << endl;
		}
		glutPostRedisplay();
		break;
	}
	case 2: {
		if (key == GLUT_KEY_UP)
		{
			angle++;
			cout << "��ת�Ƕ�Ϊ��" << angle << endl;
		}
		else if (key == GLUT_KEY_DOWN) 
		{
			angle--;
			cout << "��ת�Ƕ�Ϊ��" << angle << endl;
		}
		glutPostRedisplay();
		break;
	}
	case 3: {
		if (key == GLUT_KEY_UP) {
			scalef+=0.2;
			cout << "���ű���Ϊ��" << scalef << endl;
		}
		else if (key == GLUT_KEY_DOWN) {
			if(scalef-0.2 > 0)
				scalef -= 0.2;
			else {
				scalef == 0.0;
			}
			cout << "���ű���Ϊ��" << scalef << "(���ű�����СΪ0)" << endl;
		}
		glutPostRedisplay();
		break;
	}
	default:
		break;
	}
}