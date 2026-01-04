#include <GL/glut.h>
#include <string>

// ---------- TEXT FUNCTIONS ----------
void drawText(float x, float y, const std::string& text, void* font = GLUT_BITMAP_HELVETICA_18)
{
    glRasterPos2f(x, y);
    for (char c : text)
        glutBitmapCharacter(font, c);
}

void drawTextCentered(float centerX, float y, const std::string& text, void* font = GLUT_BITMAP_HELVETICA_18)
{
    int winW = glutGet(GLUT_WINDOW_WIDTH);
    if (winW <= 0) {
        drawText(centerX, y, text, font);
        return;
    }

    int width = 0;
    for (char c : text)
        width += glutBitmapWidth(font, c);

    float startX = centerX - (float)width / winW;
    glRasterPos2f(startX, y);

    for (char c : text)
        glutBitmapCharacter(font, c);
}

// ---------- DISPLAY ----------
void display()
{
    // Background
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Title
    glColor3f(0.0f, 0.9f, 0.9f);
    drawText(-0.32f, 0.85f, "Basic Graphics Primitives", GLUT_BITMAP_TIMES_ROMAN_24);

    // Divider
    glLineWidth(1.5f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
        glVertex2f(-1.0f, 0.8f);
        glVertex2f( 1.0f, 0.8f);
    glEnd();

    // POINT
    glPointSize(20.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POINTS);
        glVertex2f(-0.7f, 0.3f);
    glEnd();

    glColor3f(1, 1, 1);
    drawText(-0.78f, 0.15f, "POINT");

    // LINES
    glPointSize(8.0f);
    glLineWidth(3.0f);

    // Horizontal
    glColor3f(0.0f, 1.0f, 0.4f);
    glBegin(GL_LINES);
        glVertex2f(-0.2f, 0.6f);
        glVertex2f( 0.2f, 0.6f);
    glEnd();

    // Vertical
    glColor3f(0.2f, 0.6f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.15f, 0.4f);
        glVertex2f(-0.15f, 0.1f);
    glEnd();

    // Slanted
    glColor3f(1.0f, 1.0f, 0.2f);
    glBegin(GL_LINES);
        glVertex2f(0.05f, 0.4f);
        glVertex2f(0.25f, 0.1f);
    glEnd();

    drawText(-0.07f, -0.1f, "LINES");

    // TRIANGLE
    float v1[2] = {0.45f, 0.1f};
    float v2[2] = {0.85f, 0.1f};
    float v3[2] = {0.65f, 0.6f};

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(v1[0], v1[1]);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(v2[0], v2[1]);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(v3[0], v3[1]);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(v1[0], v1[1]);
        glVertex2f(v2[0], v2[1]);
        glVertex2f(v3[0], v3[1]);
    glEnd();

    drawText(0.55f, -0.05f, "TRIANGLE");

    // Bottom divider
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
        glVertex2f(-1.0f, -0.7f);
        glVertex2f( 1.0f, -0.7f);
    glEnd();

    // Footer
    glColor3f(0.85f, 0.85f, 0.85f);
    drawTextCentered(0.0f, -0.82f, "Menwuyelet Temesgen");
    drawTextCentered(0.0f, -0.90f, "ID: UGR/34920/16");
    drawTextCentered(0.0f, -0.98f, "Sec. 5", GLUT_BITMAP_HELVETICA_12);

    glFlush();
}

// ---------- MAIN ----------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Basic Graphics Primitives");

    gluOrtho2D(-1, 1, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
