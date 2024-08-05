#include <GL/glut.h> 
#include <stdio.h> 
 
int x1, y1, x2, y2; 
 
void myInit() { 
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0, 500, 0, 500); 
} 
 
void draw_pixel(int x, int y) { 
    glBegin(GL_POINTS); 
    glVertex2i(x, y); 
    glEnd(); 
} 
 
void draw_line(int x1, int y1, int x2, int y2) { 
    int dx = abs(x2 - x1), dy = abs(y2 - y1); 
    int sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1; 
    int err = (dx > dy ? dx : -dy) / 2, e2; 
 
    while (1) { 
        draw_pixel(x1, y1); 
        if (x1 == x2 && y1 == y2) break; 
        e2 = err; 
        if (e2 > -dx) { err -= dy; x1 += sx; } 
        if (e2 < dy) { err += dx; y1 += sy; } 
    } 
} 
 
void myDisplay() { 
    glClear(GL_COLOR_BUFFER_BIT); 
    draw_line(x1, y1, x2, y2); 
    glFlush(); 
} 
 
int main(int argc, char **argv) { 
    printf("Enter x1, y1, x2, y2:\n"); 
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Line Drawing"); 
    myInit(); 
    glutDisplayFunc(myDisplay); 
    glutMainLoop(); 
 
    return 0; 
} 
 
 
#include <GL/glut.h> 
 
float rectWidth = 100.0f, rectHeight = 50.0f; 
float transX = 0, transY = 0, rotate = 0, scaleX = 1, scaleY = 1; 
 
void init() { 
    glClearColor(1.0, 1.0, 1.0, 0); 
    gluOrtho2D(-300, 300, -300, 300); 
} 
 
void drawRectangle() { 
    glPushMatrix(); 
    glTranslatef(transX, transY, 0); 
    glRotatef(rotate, 0, 0, 1); 
    glScalef(scaleX, scaleY, 1); 
    glColor3f(0, 0, 0); 
    glBegin(GL_QUADS); 
    glVertex2f(-rectWidth / 2, -rectHeight / 2); 
    glVertex2f(rectWidth / 2, -rectHeight / 2); 
    glVertex2f(rectWidth / 2, rectHeight / 2); 
    glVertex2f(-rectWidth / 2, rectHeight / 2); 
    glEnd(); 
    glPopMatrix(); 
} 
 
void display() { 
    glClear(GL_COLOR_BUFFER_BIT); 
    drawRectangle(); 
    glFlush(); 
} 
 
void keyboard(unsigned char key, int, int) { 
    if (key == 't') { transX += 10; transY += 10; } 
    else if (key == 'r') { rotate += 10; } 
    else if (key == 's') { scaleX += 0.1f; scaleY += 0.1f; } 
    glutPostRedisplay(); 
} 
 
int main(int argc, char** argv) { 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(600, 600); 
    glutCreateWindow("2D Transformations"); 
    init(); 
    glutDisplayFunc(display); 
    glutKeyboardFunc(keyboard); 
    glutMainLoop(); 
    return 0; 
} 
 
#include <GL/glut.h> 
 
float transX = 0, transY = 0, transZ = 0; 
float rotateX = 0, rotateY = 0, rotateZ = 0; 
float scaleX = 1, scaleY = 1, scaleZ = 1; 
 
void init() { 
    glClearColor(1.0, 1.0, 1.0, 0); 
    glEnable(GL_DEPTH_TEST); 
} 
 
void drawCube() { 
    glPushMatrix(); 
    glTranslatef(transX, transY, transZ); 
    glRotatef(rotateX, 1, 0, 0); 
    glRotatef(rotateY, 0, 1, 0); 
    glRotatef(rotateZ, 0, 0, 1); 
    glScalef(scaleX, scaleY, scaleZ); 
     
    glBegin(GL_QUADS); 
 
    // Front face (red) 
    glColor3f(1.0, 0.0, 0.0); 
    glVertex3f(-0.5, -0.5,  0.5); 
    glVertex3f( 0.5, -0.5,  0.5); 
    glVertex3f( 0.5,  0.5,  0.5); 
    glVertex3f(-0.5,  0.5,  0.5); 
 
    // Back face (green) 
    glColor3f(0.0, 1.0, 0.0); 
    glVertex3f(-0.5, -0.5, -0.5); 
    glVertex3f(-0.5,  0.5, -0.5); 
    glVertex3f( 0.5,  0.5, -0.5); 
    glVertex3f( 0.5, -0.5, -0.5); 
 
    // Left face (blue) 
    glColor3f(0.0, 0.0, 1.0); 
    glVertex3f(-0.5, -0.5, -0.5); 
    glVertex3f(-0.5, -0.5,  0.5); 
    glVertex3f(-0.5,  0.5,  0.5); 
    glVertex3f(-0.5,  0.5, -0.5); 
 
    // Right face (yellow) 
    glColor3f(1.0, 1.0, 0.0); 
    glVertex3f( 0.5, -0.5, -0.5); 
    glVertex3f( 0.5,  0.5, -0.5); 
    glVertex3f( 0.5,  0.5,  0.5); 
    glVertex3f( 0.5, -0.5,  0.5); 
 
    // Top face (cyan) 
    glColor3f(0.0, 1.0, 1.0); 
    glVertex3f(-0.5,  0.5, -0.5); 
    glVertex3f(-0.5,  0.5,  0.5); 
    glVertex3f( 0.5,  0.5,  0.5); 
    glVertex3f( 0.5,  0.5, -0.5); 
 
    // Bottom face (magenta) 
    glColor3f(1.0, 0.0, 1.0); 
    glVertex3f(-0.5, -0.5, -0.5); 
    glVertex3f( 0.5, -0.5, -0.5); 
    glVertex3f( 0.5, -0.5,  0.5); 
    glVertex3f(-0.5, -0.5,  0.5); 
 
    glEnd(); 
    glPopMatrix(); 
} 
 
