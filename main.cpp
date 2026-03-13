#include <GL/glut.h>

GLUquadric* quad;

void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth buffer
    quad = gluNewQuadric();   // Create a new quadric object
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -6.0f); // Move sphere back so it’s visible
    glColor3f(0.2f, 0.6f, 1.0f);     // Sphere color

    // radius, slices, stacks
    gluSphere(quad, 1.0, 32, 32);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("GLU Sphere Example");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
