#include <GL/glut.h>
#include <iostream>

/* ================= GLOBALS ================= */

bool race = false;
float carY = -100;
float roadLineOffset = 0;

/* ================= TIMER ================= */

void animate(int) {
    if (race) {
        carY += 2.0f;              // car speed
        roadLineOffset += 5.0f;    // road motion

        if (carY > 700)
            carY = -100;

        if (roadLineOffset > 40)
            roadLineOffset = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(16, animate, 0); // ~60 FPS
}

/* ================= INPUT ================= */

void keyboard(unsigned char key, int, int) {
    switch (key) {
    case 'r':
    case 'R':
        race = true;
        break;

    case 'b':
    case 'B':
        race = false;
        carY = -100;
        break;

    case 'q':
    case 'Q':
        exit(0);
    }
}

/* ================= DRAW ================= */

void drawCar(float x, float y) {
    // body
    glColor3f(1, 0, 0);
    glRectf(x, y, x + 60, y + 120);

    // roof
    glColor3f(0.8, 0, 0);
    glRectf(x + 10, y + 40, x + 50, y + 90);

    // wheels
    glColor3f(0, 0, 0);
    glRectf(x - 5, y + 10, x + 5, y + 30);
    glRectf(x - 5, y + 80, x + 5, y + 100);
    glRectf(x + 60, y + 10, x + 70, y + 30);
    glRectf(x + 60, y + 80, x + 70, y + 100);
}

void drawRoad() {
    // grass
    glColor3f(0.1f, 0.6f, 0.1f);
    glRectf(0, 0, 640, 700);

    // road
    glColor3f(0.2f, 0.2f, 0.2f);
    glRectf(200, 0, 440, 700);

    // borders
    glColor3f(1, 1, 1);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(200, 0); glVertex2f(200, 700);
    glVertex2f(440, 0); glVertex2f(440, 700);
    glEnd();

    // dashed center line
    for (int y = -40; y < 700; y += 80) {
        glRectf(318, y + roadLineOffset, 322, y + 40 + roadLineOffset);
    }
}

void display() {
    glClearColor(0.3f, 0.3f, 0.3f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 700);

    drawRoad();

    if (race)
        drawCar(290, carY);

    // UI text
    glColor3f(1,1,1);
    glRasterPos2f(10, 660);
    const char* txt = "R - Start | B - Reset | Q - Quit";
    for (int i = 0; txt[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[i]);

    glFlush();
}

/* ================= MAIN ================= */

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(640, 700);
    glutCreateWindow("Racing Car Arena");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, animate, 0);

    glutMainLoop();
    return 0;
}
