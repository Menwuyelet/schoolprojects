#include <GL/glut.h>
#include <iostream>

bool showMenu = true;
bool showChess = false;

int currentMove = 0;

char board[8][8] = {
    {'r','n','b','q','k','b','n','r'},
    {'p','p','p','p','p','p','p','p'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'P','P','P','P','P','P','P','P'},
    {'R','N','B','Q','K','B','N','R'}
};

struct Move {
    int sr, sc, dr, dc;
};

Move demoGame[] = {
    {6,4,4,4}, // e2 -> e4
    {1,4,3,4}, // e7 -> e5
    {7,6,5,5}, // g1 -> f3
    {0,1,2,2}  // b8 -> c6
};

void drawText(float x, float y, const char* text) {
    glRasterPos2f(x,y);
    for (int i = 0; text[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void drawMenu() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawText(220, 400, "CHESS DEMO");
    drawText(180, 350, "Press C to Start");
    drawText(180, 320, "Press Q to Quit");
    glFlush();
}

void drawBoard() {
    int size = 50;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if ((r + c) % 2 == 0)
                glColor3f(1,1,1);
            else
                glColor3f(0.3,0.3,0.3);

            glRecti(100 + c*size, 100 + r*size,
                    150 + c*size, 150 + r*size);

            if (board[r][c] != ' ') {
                glColor3f(0,0,0);
                char piece[2] = { board[r][c], '\0' };
                drawText(120 + c*size, 120 + r*size, piece);
            }
        }
    }
}

void drawChess() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawText(100, 520, "Auto Chess Demo  |  Press B for Back");
    drawBoard();
    glFlush();
}

void applyMove(int value) {
    if (!showChess) return;

    if (currentMove < 4) {
        Move m = demoGame[currentMove];
        board[m.dr][m.dc] = board[m.sr][m.sc];
        board[m.sr][m.sc] = ' ';
        currentMove++;
        glutPostRedisplay();
        glutTimerFunc(1000, applyMove, 0);
    }
}

void display() {
    if (showMenu) drawMenu();
    else if (showChess) drawChess();
}

void keyboard(unsigned char key, int, int) {
    if (key == 'c' || key == 'C') {
        showMenu = false;
        showChess = true;
        currentMove = 0;
        glutTimerFunc(1000, applyMove, 0);
    }
    if (key == 'b' || key == 'B') {
        showMenu = true;
        showChess = false;
    }
    if (key == 'q' || key == 'Q') exit(0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Chess CG Demo");

    gluOrtho2D(0,600,0,600);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
