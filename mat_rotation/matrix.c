/*
 * matrix.c
 *
 * 2015/12/18
 * Waheed Brown
 *
 * OpenGL Tutorial
 * http://www.cprogramming.com/tutorial/3d/rotationMatrices.html
 */

#include "matrix.h"

// Pass by reference
void pointDotProduct(float* result, float* p, float m[][4]) {
  int i;
  for(i = 0; i < 4; ++i) {
    result[i] = ( p[0] * m[0][i] ) +
      ( p[1] * m[1][i] ) +
      ( p[2] * m[2][i] ) +
      ( p[3] * m[3][i] );
  }
}

void showPoint(float* p) {
  printf("{");

  int i;
  for(i = 0; i < 4; ++i) {
    printf("%f", p[i]);
    if(i >= 3) {
      break;
    } else {
      printf(",\t");
    }
  }

  printf("}\n");
}

/*
 * RAD to DEG -> 180/PI
 * DEG to RAD -> PI/180
 */
float radToDeg(const float rad) {
  return rad * 180/M_PI;
}

float degToRad(const float deg) {
  return deg * M_PI/180;
}

// Pass by reference
void matrixDotProduct(float result[][4], float A[][4], float B[][4]) {
  int i, j;
  for(i = 0; i < 4; ++i) {
    for(j = 0; j < 4; ++j) {
      result[i][j] = ( A[i][0] * B[0][j] ) +
	( A[i][1] * B[1][j] ) +
	( A[i][2] * B[2][j] ) +
	( A[i][3] * B[3][j] );
    }
  }
}

void showMatrix(float matrix[][4]) {
  printf("{ ");

  int i, j;
  for(i = 0; i < 4; ++i ) {
    printf("{");

    for(j = 0; j < 4; ++j) {
      printf("%f", matrix[i][j]);
      if( j >= 3) {
	break;
      } else {
	printf(",\t");
      }
    }

    printf("}");
    if(i >= 3) {
      break;
    } else {
      printf(",\n");
    }
  }

  printf(" }\n");
}
