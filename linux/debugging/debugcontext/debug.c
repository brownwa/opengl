/*
 * debug.c
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

#include <stdio.h>
#include <stdbool.h>
#include "debug.h"
// Included in debug.h
// #include "GL/freeglut.h"
// #include "GL/gl.h"
// #include "GL/glx.h"

// Placeholder function for OpenGL 2.1
GLXContext glXCreateContextAttribsARB(Display* aDpy,
				      GLXFBConfig aConfig,
				      GLXContext a_share_context,
				      bool aFlag,
				      const int* aAttriblist)
{
  GLXContext myContext;
  return myContext;
}

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

  return glXCreateContextAttribsARB(dpy, config,
  				    share_context,
  				    true, attriblist);
}

// Prototype for the Debug Message Callback Function
void APIENTRY DebugCallbackFunction(GLenum source,
				      GLenum type,
				      GLuint id,
				      GLenum severity,
				      GLsizei length,
				      const GLchar* message,
				      void* userParam)
{
  // 0x%04X: 4 digit hexadecimal integer with leading zeros
  printf("Debug Message: SOURCE(0x%04X), "
	 "TYPE(0x%04X), "
	 "ID(0x%08X), "
	 "SEVERITY(0x%04X), \"%s\"\n",
	 source, type, id, severity, message);
}
