#include <GL/glut.h>
#include <cmath>


double merkuryKat = 45;
float merkuryX = sin(merkuryKat) * 0.15;
float merkuryY = cos(merkuryKat) * 0.15;
float merkuryR = 0.01;

double wenusKat = 90;
float wenusX = sin(wenusKat) * 0.25;
float wenusY = cos(wenusKat) * 0.25;
float wenusR = 0.02;

double ziemiaKat = 135;
float ziemiaX = sin(ziemiaKat) * 0.35;
float ziemiaY = cos(ziemiaKat) * 0.35;
float ziemiaR = 0.02;

double marsKat = 180;
float marsX = sin(marsKat) * 0.45;
float marsY = cos(marsKat) * 0.45;
float marsR = 0.02;

double jowiszKat = 225;
float jowiszX = sin(jowiszKat) * 0.55;
float jowiszY = cos(jowiszKat) * 0.55;
float jowiszR = 0.04;

double saturnKat = 270;
float saturnX = sin(saturnKat) * 0.65;
float saturnY = cos(saturnKat) * 0.65;
float saturnR = 0.038;

double uranKat = 315;
float uranX = sin(uranKat) * 0.75;
float uranY = cos(uranKat) * 0.75;
float uranR = 0.03;

double neptunKat = 0;
float neptunX = sin(neptunKat) * 0.85;
float neptunY = cos(neptunKat) * 0.85;
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

	if (merkuryKat <= 360) {
		merkuryX = sin(merkuryKat) * 0.15;
		merkuryY = cos(merkuryKat) * 0.15;
		merkuryKat += 0.007;
	}
	else merkuryKat = 0;

	if (wenusKat <= 360) {
		wenusX = sin(wenusKat) * 0.25;
		wenusY = cos(wenusKat) * 0.25;
		wenusKat += 0.006;
	}
	else wenusKat = 0;

	if (ziemiaKat <= 360) {
		ziemiaX = sin(ziemiaKat) * 0.35;
		ziemiaY = cos(ziemiaKat) * 0.35;
		ziemiaKat += 0.005;
	}
	else ziemiaKat = 0;

	if (marsKat <= 360) {
		marsX = sin(marsKat) * 0.45;
		marsY = cos(marsKat) * 0.45;
		marsKat += 0.004;
	}
	else marsKat = 0;

	if (jowiszKat <= 360) {
		jowiszX = sin(jowiszKat) * 0.55;
		jowiszY = cos(jowiszKat) * 0.55;
		jowiszKat += 0.003;
	}
	else jowiszKat = 0;

	if (saturnKat <= 360) {
		saturnX = sin(saturnKat) * 0.65;
		saturnY = cos(saturnKat) * 0.65;
		saturnKat += 0.002;
	}
	else saturnKat = 0;

	if (uranKat <= 360) {
		uranX = sin(uranKat) * 0.75;
		uranY = cos(uranKat) * 0.75;
		uranKat += 0.001;
	}
	else uranKat = 0;

	if (neptunKat <= 360) {
		neptunX = sin(neptunKat) * 0.85;
		neptunY = cos(neptunKat) * 0.85;
		neptunKat += 0.0009;
	}
	else neptunKat = 0;
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