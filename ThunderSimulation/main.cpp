#include "Laplace.h"
#include "Shader.h"
#include "Display.h"
#include "Global.h"
#include "Jittering.h"
#include "Surface.h"
#include "Chanel.h"
#include "LightningRod.h"

#include <iostream>
#include <Windows.h>
#include "GL/glew.h"
#include "GL/glut.h"

using namespace std;

extern const short int index;
double lattice[index + 1][index + 1] = {0};
double mainChanel[index + 1][index + 1] = {0};
double mainChanelPos[index * index/2][2] = {0};
extern int order;
extern int w = 512;
extern int h = 512;

Laplace laplace(0.5, 3.3);
Rod* rod = new Rod(index / 2);
Thunder* thunder = new Thunder();
Positive* positive = new Positive();
Negative* negative = new Negative();
STATE state;
bool mouseState = false;
unsigned int count = 0;

void KeyboardInput(unsigned char key, int x, int y) {
	switch (key) {
	// J : 지터링 샘플링
	case 'j':
		Jittering(laplace.order, mainChanelPos,w,h);
		break;
	// R : 기본 전위값 설정 및 초기화
	case 'r':
		laplace = Surface(laplace, 1, 1, lattice, mainChanelPos);
		cout << "<Surfacemapping>" << endl;
		for (int i = 0; i <= index; i++) {
			for (int j = 0; j <= index; j++) {
				printf("%.2f ", floor(lattice[i][j] * 100) / 100);
			}
			cout << endl;
		}
		cout << endl;

		rod->state = false;//피뢰침 초기화
		break;
	// 1 : 번개 시뮬레이션 디스플레이
	case '1': 
		state = THUNER;
		break;
	// 2 : 전위 값 디스플레이
	case '2': 
		state = POSITIVE;
		break;
	// 3 : Negative 전위 값 디스플레이
	case '3':
		state = NEGATIVE;
		break;
	// V : InterpolationValue set
	case 'v':
		laplace = InterpolationValue(laplace, lattice);
		break;
	// S : Interpolation set
	case 's':
		for (int i = 0; i < index; i++) {
			laplace = InterpolationHeight(laplace, lattice);
			laplace = InterpolationWidth(laplace, lattice);
		}
		break;
	// C : 다음 채널 선택
	case 'c':
		laplace = MainChanel(laplace, lattice, mainChanelPos);
		break;
	// SPACEBAR : 전위값 설정 및 진행
	case ' ':
		InterpolationValue(laplace,lattice);
		for (int i = 0; i < index; i++) {
			laplace = InterpolationHeight(laplace, lattice);
			laplace = InterpolationWidth(laplace, lattice);
		}
		laplace = MainChanel(laplace, lattice, mainChanelPos);
		break;
	// L : 피뢰침 설정
	case 'l':
		rod -> LightningRod(lattice);
		rod->state = !rod->state;
		break;
	// P : 현재 전위값 수치 출력
	case 'p':
		cout << "<Lattice>" << endl;
		for (int i = 0; i <= index; i++) {
			for (int j = 0; j <= index; j++) {
				printf("%.2f ", lattice[i][j]);
			}
			cout << endl;
		}
		break;
	// Q : InterpolationValue set
	case 'q':
		InterpolationValue(laplace,lattice);
		for (int i = 0; i < index; i++) {
			laplace = InterpolationHeight(laplace, lattice);
			laplace = InterpolationWidth(laplace, lattice);
		}
		break;
	}
}

void MouseClick(int button, int _state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON&& _state == GLUT_DOWN && !(state == THUNER)) {
		mouseState = true;
		if (x > 0)x = x / (w / index);
		if (y > 0)y = y / (h / index);
		lattice[y][x] = 0;
	}
	else if (button == GLUT_LEFT_BUTTON && _state == GLUT_UP) {
		mouseState = false;
	}
}

void MouseMove(int x, int y){
	if (mouseState) {
		if(x>0)x = x /  (w/index);
		if(y>0)y = y / (h/index);
		lattice[y][x] = 0;
	}
}

void Reshape(int width, int height) {
	if (height == 0)h = 1;

	float ratio = 1.0f * width / height;
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45, ratio, 1, 100);
	glMatrixMode(GL_MODELVIEW);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (state)
	{
	case THUNER:
		thunder->Display(laplace.order, mainChanelPos);
		if(rod->state)rod->LightningRodDisplay();
		break; 
	case POSITIVE:
		positive->Display(lattice);
		break;
	case NEGATIVE:
		negative->Display(lattice);
	}

	glFlush();
	glutSwapBuffers();
}

int glutMain(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(w,h);
	glutCreateWindow("ThunderSimulation");
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutDisplayFunc(Display);
	//glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardInput);
	glutMouseFunc(MouseClick);
	glutMotionFunc(MouseMove);
	glutIdleFunc(Display);

	glutMainLoop();

	return 0;
}

int main(int argc, char *argv[]) {

	glutMain(argc, argv);
	return 0;
}