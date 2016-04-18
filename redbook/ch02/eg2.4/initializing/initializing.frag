#version 330 core
// FRAGMENT SHADER

// Saturday March 20, 2016
// initializing.frag
// Waheed Brown
//
// OpenGL Redbook - Chapter 2 - Example 2.4
//
// Reference:
// Shreiner, D., et. al., "OpenGL Programming Guide, 8th Ed.", (c) 2013 Pearson Education, Incw.

uniform Uniforms {
  vec3 translation;
  float scale;
  vec4 rotation;
  bool enabled;
};

in vec4 fColor;
out vec4 color;

void main()
{
  color = fColor;
}
