/*
 * debug.cpp
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
#include "debug.h"

GLXContext Debug::CreateDebugContext(Display* dpy,
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

  // return glXCreateContextAttribsARB(dpy, config,
  // 				    share_context,
  // 				    True, attriblist);

  // Testing lines
  GLXContext myContext;
  return myContext;
}
