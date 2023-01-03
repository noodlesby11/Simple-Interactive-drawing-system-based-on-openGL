#include"function.h"
int Width = 1000, Height = 700;
int ControlLock = 1;
float red = 0.0f, green = 0.0f, blue = 0.0f;
int graph = 0;
int pointsize = 2;
bool clip = false;
int clipPoints[4];

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);  
	glMatrixMode(GL_PROJECTION);       
	gluOrtho2D(0.0, Width, 0.0, Height);  //设置窗口坐标范围
	cout << "*欢迎使用，按F1解锁控制" << endl;
	cout << "*当绘制多边形，曲线时按中键再按左键确定下一个点" << endl;
	cout << "*使用裁剪时，先将鼠标从欲裁剪区域左上拖动至欲裁剪区域右下，后按下f进行裁剪" << endl;
	cout << "*在绘制多边形和曲线时，当需要确定图形已经绘制完成不需要增加新的控制点，可以按下空格进行确定。" << endl;
	cout << "*可以用菜单选择二维变换类型；也可q键切换至平移变换，上下左右键控制；w键切换至旋转变换，上下键进行控制；e键切换至缩放变换，上下键进行控制" << endl;
	cout << endl;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);                        
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowPosition(150, 50); 
	glutInitWindowSize(Width, Height);
	glutCreateWindow("简易交互绘图系统");

	init();                          
	glClear(GL_COLOR_BUFFER_BIT);

    //建立菜单
    CreateMyMenu();

    //反走样
    glEnable(GL_LINE_SMOOTH);//线反走样
	glEnable(GL_POINT_SMOOTH);//点反走样
	glEnable(GL_LINE_SMOOTH);//线反走样
	glEnable(GL_POLYGON_SMOOTH);//多边形反走样
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//开启alpha混合

    glutDisplayFunc(display);
	glutMouseFunc(mousefunction);

	glutSpecialFunc(ControlFunc);
	glutKeyboardFunc(keyfuction);
	glutMainLoop();// 不停循环直到退出
	return 0;
}
