#include <GL/gl.h>
#include <cmath>
#include <iostream>
#include <drawFunction.h>


using std::cout;
using std::endl;

void drawFunction()
{
   glClearColor(1, 1, 1, 1);
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.0f, 0.0f, 0.0f);

   int x = 100;
   int y = 100;

   harmOscil();


   glBegin(GL_LINES);
      glVertex2i(-x, 0);
      glVertex2i(x, 0);
      glVertex2i(0, -y);
      glVertex2i(0, y);
   glEnd();

   glFlush();
}

void reshapeFunction(int w, int h)
{
   GLfloat aspectRatio = static_cast<GLfloat>(w) / static_cast<GLfloat>(h);
   GLfloat range = 100.0f;

   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   range /= aspectRatio;
   float yRange = 30;

   if(w <= h)
   {
      glOrtho(-range, range, -yRange, yRange, range, -range);
   }
   else
   {
      glOrtho(-range, range, -yRange, yRange, range, -range);
   }

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

}

void harmOscil()
{
   const double ekspo = 2.718;

   const double zatCoeff = 0.1;
   const double amplitude = 30;
   const double omega = 1.2;
   const double fazAngle = 0.2;

   for(double x = 0; x < 60; x += 0.01)
   {
      double y = amplitude * pow(ekspo, (-zatCoeff * x)) * sin(omega * x + fazAngle);
      cout << "x = " << x << " y = " << y << endl;      

      glBegin(GL_POINTS);
         glVertex2f(x, y);
      glEnd();
   }

   cout << endl;



}


