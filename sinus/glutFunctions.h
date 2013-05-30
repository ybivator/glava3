#ifndef GLUT_FUNCTIONS_H_
#define GLUT_FUNCTIONS_H_


#include <GL/glut.h>

const float PI = 3.14159;
const float PI2 = PI*2;
const float halfPI = PI/2;

void display();
void reshape(int w, int h);

int counter(GLfloat startP, GLfloat endP);


#endif
