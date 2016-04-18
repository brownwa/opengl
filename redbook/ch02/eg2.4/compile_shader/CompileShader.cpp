///////////////////////////////////////////////////////
//
// Tuesday March 15, 2016
// CompileShader.cpp
// Waheed Brown
//
// OpenGL Redbook - Chapter 2 - Example 2.4
// 
// USAGE:
//
// $ ./CompileShader <path_to_shader_file>
//
// NOTES:
//
// In chapter 1, example 1.1, the author uses LoadShaders.cpp
// to handle both compiling and linking his two shaders. As
// well he passes the shaders back into his OpenGL program
// for coloring in the triangles.
//
// What we're attempting below is to simply compile one shader,
// without calling the linking stage. The reason we do this is
// to be able to debug the sample code in chapter 2, examples
// 2.1 through 2.4. Without a GLSL comiler, we would be coding
// blind and not really learning anything.
//
// Hence the below program, a very unpretty, rudimentary GLSL
// compiler that takes only a single file name as it's input.
// S/he doesn't need to be pretty to dance, s/he just has to
// know the steps.
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
#include <cstdio>
#include <cstdlib>

using namespace std;

// Handle shader compilation errors
int HandleErrors(GLuint shader)
{
  GLint success = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

  if(success != GL_FALSE) {
    cout << "Shader compiled successfully." << endl;
    return EXIT_SUCCESS;
  } // else
  cerr << "Shader compilation failed." << endl;

  // Capture error log
  GLint logSize = 0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
  GLchar* errorLog = new GLchar[logSize];
  GLsizei bytesCaptured;
  glGetShaderInfoLog(shader,
		     logSize,
		     &bytesCaptured,
		     errorLog);

  cerr << errorLog << endl;
  
  // Free memory
  delete[] errorLog;

  return EXIT_FAILURE; // = -1
}

int main(int argc, char **argv)
{
  const char* filename = argv[1];
  FILE* infile = fopen(filename, "rb");
  // Using "rb" option to read as binary file, so
  // that we can copy byte data into the shader object.
  // My guess is that this is faster than copying
  // character/string data(?)

  if(!infile) {
    cerr << "Unable to open " << filename << endl;
    cout << "\nUsage: $ ./CompileShader <path_to_shader_file>\n";
    cout << endl;
    return 1;
  }
  
  // Read file
  fseek(infile,
	0 /* zero byte offset from origin */,
	SEEK_END /* position to EOF */);
  int len = ftell(infile); // number of bytes from start
  fseek(infile, 0, SEEK_SET); // position back to start

  // Assuming +1 is for NULL termination of the string(?)
  GLchar* source = new GLchar[len + 1];
  fread(source,
	1 /* 1 byte per element */,
	len /* num bytes */,
	infile);
  fclose(infile);
  source[len] = 0; // NULL terminate string
  const GLchar* csource = const_cast<const GLchar*>(source);

  // glCreateShader requires an OpenGL context
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutInitContextVersion(3, 3);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glutCreateWindow( argv[0] );

  // Mandatory OpenGL extensions check for glCreateShader
  glewExperimental = GL_TRUE;
  if ( glewInit() ) {
    cerr << "Unable to initialize GLEW ... exiting" << endl;
    exit(EXIT_FAILURE);
  }
  GLuint myShader = glCreateShader(GL_VERTEX_SHADER);
  //  GLuint myShader = glCreateShader(GL_FRAGMENT_SHADER);

  // Feed the shader text file into the shader object
  glShaderSource(myShader,
		 1 /* 1 string */,
		 &csource,
		 NULL /* assume all strings NULL terminated */);

  // Compile the shader
  glCompileShader(myShader);
  int compilerStatus = HandleErrors(myShader);
  // Here a redundant return value is used to encourage
  // CompileShader to fail gracefully. Graceful failure
  // in this case means free all allocated memory
  // (see below).
  
  // Free memory
  delete[] source;
  glDeleteShader(myShader);
  // This last line is important because we must
  // always undo the effects of glCreateShader, which
  // is essentially allocating GPU memory. See the
  // man pages for glDeleteShader for details. Install
  // the OpenGL man pages (Ubuntu) as follows:
  //
  // $ sudo apt-get update
  // $ sudo apt-get install opengl-4-man-doc
  // $ sudo apt-get upgrade opengl-4-man-doc
  //
  // NOTE: You can opt out of upgrading additional
  //       packages if apt prompts you.  

  return compilerStatus; // -1 on compiler failure
}
