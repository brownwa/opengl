#version 330 core
//VERTEX SHADER

// Tuesday March 15, 2016
// initializing.vert
// Waheed Brown
//
// OpenGL Redbook - Chapter 2 - Example 2.4
//
// Reference:
// Shreiner, D., et. al., "OpenGL Programming Guide, 8th Ed.", (c) 2013 Pearson Education, Incw.

// Vertex and fragment shaders that share a block
// of uniforms named "Uniforms"  
//
uniform Uniforms {
  vec3 translation;
  float scale;
  vec4 rotation;
  bool enabled;
};

// Inputs
in vec2 vPos;
in vec3 vColor;
out vec4 fColor;

void main()
{
  vec3  pos = vec3(vPos, 0.0);
  float angle = radians( rotation[0] );

  // We will rotate around x-axis
  //
  // NOTE: This below method seems to be an
  // optimized versoin of the 4x4 matrix
  // rotation method discussed here:
  //
  // http://www.cprogramming.com/tutorial/3d/rotation.html
  //
  // However, the below S matrix looks like one for the
  // sine component of the rotation, using the
  // LEFT-HAND-RULE. But OpenGL is supposed to use the
  // right-hand-rule(?). This is confusing for me.
  //
  vec3  axis = normalize(rotation.yzw);
  mat3  I = mat3(1.0);
  mat3  S = mat3(      0, -axis.z,  axis.y,
		  axis.z,       0, -axis.x,
		 -axis.y,  axis.x,       0);
  mat3 uuT = outerProduct(axis, axis);

  // Identity matrix - outer Product =
  // cosine component of rotation matrix elements; I.E.,
  //
  // S is the [s]ine component of the rotation matrix
  // elements
  //
  // Notice how that the way the matricies are
  // structured, the cosine component term only exists
  // on the diagonal. This is because it is constructed
  // using the identiy matrix.
  //
  // Likewise, the sine components (matrix S) only exist
  // outside of the diagonal.
  //
  // Again, this left-hand-rule transformation matrix
  // can be viewed here:
  //
  // http://www.cprogramming.com/tutorial/3d/rotation.html
  // 
  mat3 rot = uuT + ( cos(angle) * (I - uuT) )
                 + ( sin(angle) * S );

  // 2D order of transformation (algebra)
  // 1. Compression
  // 2. Stretching
  // 3. Horizontal translation
  // 4. Reflection
  // 5. Vertical translation
  //
  // OpenGL order of transformation
  // 1. Scaling
  // 2. Rotation
  // 3. Translation
  //
  pos *= scale;
  pos *= rot;
  pos += translation;

  // RGBA ([A]lpha = opacity)
  fColor = vec4(scale, scale, scale, 1);
  gl_Position = vec4(pos, 1); // quarternion (x, y, z, w)
}
