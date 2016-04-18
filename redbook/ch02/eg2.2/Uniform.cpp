///////////////////////////////////////////////////////
//
// Wednesday March 16, 2016
// Uniform.cpp
// Waheed Brown
//
// OpenGL Redbook - Chapter 2 - Example 2.2
// 
// Reference:
//
// Shreiner, D., et. al., "OpenGL Programming Guide, 8th Ed.", (c) 2013 Pearson Education, Incw.
//
///////////////////////////////////////////////////////


#define GLEW_STATIC
#include <GL/glew.h>
#include "GL/freeglut.h" // replace GL/gl.h
#include <iostream>

#include "LoadShaders.h"

using namespace std;

int main(int argc, char **argv)
{
  // EVERY OpenGL program requires an OpenGL context
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutInitContextVersion(3, 3);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glutCreateWindow( argv[0] );

  // Initialize the GLEW library
  glewExperimental = GL_TRUE;
  if ( glewInit() /* GLEW_OK = 0 */ ) {
    cerr << "Unable to initialize GLEW ... exiting" << endl;
    exit(EXIT_FAILURE);
  }

  // Load the shader with the eg2.2 uniform variables
  ShaderInfo shaders[] = {
    { GL_VERTEX_SHADER, "uniform.vert" },
    { GL_NONE, NULL }
  };
  GLuint program = LoadShaders(shaders); // from eg1.1

  ////////////////////////////////
  //
  // Example 2.2 starts here
  //
  ////////////////////////////////
  
  GLint timeLoc; // Uniform index for variable "time" in shader
  GLfloat timeValue; // Application time

  timeLoc = glGetUniformLocation(program, "time");
  glUniform1f(timeLoc, timeValue);

  return 0;
}
