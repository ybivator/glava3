#include <GL/glut.h>
#include <drawFunction.h>

int main(int argc, char *argv[])
{
   int windowWidth = 1000;
   int windowHeight = 800;
   int windowPosX = 0;
   int windowPosY = 0;

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutInitWindowSize(windowWidth, windowHeight);
   glutInitWindowPosition(windowPosX, windowPosY);
   glutCreateWindow("3.17");

   glutDisplayFunc(drawFunction);
   glutReshapeFunc(reshapeFunction);


   glutMainLoop();

   return 0;
}
