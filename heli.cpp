#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

//Pipe
int pipeSpawn[3] = { 200,400,600 };
int translatePipePos[3] = { 0,100,0 };
int pipeCollisionBox[3][4][2] = { { { 0,0 },{ 0,0 },{ 0,0 },{ 0,0 } },{ { 0,0 },{ 0,0 },{ 0,0 },{ 0,0 } },{ { 0,0 },{ 0,0 },{ 0,0 },{ 0,0 } } };

//Heli
int wingRotateAngle = 0;
int HeliPos = 0;
int HeliFlyDist = 0;
int HeliCollisionBox[2][2] = { { -180,10 },{ -180,-10 } };

//Game logic
int introStatus = 0;
int gameOver = 0;
int btnState = 0;
int score = 0;
int reset = 0;

void resetGame() {
	if (reset == 1) {
		gameOver = 0;
		reset = 0;
		score = 0;
		HeliPos = 0;
		HeliFlyDist = 0;

		//Reseting Pipe Position
		pipeSpawn[0] = 200;
		pipeSpawn[1] = 400;
		pipeSpawn[2] = 600;
		translatePipePos[0] = 0;
		translatePipePos[1] = 100;
		translatePipePos[2] = 0;

		glutPostRedisplay();
	}
}

void drawPipe(int index, int pipeXAxis, int pipeYAxis)
{
	//Collision Box
	pipeCollisionBox[index][0][0] = pipeXAxis;
	pipeCollisionBox[index][0][1] = pipeYAxis + 50;
	pipeCollisionBox[index][1][0] = pipeXAxis + 50;
	pipeCollisionBox[index][1][1] = pipeYAxis + 50;
	pipeCollisionBox[index][2][0] = pipeXAxis + 50;
	pipeCollisionBox[index][2][1] = pipeYAxis - 50;
	pipeCollisionBox[index][3][0] = pipeXAxis;
	pipeCollisionBox[index][3][1] = pipeYAxis - 50;

	//Top pipe
	glPushMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2i(pipeXAxis, 800);
	glVertex2i(pipeXAxis + 50, 800);
	glVertex2i(pipeXAxis + 50, 50 + pipeYAxis);
	glVertex2i(pipeXAxis, 50 + pipeYAxis);
	//Pipe head
	glColor3f(1, 1, 1);
	glVertex2i(pipeXAxis - 3, 70 + pipeYAxis);
	glVertex2i(pipeXAxis + 50 + 3, 70 + pipeYAxis);
	glVertex2i(pipeXAxis + 50 + 3, 50 + pipeYAxis);
	glVertex2i(pipeXAxis - 3, 50 + pipeYAxis);
	glEnd();

	//Bottom pipe
	glColor3f(1, 1, 0.75);
	glBegin(GL_QUADS);
	glVertex2i(pipeXAxis, -800);
	glVertex2i(pipeXAxis + 50, -800);
	glVertex2i(pipeXAxis + 50, -50 + pipeYAxis);
	glVertex2i(pipeXAxis, -50 + pipeYAxis);
	//Pipe Head
	glColor3f(1, 1, 1);
	glVertex2i(pipeXAxis - 3, -70 + pipeYAxis);
	glVertex2i(pipeXAxis + 50 + 3, -70 + pipeYAxis);
	glVertex2i(pipeXAxis + 50 + 3, -50 + pipeYAxis);
	glVertex2i(pipeXAxis - 3, -50 + pipeYAxis);
	glEnd();
	glPopMatrix();
}

void pipeSpawner(int unused)
{
	if (pipeSpawn[0] == -300 && gameOver != 1) {
		pipeSpawn[0] = 300;
		translatePipePos[0] = (rand() % 20) * 10;
		score++;
	}
	else
		pipeSpawn[0] -= 1;

	if (pipeSpawn[1] == -300 && gameOver != 1) {
		pipeSpawn[1] = 300;
		translatePipePos[1] = (rand() % 20) * 10;
		score++;
	}
	else
		pipeSpawn[1] -= 1;

	if (pipeSpawn[2] == -300 && gameOver != 1) {
		pipeSpawn[2] = 300;
		translatePipePos[2] = (rand() % 20) * 10;
		score++;
	}
	else pipeSpawn[2] -= 1;

	glutPostRedisplay();
	glutTimerFunc(10, pipeSpawner, 0);
}

