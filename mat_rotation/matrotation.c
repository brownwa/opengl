/*
 * matrotation.c
 *
 * 2015/12/16
 * Waheed Brown
 *
 * OpenGL Tutorial
 * http://www.cprogramming.com/tutorial/3d/rotationMatrices.html
 */

#include "matrix.h"
// Included in matrix.h
// #include <stdio.h>
// #include <math.h>

int main (int argc, char** argv) {

  float point[] = {2, 2, 2, 0}; // RH coord system
  float phi = degToRad(90); // Angles in radians
  float theta = degToRad(90);
  float psi = degToRad(90);
  
  float matRotationX[4][4] = { {1, 0, 0, 0},
			       {0, cosf(phi), -sinf(phi), 0},
			       {0, sinf(phi), cosf(phi), 0},
			       {0, 0, 0, 1} };

  float matRotationY[4][4] = { {cosf(theta), 0, sinf(theta), 0},
			       {0, 1, 0, 0},
			       {-sinf(theta), 0, cosf(theta), 0},
			       {0, 0, 0, 1} };

  float matRotationZ[4][4] = { {cosf(psi), sinf(psi), 0, 0},
			       {-sinf(psi), cosf(psi), 0, 0},
			       {0, 0, 1, 0},
			       {0, 0, 0, 1} };

  float matRotationTemp[4][4];
  float matRotationTotal[4][4];
  float newPoint[4];

  // Total Rotation = MatX * MatY * MatZ
  matrixDotProduct(matRotationTemp, matRotationX, matRotationY);
  matrixDotProduct(matRotationTotal, matRotationTemp, matRotationZ);
  pointDotProduct(newPoint, point, matRotationTotal);

  printf("\n");
  showPoint(point);
  printf("\n");
  showMatrix(matRotationX);
  printf("\n");
  showMatrix(matRotationY);
  printf("\n");
  showMatrix(matRotationZ);
  printf("\n");
  showMatrix(matRotationTotal);
  printf("\n");
  showPoint(newPoint);
  printf("\n");

  return 0;
}
