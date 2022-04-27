#include <GL/glut.h>
#include <cmath>

double katGlowny = 0.0;

float merkuryX = sin(katGlowny + 45) * 0.15;
float merkuryY = cos(katGlowny + 45) * 0.15;
float merkuryR = 0.01;

float wenusX = sin(katGlowny + 90) * 0.25;
float wenusY = cos(katGlowny + 90) * 0.25;
float wenusR = 0.02;

float ziemiaX = sin(katGlowny + 135) * 0.35;
float ziemiaY = cos(katGlowny + 135) * 0.35;
float ziemiaR = 0.02;

float marsX = sin(katGlowny + 180) * 0.45;
float marsY = cos(katGlowny + 180) * 0.45;
float marsR = 0.02;

float jowiszX = sin(katGlowny + 225) * 0.55;
float jowiszY = cos(katGlowny + 225) * 0.55;
float jowiszR = 0.04;

float saturnX = sin(katGlowny + 270) * 0.65;
float saturnY = cos(katGlowny + 270) * 0.65;
float saturnR = 0.038;

float uranX = sin(katGlowny + 315) * 0.75;
float uranY = cos(katGlowny + 315) * 0.75;
float uranR = 0.03;

float neptunX = sin(katGlowny) * 0.85;
float neptunY = cos(katGlowny) * 0.85;
float neptunR = 0.03;

void nowaPlaneta(float promien, float wspSrodkaX, float wspSrodkaY, float czerwony, float zielony, float niebieski) {
	float p = 0.0;
	float q = 0.0;
	double kat = 0.0;

	glPushMatrix();
	glTranslatef(wspSrodkaX, wspSrodkaY, 0.0f);
	glColor3f(czerwony, zielony, niebieski);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(p, q);
	while (true) {
		if (kat <= 360) {
			p = 0.0 + sin(kat) * promien;
			q = 0.0 + cos(kat) * promien;
			glVertex2f(p, q);
		}
		else break;
		kat += 0.1;
	}
	glEnd();
	glPopMatrix();
}

void orbita(float promien) {
	float p = 0.0;
	float q = 0.0;
	double kat = 0.0;
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
	while (true) {
		if (kat <= 360) {
			p = 0.0 + sin(kat) * promien;
			q = 0.0 + cos(kat) * promien;
			glVertex2f(p, q);
		}
		else break;
		kat += 0.1;
	}
	glEnd();
	glPopMatrix();
}

void orbitaPlanety(float promien, float wspX, float wspY) {
	float p = 0.0;
	float q = 0.0;
	double kat = 0.0;
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
	while (true) {
		if (kat <= 360) {
			p = wspX + sin(kat) * promien;
			q = wspY + cos(kat) * promien;
			glVertex2f(p, q);
		}
		else break;
		kat += 0.1;
	}
	glEnd();
	glPopMatrix();
}

void inicjalizacja() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void wyswietlanko() {
	//slonce
	nowaPlaneta(0.08, 0.0, 0.0, 1.0, 0.9, 0.0);

	//Merkury
	orbita(0.15);
	nowaPlaneta(merkuryR, merkuryX, merkuryY, 1.0, 1.0, 1.0);

	//Wenus
	orbita(0.25);
	nowaPlaneta(wenusR, wenusX, wenusY, 1.0, 0.9, 0.3);

	//Ziemia
	orbita(0.35);
	nowaPlaneta(ziemiaR, ziemiaX, ziemiaY, 0.1, 0.3, 0.7);

	//Mars
	orbita(0.45);
	nowaPlaneta(marsR, marsX, marsY, 1.0, 0.35, 0.0);

	//Jowisz
	orbita(0.55);
	nowaPlaneta(jowiszR, jowiszX, jowiszY, 1.0, 0.6, 0.0);

	//Saturn
	orbita(0.65);
	orbitaPlanety(0.05, saturnX, saturnY);
	nowaPlaneta(saturnR, saturnX, saturnY, 1.0, 0.8, 0.0);

	//Uran
	orbita(0.75);
	orbitaPlanety(0.04, uranX, uranY);
	nowaPlaneta(uranR, uranX, uranY, 0.0, 0.9, 1.0);

	//Neptun
	orbita(0.85);
	orbitaPlanety(0.04, neptunX, neptunY);
	nowaPlaneta(neptunR, neptunX, neptunY, 0.0, 0.7, 1.0);

	glFlush();
	inicjalizacja();
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, timer, 0);
	if (katGlowny <= 360) {
		merkuryX = sin(katGlowny + 45) * 0.15;
		merkuryY = cos(katGlowny + 45) * 0.15;

		wenusX = sin(katGlowny + 90) * 0.25;
		wenusY = cos(katGlowny + 90) * 0.25;

		ziemiaX = sin(katGlowny + 135) * 0.35;
		ziemiaY = cos(katGlowny + 135) * 0.35;

		marsX = sin(katGlowny + 180) * 0.45;
		marsY = cos(katGlowny + 180) * 0.45;

		jowiszX = sin(katGlowny + 225) * 0.55;
		jowiszY = cos(katGlowny + 225) * 0.55;

		saturnX = sin(katGlowny + 270) * 0.65;
		saturnY = cos(katGlowny + 270) * 0.65;

		uranX = sin(katGlowny + 315) * 0.75;
		uranY = cos(katGlowny + 315) * 0.75;

		neptunX = sin(katGlowny) * 0.85;
		neptunY = cos(katGlowny) * 0.85;
		katGlowny += 0.005;
	}
	else katGlowny = 0.0;
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	int x = 800;
	int y = x;
	glutInitWindowSize(x, y);
	glutInitWindowPosition((int)(glutGet(GLUT_SCREEN_WIDTH) - x) / 2, (int)(glutGet(GLUT_SCREEN_HEIGHT) - y) / 2);
	glutCreateWindow("Uklad sloneczny");
	inicjalizacja();
	glutDisplayFunc(wyswietlanko);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}