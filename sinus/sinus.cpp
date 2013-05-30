// sinus.cpp : Defines the entry point for the console application.
//

#include "glutFunctions.h"

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutInitWindowSize(1000, 800);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Sinus function");
   
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   
   glutMainLoop();
   
   return 0;
}

