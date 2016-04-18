#version 330 core
//VERTEX SHADER

// Sunday March 13, 2016
// uniform.vert
// Waheed Brown
//
// OpenGL Redbook - Chapter 2 - Example 2.3
//
// Reference:
// Shreiner, D., et. al., "OpenGL Programming Guide, 8th Ed.", (c) 2013 Pearson Education, Incw.

uniform Matricies {
	mat4 ModelView;
	mat4 Projection;
	mat4 Color;
};

layout(shared, row_major) uniform Quaternions {
       mat4 quaternion01;
       mat4 quaternion02;
       mat4 quaternionResult;
};

void main()
{
	
}