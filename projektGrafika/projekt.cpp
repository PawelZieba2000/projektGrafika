#include <GL/glut.h>
#include <cmath>


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

void wyswietlanko() {
	//slonce
	nowaPlaneta(0.08, 0.0, 0.0, 1.0, 0.9, 0.0);

	//Merkury
	orbita(0.15);
	nowaPlaneta(0.01, 0.0, -0.15, 1.0, 1.0, 1.0);

	//Wenus
	orbita(0.25);
	nowaPlaneta(0.02, 0.0, -0.25, 1.0, 0.9, 0.3);

	//Ziemia
	orbita(0.35);
	nowaPlaneta(0.02, 0.0, -0.35, 0.1, 0.3, 0.7);

	//Mars
	orbita(0.45);
	nowaPlaneta(0.02, 0.0, -0.45, 1.0, 0.35, 0.0);

	//Jowisz
	orbita(0.55);
	nowaPlaneta(0.04, 0.0, -0.55, 1.0, 0.6, 0.0);

	//Saturn
	orbita(0.65);
	orbitaPlanety(0.05, 0.0, -0.65);
	nowaPlaneta(0.038, 0.0, -0.65, 1.0, 0.8, 0.0);

	//Uran
	orbita(0.75);
	orbitaPlanety(0.04, 0.0, -0.75);
	nowaPlaneta(0.03, 0.0, -0.75, 0.0, 0.9, 1.0);

	//Neptun
	orbita(0.85);
	orbitaPlanety(0.04, 0.0, -0.85);
	nowaPlaneta(0.03, 0.0, -0.85, 0.0, 0.7, 1.0);

	glFlush();
}

void inicjalizacja() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
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
	glutMainLoop();
	return 0;
}