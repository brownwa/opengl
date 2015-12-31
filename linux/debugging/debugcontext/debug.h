/*
 * debug.h
 * 2015/12/29
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

// Creating a Debug Context Using GLX
GLXContext CreateDebugContext(Display* dpy,
			      GLXFBConfig config,
			      GLXContext share_context,
			      int major, int minor);

// Prototype for the Debug Message Callback Function
typedef void (APIENTRY *DEBUGPROC)(GLenum source,
				   GLenum type,
				   GLuint id,
				   GLenum severity,
				   GLsizei length,
				   const GLchar* message,
				   void* userParam);

void APIENTRY DebugCallbackFunction(GLenum source,
				    GLenum type,
				    GLuint id,
				    GLenum severity,
				    GLsizei length,
				    const GLchar* message,
				    void* userParam);

