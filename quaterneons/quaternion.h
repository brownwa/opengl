/*
 * quaternion.h
 *
 * 2015/12/21
 * Waheed Brown
 *
 * OpenGL Tutorial - Quaternions
 * http://www.cprogramming.com/tutorial/3d/quaternions.html
 */

#include <stdio.h>
#include <math.h>

// Old version of math.h without sinf or cosf
#define sinf(x) (float)sin( (double)(x) )
#define cosf(x) (float)cos( (double)(x) )
#define sqrtf(x) (float)sqrt( (double)(x) )

// Point (4 element array, {x, y, z, 0})
void pointDotProduct(float* result, float* p, float m[][4]);
void showPoint(float* p);
float radToDeg(float rad);
float degToRad(float deg);

// Matrix (Always 4x4)
void MatrixDotProduct(float result[][4], float A[][4], float B[][4]);
void showMatrix(float m[][4]);

// Quaternion (4 element array, {w, x, y, z})
void qMultiply(float* result, float* q1, float* q2);
float calcMagnitude(float* q);
void normalize(float *q);
void genLocalRot(float* qLocal /* {w, x, y, z} */,
		 float angle,
		 float* axis /* {x, y, z, 0} */);
void showQuaternion(float* q);
