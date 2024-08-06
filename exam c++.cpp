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

// Initial position and direction of the rectangle
float posX = -0.9f;
float direction = 0.01f;
float ro = 2.0f;
float r =0.0f;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);      // Set up a 2D orthographic projection
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Define the coordinate system
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);     // Clear the screen
    glColor3f(0.0, 0.0, 0.0);         // Set rectangle color to black

    glPushMatrix();
    glTranslatef(posX, 0.0f, 0.0f);   // Move the rectangle along the x-axis
    glRotatef(r,0,0,1);
        glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers(); // Swap buffers for smooth animation
}

void update(int value) {
    // Update the position of the rectangle
    posX += direction;
    r += ro;
    // Reverse direction if the rectangle hits the window boundaries
    if (posX > 0.9f || posX < -0.9f) {
        direction = -direction;
    }
    if(r>359.0 || r < -359.0)
    {
    r =-r;
    }

    glutPostRedisplay();      // Request a redisplay
    glutTimerFunc(16, update, 0); // Call update again in 16 milliseconds (~60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                              // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);        // Enable double buffering and RGB color mode
    glutInitWindowSize(800, 600);                       // Set window size
    glutInitWindowPosition(100, 100);                   // Set window position
    glutCreateWindow("Basic Animation with OpenGL");    // Create window with title

    init();                                             // Call initialization routine

    glutDisplayFunc(display);                           // Register display callback function
    glutTimerFunc(0, update, 0);                        // Register timer callback function

    glutMainLoop();                                     // Enter the GLUT event-processing loop
    return 0;
}

 

 
