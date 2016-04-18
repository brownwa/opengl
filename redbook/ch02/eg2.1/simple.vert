#version 330 core
//VERTEX SHADER

// Sunday March 13, 2016
// simple.vert
// Waheed Brown
//
// OpenGL Redbook - Chapter 2 - Example 2.2
//
// Reference:
// Shreiner, D., et. al., "OpenGL Programming Guide, 8th Ed.", (c) 2013 Pearson Education, Incw.

in vec4 vPosition;
in vec4 vColor;

out vec4 color;

uniform mat4 ModelViewProjectionMatrix;

void main()
{
	color = vColor;
	gl_Position = ModelViewProjectionMatrix * vPosition;
}