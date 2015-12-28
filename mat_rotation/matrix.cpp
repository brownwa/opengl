/*
 * matrix.cpp
 *
 * 2015/12/18
 * Waheed Brown
 *
 * OpenGL Tutorial
 * http://www.cprogramming.com/tutorial/3d/rotationMatrices.html
 */

#include <iostream>
#include <math.h>
#include "matrix.h"
using namespace std;

// Pass by reference
void Point::dotProduct(double* result, double* p, double m[][4]) {
  for(size_t i = 0; i < 4; ++i) {
    result[i] = ( p[0] * m[0][i] ) +
      ( p[1] * m[1][i] ) +
      ( p[2] * m[2][i] ) +
      ( p[3] * m[3][i] );
  }
}

void Point::showPoint(double* p) {
  cout << '{';

  for(size_t i = 0; i < 4; ++i) {
    cout << p[i];
    if(i >= 3) {
      break;
    } else {
      cout << ",\t";
    }
  }

  cout << '}' << endl;
}

/*
 * RAD to DEG -> 180/PI
 * DEG to RAD -> PI/180
 */
double Point::radToDeg(const double rad) {
  return rad * 180/M_PI;
}

double Point::degToRad(const double deg) {
  return deg * M_PI/180;
}

// Pass by reference
void Matrix::dotProduct(double result[][4], double A[][4], double B[][4]) {
  for(size_t i = 0; i < 4; ++i) {
    for(size_t j = 0; j < 4; ++j) {
      result[i][j] = ( A[i][0] * B[0][j] ) +
	( A[i][1] * B[1][j] ) +
	( A[i][2] * B[2][j] ) +
	( A[i][3] * B[3][j] );
    }
  }
}

void Matrix::showMatrix(double matrix[][4]) {
  cout << "{ ";

  for(size_t i = 0; i < 4; ++i ) {
    cout << '{';

    for(size_t j = 0; j < 4; ++j) {
      cout << matrix[i][j];
      if( j >= 3) {
	break;
      } else {
	cout << ",\t";
      }
    }

    cout << '}';
    if(i >= 3) {
      break;
    } else {
      cout << ',' << endl;
    }
  }

  cout << " }" << endl;
}
