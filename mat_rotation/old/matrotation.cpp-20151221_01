/*
 * matrotation.cpp
 *
 * 2015/12/16
 * Waheed Brown
 *
 * OpenGL Tutorial
 * http://www.cprogramming.com/tutorial/3d/rotationMatrices.html
 */

#include <math.h>
#include "matrix.h"
#include <iostream>
using namespace std;

int main () {

  double point[] = {2, 2, 2, 0}; // RH coord system
  double phi = Point::degToRad(90); // Angles in radians
  double theta = Point::degToRad(90);
  double psi = Point::degToRad(90);
  
  double matRotationX[4][4] = { {1, 0, 0, 0},
				{0, cos(phi), -sin(phi), 0},
				{0, sin(phi), cos(phi), 0},
				{0, 0, 0, 1} };

  double matRotationY[4][4] = { {cos(theta), 0, sin(theta), 0},
				{0, 1, 0, 0},
				{-sin(theta), 0, cos(theta), 0},
				{0, 0, 0, 1} };

  double matRotationZ[4][4] = { {cos(psi), sin(psi), 0, 0},
				{-sin(psi), cos(psi), 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1} };

  double matRotationTemp[4][4];
  double matRotationTotal[4][4];
  double newPoint[4];

  // Total Rotation = MatX * MatY * MatZ
  Matrix::dotProduct(matRotationTemp, matRotationX, matRotationY);
  Matrix::dotProduct(matRotationTotal, matRotationTemp, matRotationZ);
  Point::dotProduct(newPoint, point, matRotationTotal);

  cout << endl;
  Point::showPoint(point);
  cout << endl;
  Matrix::showMatrix(matRotationX);
  cout << endl;
  Matrix::showMatrix(matRotationY);
  cout << endl;
  Matrix::showMatrix(matRotationZ);
  cout << endl;
  Matrix::showMatrix(matRotationTotal);
  cout << endl;
  Point::showPoint(newPoint);
  cout << endl;

  return 0;
}
