/*
 * quatrotation.cpp
 *
 * 2015/12/21
 * Waheed Brown
 *
 * OpenGL Tutorial
 * http://www.cprogramming.com/tutorial/3d/quaternions.html
 */

#include <iostream>
#include "quaternion.h"
using namespace std;

int main () {

  float point[4] = {10, 0, 0, 0}; // RH coord system
  Quaternion baseQ(1, 0, 0, 0); // Base q must be initialized

  // Change rotation of an existing quaternion
  Point axis(0, 0, 1);
  Quaternion localRot = Quaternion::genLocalRot( Point::degToRad(90), axis);
  Quaternion totalRot = localRot * baseQ;

  // Build rotation matrix
  // Reference: http://www.cprogramming.com/tutorial/3d/quaternions.html
  float w, x, y, z;
  w = totalRot.getW();
  x = totalRot.getX();
  y = totalRot.getY();
  z = totalRot.getZ();
  float mElements[4][4] = { { 1 - (2 * y * y) - (2 * z * z),
			      (2 * x * y) - (2 * w * z),
			      (2 * x * z) + (2 * w * y),
			      0 },
			    { (2 * x * y) + (2 * w * z),
			      1 - (2 * x * x)  - (2 * z * z),
			      (2 * y * z) + (2 * w * x),
			      0 },
			    { (2 * x * z) - (2 * w * y),
			      (2 * y * z) - (2 * w * x),
			      1 - (2 * x * x) - (2 * y * y),
			      0 },
			    { 0, 0, 0, 1} };
  Matrix4x4 rotMatrix(mElements);

  // Apply rotation to original point
  float newPoint[4];
  Point::dotProduct(newPoint, point, rotMatrix.getElements());

  cout << endl;
  localRot.show();
  cout << endl;
  baseQ.show();
  cout << endl;
  totalRot.show();
  cout << endl;
  rotMatrix.show();
  cout << endl;
  Point::show(newPoint);
  cout << endl;

  // Generate rotated point

  return 0;
}
