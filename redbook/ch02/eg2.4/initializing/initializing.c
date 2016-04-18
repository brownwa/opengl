///////////////////////////////////////////////////////
//
// Saturday March 20, 2016
// Initializing.c
// Waheed Brown
//
// OpenGL Redbook - Chapter 2 - Example 2.4
//
// NOTE:
//
// I am going to take a guess and assume that best practice
// is to write shader handlers in C, for performance
// reasons. LoadShaders.cpp at first appears to be an
// exception. On closer inspection though, LoadShaders
// only uses C++ heap assignment (new) and deletion, wrt
// file handling. The actual shader management limits itself
// to C.
//
// Reference:
//
// Shreiner, D., et. al., "OpenGL Programming Guide, 8th Ed.", (c) 2013 Pearson Education, Incw.
//
///////////////////////////////////////////////////////

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <string.h>

#include "LoadShaders.h"

// Convert GLSL types to storage sizes
//
// This function uses a very clever switch statement
// feature. By defining a macro for CASE, one can
// easily define each switch case statement on one
// line. This makes the code a lot more compact.
//
// The complicated part is understanding the macro.
// All it does is define a function signature,
// CASE(), along with the function body. The function
// body simply a case statment block, compacted
// onto one line. Even the break statement that ends
// a case block is there.
//
// Note that the backslash "\" allows the macro to be
// defined on more than one line.
size_t TypeSize(GLenum type)
{
  size_t size;

#define CASE(Enum, Count, Type) \
  case Enum: size = Count * sizeof(Type); break

  switch(type) {
    CASE(GL_FLOAT, 1, GLfloat);
    CASE(GL_FLOAT_VEC2, 2, GLfloat);
    CASE(GL_FLOAT_VEC3, 3, GLfloat);
    CASE(GL_FLOAT_VEC4, 4, GLfloat);
    CASE(GL_INT, 1, GLint);
    CASE(GL_INT_VEC2, 2, GLint);
    CASE(GL_INT_VEC3, 3, GLint);
    CASE(GL_INT_VEC4, 4, GLint);
    CASE(GL_UNSIGNED_INT, 1, GLuint);
    CASE(GL_UNSIGNED_INT_VEC2, 2, GLuint);
    CASE(GL_UNSIGNED_INT_VEC3, 3, GLuint);
    CASE(GL_UNSIGNED_INT_VEC4, 4, GLuint);
    CASE(GL_BOOL, 1, GLboolean);
    CASE(GL_BOOL_VEC2, 2, GLboolean);
    CASE(GL_BOOL_VEC3, 3, GLboolean);
    CASE(GL_BOOL_VEC4, 4, GLboolean);
    CASE(GL_FLOAT_MAT2, 4, GLfloat);
    CASE(GL_FLOAT_MAT2x3, 6, GLfloat);
    CASE(GL_FLOAT_MAT2x4, 8, GLfloat);
    CASE(GL_FLOAT_MAT3, 9, GLfloat);
    CASE(GL_FLOAT_MAT3x2, 6, GLfloat);
    CASE(GL_FLOAT_MAT3x4, 12, GLfloat);
    CASE(GL_FLOAT_MAT4, 16, GLfloat);
    CASE(GL_FLOAT_MAT4x2, 8, GLfloat);
    CASE(GL_FLOAT_MAT4x3, 12, GLfloat);
#undef CASE

  default:
    fprintf(stderr, "Unknown type: 0x%x\n", type);
    exit(EXIT_FAILURE); // -1
    break;
  }
  
  return size;
}

