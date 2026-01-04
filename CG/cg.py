from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

def draw_text(x, y, text, font=GLUT_BITMAP_HELVETICA_18):
    glRasterPos2f(x, y)
    for char in text:
        glutBitmapCharacter(font, ord(char))
def draw_text_centered(center_x, y, text, font=GLUT_BITMAP_HELVETICA_18):
    win_w = glutGet(GLUT_WINDOW_WIDTH)
    if win_w <= 0:
        draw_text(center_x, y, text, font)
        return
    total_px = 0
    for ch in text:
        total_px += glutBitmapWidth(font, ord(ch))
    start_x = center_x - (total_px / win_w)
    glRasterPos2f(start_x, y)
    for ch in text:
        glutBitmapCharacter(font, ord(ch))
def display():
    glClearColor(0.05, 0.05, 0.1, 1.0)
    glClear(GL_COLOR_BUFFER_BIT)

    glColor3f(1.0, 1.0, 1.0)
    draw_text(-0.28, 0.85, "Basic Graphics Primitives", GLUT_BITMAP_TIMES_ROMAN_24)
    
    glLineWidth(1.0)
    glColor3f(0.3, 0.3, 0.5)
    glBegin(GL_LINES)
    glVertex2f(-1.0, 0.8)
    glVertex2f(1.0, 0.8)
    glEnd()

    glPointSize(20.0)
    glColor3f(1.0, 0.4, 0.4)
    glBegin(GL_POINTS)
    glVertex2f(-0.7, 0.3)
    glEnd()
    glColor3f(1.0, 1.0, 1.0)
    draw_text(-0.78, 0.15, "POINT")

    glPointSize(8.0)
    glLineWidth(3.0)
    
    glColor3f(0.2, 1.0, 0.6)
    glBegin(GL_LINES)
    glVertex2f(-0.2, 0.6)
    glVertex2f(0.2, 0.6)
    glEnd()
    glBegin(GL_POINTS)
    glVertex2f(-0.2, 0.6); glVertex2f(0.2, 0.6)
    glEnd()
    draw_text(-0.25, 0.62, "A"); draw_text(0.22, 0.62, "B")

    glColor3f(0.2, 0.8, 1.0)
    glBegin(GL_LINES)
    glVertex2f(-0.15, 0.4)
    glVertex2f(-0.15, 0.1)
    glEnd()
    glBegin(GL_POINTS)
    glVertex2f(-0.15, 0.4); glVertex2f(-0.15, 0.1)
    glEnd()
    draw_text(-0.22, 0.42, "A"); draw_text(-0.22, 0.05, "B")

    glColor3f(1.0, 0.8, 0.2)
    glBegin(GL_LINES)
    glVertex2f(0.05, 0.4)
    glVertex2f(0.25, 0.1)
    glEnd()
    glBegin(GL_POINTS)
    glVertex2f(0.05, 0.4); glVertex2f(0.25, 0.1)
    glEnd()
    draw_text(0.02, 0.42, "A"); draw_text(0.27, 0.08, "B")
    
    glColor3f(1.0, 1.0, 1.0)
    draw_text(-0.07, -0.1, "LINES")

    v1, v2, v3 = [0.45, 0.1], [0.85, 0.1], [0.65, 0.6]
    glBegin(GL_TRIANGLES)
    glColor3f(0.4, 0.1, 0.7)
    glVertex2f(*v1)
    glColor3f(0.6, 0.2, 0.9)
    glVertex2f(*v2)
    glColor3f(0.3, 0.5, 1.0)
    glVertex2f(*v3)
    glEnd()

    glLineWidth(2.5)
    glColor3f(1.0, 1.0, 1.0)
    glBegin(GL_LINE_LOOP)
    glVertex2f(*v1); glVertex2f(*v2); glVertex2f(*v3)
    glEnd()
    draw_text(0.55, -0.05, "TRIANGLE")

    glColor3f(0.3, 0.3, 0.5)
    glBegin(GL_LINES)
    glVertex2f(-1.0, -0.7)
    glVertex2f(1.0, -0.7)
    glEnd()

    glColor3f(0.8, 0.8, 0.8)
    draw_text_centered(0.0, -0.82, "Eyob Adamu", GLUT_BITMAP_HELVETICA_18)
    draw_text_centered(0.0, -0.92, "ID: UGR/34358/16", GLUT_BITMAP_HELVETICA_12)
    glFlush()

def main():
    glutInit()
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
    glutInitWindowSize(1000, 800)
    glutCreateWindow(b"Basic Graphics Primitives")
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0)
    glutDisplayFunc(display)
    glutMainLoop()

main()