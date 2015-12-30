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

class Debug
{
 private:
  Display* _dpy;
  GLXFBConfig _config;
  GLXContext _share_context;
  int _major;
  int _minor;

 public:
  Debug() {}
  Debug(Display* newDpy,
	GLXFBConfig newConfig,
	GLXContext new_share_context,
	int newMajor, int newMinor) :
      _dpy(newDpy),
      _config(newConfig),
      _share_context(new_share_context),
      _major(newMajor),
      _minor(newMinor) {}
  GLXContext CreateDebugContext(Display* dpy,
				       GLXFBConfig config,
				       GLXContext share_context,
				       int major, int minor);
};
