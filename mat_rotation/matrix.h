/*
 * matrix.h
 *
 * 2015/12/18
 * Waheed Brown
 *
 * OpenGL Tutorial
 * http://www.cprogramming.com/tutorial/3d/rotationMatrices.html
 */

#include <stdio.h>
#include <math.h>

// Compiler doesn't have sinf or cosf in math.h
#define sinf(x) (float)sin( (double)(x) )
#define cosf(x) (float)cos( (double)(x) )

// Points
void pointDotProduct(float* result, float* p, float m[][4]);
void showPoint(float* p);
float radToDeg(const float rad);
float degToRad(const float deg);

// Matricies
void matrixDotProduct(float result[][4], float A[][4], float B[][4]);
void showMatrix(float matrix[][4]);
