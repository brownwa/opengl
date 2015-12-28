/*
 * quaternion.cpp
 *
 * 2015/12/21
 * Waheed Brown
 *
 * OpenGL Tutorial - Quaternions
 * http://www.cprogramming.com/tutorial/3d/quaternions.html
 */

#include <math.h>
#include "quaternion.h"
// Included in quaternion.h
// #include <iostream>
// using namespace std;

// Pass by reference
void Point::dotProduct(float* result, float* p, float m[][4]) {
  for(size_t i = 0; i < 4; ++i) {
    result[i] = ( p[0] * m[0][i] ) +
      ( p[1] * m[1][i] ) +
      ( p[2] * m[2][i] ) +
      ( p[3] * m[3][i] );
  }
}

void Point::show(float* p) {
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
float Point::radToDeg(const float rad) {
  return rad * 180/M_PI;
}

float Point::degToRad(const float deg) {
  return deg * M_PI/180;
}

Matrix4x4::Matrix4x4(const float newElements[][4]) {
  for(size_t i = 0; i < 4; ++i) {
    for(size_t j = 0; j < 4; ++j) {
      _elements[i][j] = newElements[i][j];
    }
  }
}

void Matrix4x4::dotProduct(float result[][4], float A[][4], float B[][4]) {
  for(size_t i = 0; i < 4; ++i) {
    for(size_t j = 0; j < 4; ++j) {
      result[i][j] = ( A[i][0] * B[0][j] ) +
	( A[i][1] * B[1][j] ) +
	( A[i][2] * B[2][j] ) +
	( A[i][3] * B[3][j] );
    }
  }
}

//void Matrix4x4::show(float matrix[][4]) {
void Matrix4x4::show() const {
  cout << "{ ";

  for(size_t i = 0; i < 4; ++i ) {
    cout << '{';

    for(size_t j = 0; j < 4; ++j) {
      cout << _elements[i][j];
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

/*
 * Quaternion multiplication:
 * http://www.cprogramming.com/tutorial/3d/quaternions.html
 */
Quaternion Quaternion::operator*(const Quaternion &o) {
  Quaternion tempQ;

  tempQ._w = (_w * o._w) - (_x * o._x) - (_y * o._y) - (_z * o._z);
  tempQ._x = (_w * o._x) + (_x * o._w) + (_y * o._z) - (_z * o._y);
  tempQ._y = (_w * o._y) - (_x * o._z) + (_y * o._w) + (_z * o._x);
  tempQ._z = (_w * o._z) + (_x * o._y) - (_y * o._x) + (_z * o._w);

  return tempQ;
}

float Quaternion::calcMagnitude(const float w, const float x,
				 const float y, const float z) {
  return sqrt( (w * w) + (x * x) + (y * y) + (z * z) );
}

void Quaternion::normalize() {
  float magnitude = calcMagnitude(_w, _x, _y, _z);
  _w = _w / magnitude;
  _x = _x / magnitude;
  _y = _y / magnitude;
  _z = _z / magnitude;
}

Quaternion Quaternion::genLocalRot(const float angle, const Point &axis) {
  Quaternion tempQ( cosf(angle / 2),
		    ( axis.getX() * sinf(angle / 2) ),
		    ( axis.getY() * sinf(angle / 2) ), 
		    ( axis.getZ() * sinf(angle / 2) ) );

  return tempQ;
}

void Quaternion::show() const {
  cout << "{" << _w << ", "<< _x << ", " <<
    _y << ", " <<_z<< "}" << endl;
}
