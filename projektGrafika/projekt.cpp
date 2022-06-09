#include <GL/glut.h>
#include <cmath>
#include <iostream>

//kamera
float katKameraX = 0.0, katKameraY = 0.0;
float x = 0.0f, z = 0.05f;

double* orbityAst;
double* katyAst;
double* xAst;
double* yAst;
int pasAst = 200;

float ksiezycR = 0.005;

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
double ksiezycZiemiiKat = 0;
float ziemiaR = 0.02;
float ksiezycZiemiiX = ziemiaX + (sin(ksiezycZiemiiKat) * (ziemiaR + 0.01));
float ksiezycZiemiiY = ziemiaY + (cos(ksiezycZiemiiKat) * (ziemiaR + 0.01));



double marsKat = 180;
float marsX = sin(marsKat) * 0.45;
float marsY = cos(marsKat) * 0.45;
float marsR = 0.02;
double ksiezycMarsaKat = 0;
float ksiezycMarsaX = marsX + (sin(ksiezycMarsaKat) * (marsR + 0.1));
float ksiezycMarsaY = marsY + (cos(ksiezycMarsaKat) * (marsR + 0.1));


double jowiszKat = 225;
float jowiszX = sin(jowiszKat) * 0.55;
float jowiszY = cos(jowiszKat) * 0.55;
float jowiszR = 0.04;
double ksiezycJowiszaKat = 0;
float ksiezycJowiszaX = jowiszX + (sin(ksiezycJowiszaKat) * (jowiszR + 0.1));
float ksiezycJowiszaY = jowiszY + (cos(ksiezycJowiszaKat) * (jowiszR + 0.1));

double saturnKat = 270;
float saturnX = sin(saturnKat) * 0.65;
float saturnY = cos(saturnKat) * 0.65;
float saturnR = 0.038;
double ksiezycSaturnaKat = 0;
float ksiezycSaturnaX = saturnX + (sin(ksiezycSaturnaKat) * (saturnR + 0.1));
float ksiezycSaturnaY = saturnY + (cos(ksiezycSaturnaKat) * (saturnR + 0.1));

double uranKat = 315;
float uranX = sin(uranKat) * 0.75;
float uranY = cos(uranKat) * 0.75;
float uranR = 0.03;
double ksiezycUranuKat = 0;
float ksiezycUranuX = uranX + (sin(ksiezycUranuKat) * (uranR + 0.1));
float ksiezycUranuY = uranY + (cos(ksiezycUranuKat) * (uranR + 0.1));

double neptunKat = 0;
float neptunX = sin(neptunKat) * 0.85;
float neptunY = cos(neptunKat) * 0.85;
float neptunR = 0.03;
double ksiezycNeptunaKat = 0;
float ksiezycNeptunaX = neptunX + (sin(ksiezycNeptunaKat) * (neptunR + 0.1));
float ksiezycNeptunaY = neptunY + (cos(ksiezycNeptunaKat) * (neptunR + 0.1));



void nowaPlaneta(float promien, float wspSrodkaX, float wspSrodkaY, float czerwony, float zielony, float niebieski, const char * filename) {
	float p = 0.0;
	float q = 0.0;
	float r = 0.0;
	double kat = 0.0;
	double kat2 = 0.0;

	GLfloat qaBlack[] = { 0, 0, 0, 1 };
	GLfloat qaColor[] = { czerwony, zielony, niebieski, 1 };
	GLfloat qaWhite[] = { 1, 1, 1, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);

	glPushMatrix();
	GLUquadric* quad;
	quad = gluNewQuadric();
	glTranslatef(wspSrodkaX, wspSrodkaY, 0.0);
	gluSphere(quad, promien, 100, 20);
	glEnd();
	glPopMatrix();
}

void slonce(float promien, float wspSrodkaX, float wspSrodkaY, float czerwony, float zielony, float niebieski, const char* filename) {
	float p = 0.0;
	float q = 0.0;
	float r = 0.0;
	double kat = 0.0;
	double kat2 = 0.0;

	GLfloat qaBlack[] = { 0, 0, 0, 1 };
	GLfloat qaColor[] = { czerwony, zielony, niebieski, 1.0 };
	GLfloat qaWhite[] = { 1, 1, 1, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128);

	glPushMatrix();
	GLUquadric* quad;
	quad = gluNewQuadric();
	glTranslatef(wspSrodkaX, wspSrodkaY, 0.0);
	gluSphere(quad, promien, 100, 20);
	glEnd();
	glPopMatrix();
}

