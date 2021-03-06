///////////////////////////////////////////////////////
//
// Saturday March 5, 2016
// traingles.cpp
// Waheed Brown
//
// OpenGL Redbook - Chapter 1 - Example 1.1
// 
// Reference:
// Shreiner, D., et. al., "OpenGL Programming Guide, 8th Ed.", (c) 2013 Pearson Education, Incw.
//
///////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "vgl.h"
#include "LoadShaders.h"
#include "GL/freeglut.h"

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

//-----------------------------------------------------
//
// init
//

void init(void)
{
  glGenVertexArrays(NumVAOs, VAOs);
  glBindVertexArray( VAOs[Triangles] );

  GLfloat verticies[NumVertices][2] = {
    { -0.90, -0.90 }, // Triangle 1
    { 0.85, -0.90 },
    { -0.90, 0.85 },
    { 0.90, -0.85 }, // Triangle 2
    { 0.90, 0.90 },
    { -0.85, 0.90 }
  };

  glGenBuffers(NumBuffers, Buffers);
  glBindBuffer( GL_ARRAY_BUFFER, Buffers[ArrayBuffer] );
  glBufferData( GL_ARRAY_BUFFER, sizeof(verticies),
		verticies, GL_STATIC_DRAW);

  // Make sure these shader files exist or it will cause
  // issue with glutInitContextVersion()
  //
  ShaderInfo shaders[] = {
    { GL_VERTEX_SHADER, "triangles.vert" },
    { GL_FRAGMENT_SHADER, "triangles.frag" },
    { GL_NONE, NULL }
  };

  GLuint program = LoadShaders(shaders);
  glUseProgram(program);

  glVertexAttribPointer( vPosition, 2, GL_FLOAT,
			 GL_FALSE, 0, BUFFER_OFFSET(0) );
  glEnableVertexAttribArray(vPosition);
  //  glClearColor(0.0, 1.0, 0.0, 1.0); // Set BG color in init
                                        // const for duration of
                                        // program
}

//-----------------------------------------------------
//
// display
//

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glBindVertexArray( VAOs[Triangles] );
  glDrawArrays(GL_TRIANGLES, 0, NumVertices);

  glFlush();
}

//-----------------------------------------------------
//
// main
//

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutInitContextVersion(3, 3); // Make sure shaders defined
                                // or will cause issues
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glutCreateWindow( argv[0] );

  // Turn on support for experimental drivers
  // http://stackoverflow.com/questions/8302625/segmentation-fault-at-glgenvertexarrays-1-vao
  //  
  glewExperimental = GL_TRUE;
  if ( glewInit() ) {
    
    // cerr (C++ stream)
    // stderr (C file handle)
    cerr << "Unable to initialize GLEW ... exiting" << endl;
    exit(EXIT_FAILURE);
  }

  init();

  glutDisplayFunc(display);

  glutMainLoop();
}
