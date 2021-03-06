/*
 * quaternion.c
 *
 * 2015/12/21
 * Waheed Brown
 *
 * OpenGL Tutorial - Quaternions
 * http://www.cprogramming.com/tutorial/3d/quaternions.html
 */

#include "quaternion.h"
// Included in quaternion.h
// #include <stdio.h>
// #include <math.h>

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
float radToDeg(float rad) {
  return rad * 180/M_PI;
}

float degToRad(float deg) {
  return deg * M_PI/180;
}

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

void showMatrix(float m[][4]) {
  printf("{ ");

  int i, j;
  for(i = 0; i < 4; ++i ) {
    printf("{");

    for(j = 0; j < 4; ++j) {
      printf("%f", m[i][j]);
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

/*
 * Quaternion multiplication:
 * http://www.cprogramming.com/tutorial/3d/quaternions.html
 */
void qMultiply(float* qM, float* q1, float* q2) {
  qM[0] = (q1[0] * q2[0]) - (q1[1] * q2[1]) - (q1[2] * q2[2]) - (q1[3] * q2[3]);
  qM[1] = (q1[0] * q2[1]) + (q1[1] * q2[0]) + (q1[2] * q2[3]) - (q1[3] * q2[2]);
  qM[2] = (q1[0] * q2[2]) - (q1[1] * q2[3]) + (q1[2] * q2[0]) + (q1[3] * q2[1]);
  qM[3] = (q1[0] * q2[3]) + (q1[1] * q2[2]) - (q1[2] * q2[1]) + (q1[3] * q2[0]);
}

float calcMagnitude(float* q) {
  return sqrtf( (q[0] * q[0]) + 
	       (q[1] * q[1]) + 
	       (q[2] * q[2]) + 
	       (q[3] * q[3]) );
}

void normalize(float *q) {
  float magnitude = calcMagnitude(q);
  q[0] = q[0] / magnitude;
  q[1] = q[1] / magnitude;
  q[2] = q[2] / magnitude;
  q[3] = q[3] / magnitude;
}

//Quaternion genLocalRot(float angle, Point &axis) {
void genLocalRot(float* qLocal /* {w, x, y, z} */,
		 float angle,
		 float* axis /* {x, y, z, 0} */) {
  qLocal[0] = cosf(angle / 2);
  qLocal[1] = ( axis[0] * sinf(angle / 2) );
  qLocal[2] = ( axis[1] * sinf(angle / 2) );
  qLocal[3] = ( axis[2] * sinf(angle / 2) );
}

void showQuaternion(float* q) {
  printf("{%f, %f, %f, %f}\n", q[0], q[1], q[2], q[3]);
}