void init()
{
  GLuint program;
  glClearColor(1, 0, 0, 1); // red

  // Load the shader with the eg2.4 uniform variables
  ShaderInfo shaders[] = {
    { GL_VERTEX_SHADER, "initializing.vert" },
    { GL_FRAGMENT_SHADER, "initializing.frag" },
    { GL_NONE, NULL }
  };

  program = LoadShaders(shaders);
  glUseProgram(program);

  // Initialize uniform values in uniform block "Uniforms"
  //
  // Uniform Block Object, UBO
  //
  GLuint uboIndex;
  GLint uboSize;
  GLuint ubo;
  GLvoid *buffer;
  // Making buffer of type GLvoid* enerates compile time
  // warnings due to pointer arithmetic. The best
  // solution is to programatically determine
  // the best type for this (uniform) buffer But it
  // would be tricky to make it robust. Another option
  // is to use the "-w" compile line option to suppress
  // warnings.
  

  // Find the uniform buffer index for "Uniforms", and
  // determine the block members' sizes
  uboIndex = glGetUniformBlockIndex(program, "Uniforms");

  // Determine the uniform block object size
  glGetActiveUniformBlockiv(program, // program ID
			    uboIndex, // index in uniform block
			    GL_UNIFORM_BLOCK_DATA_SIZE,
			    &uboSize); // return value
  buffer = malloc(uboSize);

  if(buffer == NULL) {
    fprintf(stderr, "Unable to allocate buffer\n");
    exit(EXIT_FAILURE); // -1
  }
  else {
    enum { Translation, Scale, Rotation, Enabled, NumUniforms };

    // Values to be stored in the buffer object
    GLfloat scale = 0.5;
    GLfloat translation[] = {0.1, 0.1, 0.0};
    GLfloat rotation[] = {90, 0.0, 0.0, 1.0};
    GLboolean enabled = GL_TRUE;

    // Since we know the names of the uniforms in our
    // block, make an array of those values
    const char* names[NumUniforms] = {
      "translation",
      "scale",
      "rotation",
      "enabled"
    };


    // Query the necessary attributes to determine
    // where in the buffer we should write the values
    GLuint indicies[NumUniforms];
    GLint size[NumUniforms];
    GLint offset[NumUniforms];
    GLint type[NumUniforms];

    // Get the indicies for the named uniform GLSL variables
    glGetUniformIndices(program,
			 NumUniforms,
			 names,
			 indicies /* return values */);
    
    // Get the offset, size and type for each
    // index/uniform variable
    glGetActiveUniformsiv(program,
			  NumUniforms,
			  indicies,
			  GL_UNIFORM_OFFSET,
			  offset /* return values populate
				    this "offset" array */);
    glGetActiveUniformsiv(program,
			  NumUniforms,
			  indicies,
			  GL_UNIFORM_SIZE,
			  size /* return values */);
    glGetActiveUniformsiv(program,
			  NumUniforms,
			  indicies,
			  GL_UNIFORM_TYPE,
			  type /* return values */);

    // Copy the uniform values into the buffer
    memcpy(buffer + offset[Scale], &scale,
	   size[Scale] * TypeSize( type[Scale] ));
    memcpy(buffer + offset[Translation], &translation,
	   size[Translation] * TypeSize( type[Translation] ));
    memcpy(buffer + offset[Rotation], &rotation,
	   size[Rotation] * TypeSize( type[Rotation] ));
    memcpy(buffer + offset[Enabled], &enabled,
	   size[Enabled] * TypeSize( type[Enabled] ));

    // Create the uniform buffer object, initialize
    // its storage and associate it with the shader
    // program
    glGenBuffers(1, &ubo);
    glBindBuffer(GL_UNIFORM_BUFFER, ubo);
    glBufferData(GL_UNIFORM_BUFFER, uboSize,
		 buffer, GL_STATIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, uboIndex, ubo);
  } // else

  // Perform some transformations with the shader uniform
  // variables
  //
  // [code]
  
  // Free memory
  glBindBuffer(GL_UNIFORM_BUFFER, 0); // unbind ubo
  glDeleteBuffers(1, &ubo); // not really freeing memory but
                            // frees buffer index for future use
  free(buffer);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutInitContextVersion(3, 3);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glutCreateWindow( argv[0] );

  glewExperimental = GL_TRUE;
  if( glewInit() /* GLEW_OK = 0 */ ) {
    fprintf(stderr, "Unable to initialize GLEW ... exiting\n");
    exit(EXIT_FAILURE);
  }
  
  
  ////////////////////////////////
  //
  // Example 2.4 starts here
  //
  ////////////////////////////////

}
