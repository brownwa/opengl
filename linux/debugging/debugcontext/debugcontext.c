/*
 * debugcontext.c
 * Sunday March 6, 2016
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

#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GL/glx.h"
#include <stdbool.h>

// Callback for creating a GLXContext
// https://www.opengl.org/wiki/Tutorial:_OpenGL_3.0_Context_Creation_(GLX)
//
typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);

// Creating a Debug Context Using GLX
GLXContext CreateDebugContext(Display* dpy,
			      GLXFBConfig config,
			      GLXContext share_context,
			      int major, int minor)
{
  const int attriblist[] =
    {
      // Major version of context
      GLX_CONTEXT_MAJOR_VERSION_ARB, major,
      // Minor version of context
      GLX_CONTEXT_MINOR_VERSION_ARB, minor,
      // Always select a core profile
      GLX_CONTEXT_PROFILE_MASK_ARB,
      GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
      // Turn on the debug context
      GLX_CONTEXT_FLAGS_ARB,
      GLX_CONTEXT_DEBUG_BIT_ARB,
      0
    };

  // Need to point to the callback function before calling.
  // Essentially we're creating a void pointer that gets
  // assigned to a callback function pointer when used.
  glXCreateContextAttribsARBProc glXCreateContextAttribsARB = 0;
  return glXCreateContextAttribsARB(dpy,
				    config,
				    share_context,
				    true,
				    attriblist);
}

/* // Prototype for the Debug Message Callback Function */
/* typedef void (APIENTRY *DEBUGPROC)(GLenum source, */
/* 				   GLenum type, */
/* 				   GLuint id, */
/* 				   GLenum severity, */
/* 				   GLsizei length, */
/* 				   const GLchar* message, */
/* 				   void* userParam); */

/* void APIENTRY DebugCallbackFunction(GLenum source, */
/* 				    GLenum type, */
/* 				    GLuint id, */
/* 				    GLenum severity, */
/* 				    GLsizei length, */
/* 				    const GLchar* message, */
/* 				    void* userParam); */


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