void display() { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    drawCube(); 
    glutSwapBuffers(); 
} 
 
void keyboard(unsigned char key, int, int) { 
    if (key == 't') { transX += 0.1; transY += 0.1; transZ += 0.1; } 
    else if (key == 'r') { rotateX += 10; rotateY += 10; rotateZ += 10; } 
    else if (key == 's') { scaleX += 0.1; scaleY += 0.1; scaleZ += 0.1; } 
    glutPostRedisplay(); 
} 
 
int main(int argc, char** argv) { 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(600, 600); 
    glutCreateWindow("3D Transformations with Colors"); 
    init(); 
    glutDisplayFunc(display); 
    glutKeyboardFunc(keyboard); 
    glutMainLoop(); 
    return 0; 
} 
 

#include <GL/glut.h>
#include <cmath>

// Transformation properties
float translateX = 0.0f, translateY = 0.0f;
float rotateAngle = 0.0f, scaleX = 1.0f, scaleY = 1.0f;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}

void drawRectangle() {
    glPushMatrix();
    glTranslatef(-100.0f + translateX, 100.0f + translateY, 0.0);
    glRotatef(rotateAngle, 0.0, 0.0, 1.0);
    glScalef(scaleX, scaleY, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-50.0f, -50.0f);
        glVertex2f(50.0f, -50.0f);
        glVertex2f(50.0f, 50.0f);
        glVertex2f(-50.0f, 50.0f);
    glEnd();
    glPopMatrix();
}

void drawTriangle() {
    glPushMatrix();
    glTranslatef(100.0f + translateX, 100.0f + translateY, 0.0);
    glRotatef(rotateAngle, 0.0, 0.0, 1.0);
    glScalef(scaleX, scaleY, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 50.0f);
        glVertex2f(-50.0f, -50.0f);
        glVertex2f(50.0f, -50.0f);
    glEnd();
    glPopMatrix();
}

void drawCircle() {
    const int sides = 50;
    glPushMatrix();
    glTranslatef(0.0f + translateX, -100.0f + translateY, 0.0);
    glRotatef(rotateAngle, 0.0, 0.0, 1.0);
    glScalef(scaleX, scaleY, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i) {
        float angle = 2.0f * M_PI * float(i) / float(sides);
        float cx = cos(angle) * 50.0f;
        float cy = sin(angle) * 50.0f;
        glVertex2f(cx, cy);
    }
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawRectangle();
    drawTriangle();
    drawCircle();
    glFlush();
}

void keyboard(unsigned char key, int, int) {
    switch (key) {
        case 't':
            translateX += 10.0f;
            translateY += 10.0f;
            break;
        case 'r':
            rotateAngle += 10.0f;
            break;
        case 's':
            scaleX += 0.1f;
            scaleY += 0.1f;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Transformations on Basic Shapes");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

 
 
 
 

 
#include <GL/glut.h> 
 
GLsizei winWidth = 500, winHeight = 500; 
static GLfloat rotTheta = 0.0; 
 
void init(void) { 
    glClearColor(1.0, 1.0, 1.0, 0.0); 
} 
 
void displaySquare(void) { 
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 
    glTranslatef(150.0, 150.0, 0.0); 
    glRotatef(rotTheta, 0.0, 0.0, 1.0); 
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_POLYGON); 
    glVertex2f(-50.0, -50.0); 
    glVertex2f(50.0, -50.0); 
    glVertex2f(50.0, 50.0); 
    glVertex2f(-50.0, 50.0); 
    glEnd(); 
    glutSwapBuffers(); 
} 
 
void rotateSquare(void) { 
    rotTheta += 3.0; 
    if (rotTheta > 360.0) 
        rotTheta -= 360.0; 
    glutPostRedisplay(); 
} 
void keyboard(unsigned char key, int x, int y) { 
    switch (key) { 
        case 'r': 
            glutIdleFunc(rotateSquare); 
            break; 
        case 's': 
            glutIdleFunc(NULL); // Stop rotation 
            break; 
        case 'q': 
            exit(0); // Quit program 
            break; 
        default: 
            break; 
    } 
} 
void winReshapeFcn(GLint newWidth, GLint newHeight) { 
    glViewport(0, 0, newWidth, newHeight); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(-250.0, 250.0, -250.0, 250.0); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    glClear(GL_COLOR_BUFFER_BIT); 
} 
 
int main(int argc, char** argv) { 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowPosition(150, 150); 
    glutInitWindowSize(winWidth, winHeight); 
    glutCreateWindow("Simple Square Rotation"); 
 
    init(); 
    glutDisplayFunc(displaySquare); 
    glutReshapeFunc(winReshapeFcn); 
    glutKeyboardFunc(keyboard); 
    glutIdleFunc(rotateSquare); 
 
    glutMainLoop(); 
    return 0; 
} 
 
 
 