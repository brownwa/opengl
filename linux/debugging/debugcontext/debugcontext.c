/*
 * debugcontext.c
 * 2015/12/30
 * Waheed Brown
 *
 * OpenGL Developers Toolbox
 * Debugging and Profiling OpenGL
 * Creating a Debug Context
 *
 * REFERENCES:
 * Shreiner D., et al, OpenGL Programming Guide, Eighth Edition, (c)2013 Pearson Education, Inc 
 *
 * NOTES:
 * - Uses GLX (OpenGL extension for X Window), Ubuntu environment
 */

#include "debug.h"
// Included in debug.h
// #include "GL/freeglut.h"
// #include "GL/gl.h"
// #include "GL/glx.h"

void renderFunction()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(1.0, 1.0, 1.0);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(-0.5, -0.5);
  glVertex2f(-0.5, 0.5);
  glVertex2f(0.5, 0.5);
  glVertex2f(0.5, -0.5);
  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("OpenGL - First window demo");
  glutDisplayFunc(renderFunction);
  glutMainLoop();    
  return 0;
}