void ksiezyc(float promien, float wspSrodkaX, float wspSrodkaY) {
	float p = 0.0;
	float q = 0.0;
	double kat = 0.0;

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	GLUquadric* quad;
	quad = gluNewQuadric();
	glTranslatef(wspSrodkaX, wspSrodkaY, 0.0);
	gluSphere(quad, promien, 100, 20);
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1, 1, 1, 1, -1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat qaAmbientLight[] = { 0.4,0.4,0.4,1.0 };
	GLfloat qaDiffuseLight[] = { 0.6,0.6,0.6,1.0 };
	GLfloat qaSpecularLight[] = { 1.0,1.0,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	GLfloat qaLightPosition[] = { 0,0,0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	gluLookAt(x, 0.0f, z, x, 0.0f, z - 1.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(katKameraX, 1, 0, 0);
	glRotatef(katKameraY, 0, 1, 0);
}

void wyswietlanko() {
	//slonce
	slonce(0.08, 0.0, 0.0, 1.0, 0.9, 0.0, "");

	//Merkury
	orbita(0.15);
	nowaPlaneta(merkuryR, merkuryX, merkuryY, 1.0, 1.0, 1.0, "");

	//Wenus
	orbita(0.25);
	nowaPlaneta(wenusR, wenusX, wenusY, 1.0, 0.9, 0.3, "");

	//Ziemia
	orbita(0.35);
	nowaPlaneta(ziemiaR, ziemiaX, ziemiaY, 0.1, 0.3, 0.7, "");
	ksiezyc(ksiezycR, ksiezycZiemiiX, ksiezycZiemiiY);

	//Mars
	orbita(0.45);
	nowaPlaneta(marsR, marsX, marsY, 1.0, 0.35, 0.0, "");
	ksiezyc(ksiezycR, ksiezycMarsaX, ksiezycMarsaY);

	//0.48 - 0.6

	for (int i = 0; i < pasAst; i++)
	{
		nowaPlaneta(0.005, xAst[i], yAst[i], 0.5, 0.5, 0.5, "");
	}
	//Jowisz
	orbita(0.65);
	nowaPlaneta(jowiszR, jowiszX, jowiszY, 1.0, 0.6, 0.0, "");
	ksiezyc(ksiezycR, ksiezycJowiszaX, ksiezycJowiszaY);

	//Saturn
	orbita(0.75);
	orbitaPlanety(0.05, saturnX, saturnY);
	orbitaPlanety(0.048, saturnX, saturnY);
	orbitaPlanety(0.046, saturnX, saturnY);
	nowaPlaneta(saturnR, saturnX, saturnY, 1.0, 0.8, 0.0, "");
	ksiezyc(ksiezycR, ksiezycSaturnaX, ksiezycSaturnaY);

	//Uran
	orbita(0.85);
	orbitaPlanety(0.04, uranX, uranY);
	nowaPlaneta(uranR, uranX, uranY, 0.0, 0.9, 1.0, "");
	ksiezyc(ksiezycR, ksiezycUranuX, ksiezycUranuY);

	//Neptun
	orbita(0.95);
	orbitaPlanety(0.04, neptunX, neptunY);
	nowaPlaneta(neptunR, neptunX, neptunY, 0.0, 0.7, 1.0, "");
	ksiezyc(ksiezycR, ksiezycNeptunaX, ksiezycNeptunaY);

	

	glFlush();
	inicjalizacja();
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, timer, 0);

	if (merkuryKat >= 0) {
		merkuryX = sin(merkuryKat) * 0.15;
		merkuryY = cos(merkuryKat) * 0.15;
		merkuryKat -= 0.07;
	}
	else merkuryKat = 360;
	if (wenusKat <= 360) {
		wenusX = sin(wenusKat) * 0.25;
		wenusY = cos(wenusKat) * 0.25;
		wenusKat += 0.04;
	}
	else wenusKat = 0;

	if (ziemiaKat >= 0) {
		ziemiaX = sin(ziemiaKat) * 0.35;
		ziemiaY = cos(ziemiaKat) * 0.35;
		ziemiaKat -= 0.025;
	}
	else ziemiaKat = 360;
	if (ksiezycZiemiiKat <= 360) {
		ksiezycZiemiiX = ziemiaX + (sin(ksiezycZiemiiKat) * (ziemiaR + 0.01));
		ksiezycZiemiiY = ziemiaY + (cos(ksiezycZiemiiKat) * (ziemiaR + 0.01));
		ksiezycZiemiiKat += 0.35;
	}
	else ksiezycZiemiiKat = 0;

	if (marsKat <= 360) {
		marsX = sin(marsKat) * 0.45;
		marsY = cos(marsKat) * 0.45;
		marsKat += 0.01;
	}
	else marsKat = 0;
	if (ksiezycMarsaKat >= 0) {

		ksiezycMarsaX = marsX + (sin(ksiezycMarsaKat) * (marsR + 0.01));
		ksiezycMarsaY = marsY + (cos(ksiezycMarsaKat) * (marsR + 0.01));
		ksiezycMarsaKat -= 0.3;
	}
	else ksiezycMarsaKat = 360;

	for (int i = 0; i < pasAst; i++)
	{
		if (katyAst[i] <= 360) {
			xAst[i] = sin(katyAst[i]) * orbityAst[i];
			yAst[i] = cos(katyAst[i]) * orbityAst[i];
			katyAst[i] += 0.02;
		}
		else katyAst[i] = 0;
	}

	if (jowiszKat >= 0) {
		jowiszX = sin(jowiszKat) * 0.65;
		jowiszY = cos(jowiszKat) * 0.65;
		jowiszKat -= 0.006;
	}
	else jowiszKat = 360;
	if (ksiezycJowiszaKat <= 360) {

		ksiezycJowiszaX = jowiszX + (sin(ksiezycJowiszaKat) * (jowiszR + 0.01));
		ksiezycJowiszaY = jowiszY + (cos(ksiezycJowiszaKat) * (jowiszR + 0.01));
		ksiezycJowiszaKat += 0.25;
	}
	else ksiezycJowiszaKat = 0;

	if (saturnKat <= 360) {
		saturnX = sin(saturnKat) * 0.75;
		saturnY = cos(saturnKat) * 0.75;
		saturnKat += 0.003;
	}
	else saturnKat = 0;
	if (ksiezycSaturnaKat >= 0) {

		ksiezycSaturnaX = saturnX + (sin(ksiezycSaturnaKat) * (saturnR + 0.01));
		ksiezycSaturnaY = saturnY + (cos(ksiezycSaturnaKat) * (saturnR + 0.01));
		ksiezycSaturnaKat -= 0.2;
	}
	else ksiezycSaturnaKat = 360;

	if (uranKat >= 0) {
		uranX = sin(uranKat) * 0.85;
		uranY = cos(uranKat) * 0.85;
		uranKat -= 0.0013;
	}
	else uranKat = 360;
	if (ksiezycUranuKat <= 360) {

		ksiezycUranuX = uranX + (sin(ksiezycUranuKat) * (uranR + 0.01));
		ksiezycUranuY = uranY + (cos(ksiezycUranuKat) * (uranR + 0.01));
		ksiezycUranuKat += 0.15;
	}
	else ksiezycUranuKat = 0;

	if (neptunKat <= 360) {
		neptunX = sin(neptunKat) * 0.95;
		neptunY = cos(neptunKat) * 0.95;
		neptunKat += 0.0005;
	}
	else neptunKat = 0;
	if (ksiezycNeptunaKat >= 0) {

		ksiezycNeptunaX = neptunX + (sin(ksiezycNeptunaKat) * (neptunR + 0.01));
		ksiezycNeptunaY = neptunY + (cos(ksiezycNeptunaKat) * (neptunR + 0.01));
		ksiezycNeptunaKat -= 0.1;
	}
	else ksiezycNeptunaKat = 360;
}

void obslugaKlawiszy(int key, int xx, int yy) {
	float ulamek = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		std::cout << "lewo" << std::endl;
		katKameraY--;
		break;
	case GLUT_KEY_RIGHT:
		std::cout << "prawo" << std::endl;
		katKameraY++;
		break;
	case GLUT_KEY_UP:
		std::cout << "gora" << std::endl;
		katKameraX -= 1.0f;
		break;
	case GLUT_KEY_DOWN:
		std::cout << "dol" << std::endl;
		katKameraX += 1.0f;
		break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	int x = (int)(glutGet(GLUT_SCREEN_HEIGHT)) / 1.2;
	int y = x;
	srand(time(0));
	orbityAst = new double[pasAst];
	for (int i = 0; i < pasAst; i++)
	{
		double random = rand() % (60 - 48 + 1) + 48;
		orbityAst[i] = random / 100;
	}
	katyAst = new double[pasAst];
	xAst = new double[pasAst];
	yAst = new double[pasAst];
	for (int i = 0; i < pasAst; i++)
	{
		katyAst[i] = rand() % 360;
		xAst[i] = sin(katyAst[i]) * orbityAst[i];
		yAst[i] = cos(katyAst[i]) * orbityAst[i];
	}
	glutInitWindowSize(x, y);
	glutInitWindowPosition((int)(glutGet(GLUT_SCREEN_WIDTH) - x) / 2, (int)(glutGet(GLUT_SCREEN_HEIGHT) - y) / 2);
	glutCreateWindow("Uklad sloneczny");
	glutDisplayFunc(wyswietlanko);
	glutSpecialFunc(obslugaKlawiszy);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(0, timer, 0);
	inicjalizacja();
	glutMainLoop();
	return 0;
}