void drawHeli()
{
	glPushMatrix();
	glTranslatef(0, HeliPos, 0);
	//Heli Y Axis
	HeliCollisionBox[0][1] = 10 + HeliPos;
	HeliCollisionBox[1][1] = -10 + HeliPos;

	glColor3f(1, 0.5, 0.5);
	glBegin(GL_QUADS);
	//Body
	glVertex2i(-200, 5);
	glVertex2i(-200 + 20, 5);
	glVertex2i(-200 + 20, -10);
	glVertex2i(-200, -10);
	glEnd();

	glColor3f(1, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(-210, 8);
	glVertex2i(-210 + 40, 8);
	glVertex2i(-210 + 40, 10);
	glVertex2i(-210, 10);
	glEnd();
	
	glColor3f(1, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(-190, 5);
	glVertex2i(-190 + 5, 5);
	glVertex2i(-190 + 5, 8);
	glVertex2i(-190, 8);
	glEnd();

	glColor3f(1, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(-230, 2);
	glVertex2i(-230 + 40, 2);
	glVertex2i(-230 + 40, -2);
	glVertex2i(-230, -2);
	glEnd();

	glColor3f(1, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex2i(-200 + 20, 5);
	glVertex2i(-200 + 30, -3);
	glVertex2i(-200 + 20, -10);
	glEnd();

	glRotatef(wingRotateAngle, 1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-230 + 10, 5);
	glVertex2i(-230 + 5, -5);
	glVertex2i(-230 + 15, -5);
	glEnd();
	glPopMatrix();
}

int HeliCollision() {
	int i;
	for (i = 0; i < 3; i++) {
		if (pipeCollisionBox[i][0][0] <= -180 && pipeCollisionBox[i][1][0] >= -200) {
			if ((HeliCollisionBox[0][1] >= pipeCollisionBox[i][0][1] && HeliCollisionBox[0][0] == -180) || (HeliCollisionBox[1][1] <= pipeCollisionBox[i][2][1] && HeliCollisionBox[1][0] == -180)) {
				return 1;
			}
			else if ((HeliCollisionBox[0][1] >= pipeCollisionBox[i][0][1] && HeliCollisionBox[0][0] == -200) || (HeliCollisionBox[1][1] <= pipeCollisionBox[i][2][1] && HeliCollisionBox[1][0] == -200)) {
				return 1;
			}
		}
	}

	return 0;
}

void HeliFly(int unused)
{
	if (HeliCollision() == 1) {
		gameOver = 1;
		reset = 1;
	}
	if (HeliFlyDist != 0 && HeliPos != 300) {
		HeliPos++;
		HeliFlyDist--;
	}
	else {
		btnState = 0;
		return;
	}
	glutPostRedisplay();
	glutTimerFunc(10, HeliFly, unused);
}

void HeliFall()
{
	if (HeliCollision() == 1) {
		gameOver = 1;
		reset = 1;
	}

	if (btnState == 1)
		return;

	if (HeliPos != -300 && btnState == 0) {
		HeliPos--;
	}

	if (HeliPos == -300 || HeliPos == 300) {
		gameOver = 1;
		reset = 1;
	}
	glutPostRedisplay();
}

void HeliPhysics(int unused)
{
	if (wingRotateAngle == 180)
		wingRotateAngle = 0;
	else wingRotateAngle = 180;

	HeliFall();

	glutTimerFunc(10, HeliPhysics, 0);
}

void HeliMovementMouse(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		HeliFlyDist = 30;
		btnState = 1;
		HeliFly(0);
	}
}

void HeliMovementKey(unsigned char btn, int x, int y) {
	if (btn == ' ') {
		HeliFlyDist = 30;
		btnState = 1;
		HeliFly(0);
	}

	if (btn == 'p' && introStatus == 0) {
		introStatus = 1;
		reset = 1;
		resetGame();
	}

	if (btn == ' ' && gameOver == 1) {
		resetGame();
	}
	
	if(btn=='q')
	{
		exit(0);
	}
}

void renderBitmapString(float x, float y, void* font, const char* string) {
	const char* c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void drawScore() {
	char buffer[15] = { '\0' };
	sprintf(buffer, "Score : %d", score);
	glColor3f(0, 0, 0);
	renderBitmapString(-290, 270, GLUT_BITMAP_TIMES_ROMAN_24, buffer);
}

void introScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0.5);
	glColor3f(1, 0, 0);
	renderBitmapString(-140, 265, GLUT_BITMAP_TIMES_ROMAN_24,"          THAPAR UNIVERSITY");
	glColor3f(1, 0, 0);
	renderBitmapString(-160, 230, GLUT_BITMAP_TIMES_ROMAN_24, "DEPARTMENT OF COMPUTER SCIENCE");
	renderBitmapString(-20, 205, GLUT_BITMAP_TIMES_ROMAN_24, "AND");
	renderBitmapString(-60, 180, GLUT_BITMAP_TIMES_ROMAN_24, "ENGINEERING");
	glColor3f(1, 0.5, 0);
	renderBitmapString(-65, 120, GLUT_BITMAP_TIMES_ROMAN_24, "A PROJECT ON");
	glColor3f(1, 0, 0);
	renderBitmapString(-80, 90, GLUT_BITMAP_TIMES_ROMAN_24, "The Helicopter Game");
	glColor3f(1, 0.5, 0);
	renderBitmapString(-290, -30, GLUT_BITMAP_TIMES_ROMAN_24, "BY:");
	glColor3f(0.5, 0, 0.5);
	renderBitmapString(-260, -60, GLUT_BITMAP_TIMES_ROMAN_24, "Sudhanshu Poonia   (101916090)");
	renderBitmapString(-260, -90, GLUT_BITMAP_TIMES_ROMAN_24, "Taksh Preet Singh  (101916077)");
	renderBitmapString(-260, -120, GLUT_BITMAP_TIMES_ROMAN_24,"Sidak Singh Bhatia (101916068)");
	glColor3f(1, 0.5, 0);
	renderBitmapString(40, -30, GLUT_BITMAP_TIMES_ROMAN_24, "GUIDES:");
	glColor3f(0.5, 0.3, 0.2);
	renderBitmapString(120, -60, GLUT_BITMAP_TIMES_ROMAN_24, "Amrita Mam");
	glColor3f(1, 0.2, 1);
	renderBitmapString(-80, -275, GLUT_BITMAP_TIMES_ROMAN_24, "Press P to Start");

	glFlush();
}

void gameOverScreen() {
	char buffer[15] = { '\0' };

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);

	glColor3f(1, 0, 0);
	renderBitmapString(-40, 90, GLUT_BITMAP_TIMES_ROMAN_24, "Game Over");

	glColor3f(1, 0.5, 0);
	sprintf(buffer, "Score : %d", score);
	renderBitmapString(-30, -30, GLUT_BITMAP_TIMES_ROMAN_24, buffer);

	glColor3f(1, 0.1, 1);
	renderBitmapString(-110, -275, GLUT_BITMAP_TIMES_ROMAN_24, "Press Space to Restart and Q to exit");

	glFlush();
}
void display()
{
	if (introStatus == 0)
		introScreen();
	else if (gameOver == 1)
		gameOverScreen();
	else {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0,0,0,0);
		glLoadIdentity();

		drawPipe(0, pipeSpawn[0], translatePipePos[0]);
		drawPipe(1, pipeSpawn[1], translatePipePos[1]);
		drawPipe(2, pipeSpawn[2], translatePipePos[2]);
		drawScore();
		drawHeli();

		glFlush();
	}
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(1000, 750);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("Helicopter Game");
	glutDisplayFunc(display);
	glutMouseFunc(HeliMovementMouse);
	glutKeyboardFunc(HeliMovementKey);
	init();
	pipeSpawner(0);
	HeliPhysics(0);
	glutMainLoop();
}
