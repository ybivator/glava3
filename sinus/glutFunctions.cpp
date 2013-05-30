#include "glutFunctions.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

void sinusFunc(GLfloat start, GLfloat end);

int counter(GLfloat startP, GLfloat endP)
{
   int tmp = 0;
   while(startP < endP)
   {
      tmp++;
      startP += 2 * PI;
   }
   return tmp;
}

void display()
{
   glClearColor(0, 0, 0, 0);
   glClear(GL_COLOR_BUFFER_BIT);
   
   glColor3f(1.0f, 1.0f, 1.0f);
   
   GLfloat start = -50;
   GLfloat end = 70;
   
   sinusFunc(start, end);
   
   glBegin(GL_LINES);
      glVertex2i(-100, 0);
      glVertex2i(100, 0);
      glVertex2i(0, -100);
      glVertex2i(0, 100);
   glEnd();
   
   glFlush();

}


void reshape(int w, int h)
{

   GLfloat aspectRatio;
   GLfloat nRange = 100.0f;
   if(h == 0)
      h = 1;

   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   aspectRatio = (GLfloat)w / (GLfloat)h;
   if(w <= h)
   {
      nRange /= aspectRatio;
      glOrtho(-nRange, nRange, -2, 2, -nRange, nRange);
   }
   else
   {
      nRange /= aspectRatio;
      glOrtho(-nRange, nRange, -2, 2, -nRange, nRange);
   }
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void sinusFunc(GLfloat start, GLfloat end)
{

//   for(float i = start; i <= end; i+=0.00001)
//   {
//      glBegin(GL_POINTS);
//         glVertex2f(i, sin(i));
//      glEnd(); 
//   }

   GLfloat index = 0.00001;
   GLfloat start1 = start;
   GLfloat sinus1 = sin(start1);
   GLfloat start2 = start1 + index;
   GLfloat sinus2 = sin(start2);

   if(sinus1 > 0)
   {
      if((sinus2 - sinus1) > 0)
      {
         while((sinus2 - sinus1) >= 0)
         {
            glBegin(GL_POINTS);
	       glVertex2f(start1, sinus1);
	    glEnd();
	    start1 += index;
	    sinus1 = sin(start1);
	    start2 += index;
	    sinus2 = sin(start2);
         }

	 cout << "================" << endl;

	 GLfloat startPoint = start1 - index;
	 GLfloat y = sin(startPoint);
	 GLfloat endPoint = startPoint;

	 GLfloat bottomLeft = startPoint + PI; 
	 GLfloat bottomRight = bottomLeft;
	 GLfloat topLeft = startPoint + PI2;
	 GLfloat topRight = topLeft;

	 GLfloat startBL = startPoint + PI;
	 GLfloat startBR = startBL + PI / 2;
	 GLfloat startTL = startBR + PI / 2;
	 GLfloat startTR = startTL + PI / 2;

	 int countBL = counter(startBL, end);
	 int countBR = counter(startBR, end);
	 int countTL = counter(startTL, end);
	 int countTR = counter(startTR, end);


	 cout.precision(4);
	 cout << "startPoint = " << startPoint << endl;
	 cout << "bottomLeft = " << bottomLeft << endl;
	 cout << "BLnum = " << countBL << endl;
	 cout << "bottomRight = " << bottomRight << endl;
	 cout << "BRnum = " << countBR << endl;
	 cout << "topLeft = " << topLeft << endl;
	 cout << "TLnum = " << countTL << endl;
	 cout << "topRight = " << topRight << endl;
	 cout << "TRnum = " << countTR << endl;

	 while(y > 0)
	 {
	    glBegin(GL_POINTS);
	       glVertex2f(startPoint, y);
	       for(int i = 0; i < countBL; i++)
	       {
	          glVertex2f(bottomLeft + i * PI2, -y);
	       }
	       for(int i = 0; i < countBR; i++)
	       {
	          glVertex2f(bottomRight + i * PI2, -y);
	       }
	       for(int i = 0; i < countTL; i++)
	       {
	          glVertex2f(topLeft + i * PI2, y);
	       }
	       for(int i = 0; i < countTR; i++)
	       {
	          glVertex2f(topRight + i * PI2, y);
	       }
	    glEnd();
	    startPoint += index;
	    y = sin(startPoint);
	    bottomLeft -= index;
	    bottomRight += index;
	    topLeft -= index;
	    topRight += index;
	 }
	 while(endPoint < end)
	 {
	    endPoint += halfPI;
	 }
	 endPoint -= halfPI;
	 cout << "endPoint = "<< endPoint << endl;
	 while(endPoint <= end)
	 {
	    glBegin(GL_POINTS);
	       glVertex2f(endPoint, sin(endPoint));
	    glEnd();
	    endPoint += index;
	 }

	 
      }
   }
   
}	
