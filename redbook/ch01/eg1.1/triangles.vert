#version 330 core
//VERTEX SHADER

// Saturday March 12, 2016
// traingles.vert
// Waheed Brown
//
// OpenGL Redbook - Chapter 1 - Example 1.2
//
// This is a simple, pass-through, vertex shader
// that just passes along vertex information to
// the next stage in the OpenGL rendering pipeline.
//
// Reference:
// Shreiner, D., et. al., "OpenGL Programming Guide, 8th Ed.", (c) 2013 Pearson Education, Incw.

layout(location = 0) in vec4 vPosition;

void main()
{
     gl_Position = vPosition;
}