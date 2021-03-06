/*
 * quatrotation.c
 *
 * 2015/12/21
 * Waheed Brown
 *
 * OpenGL Tutorial
 * http://www.cprogramming.com/tutorial/3d/quaternions.html
 */

#include "quaternion.h"

int main () {

  float point[4] = {10, 0, 0, 0}; // RH coord system
  float baseQ[4] = {1, 0, 0, 0}; // Must init base quaternion

  // Change rotation of an existing quaternion by 90 degrees
  float rotAxis[4] = {0, 0, 1, 0}; // z-axis
  float localRotQ[4];
  float totalRotQ[4];

  genLocalRot(localRotQ /* {w, x, y, z} */,
	      degToRad(90),
	      rotAxis /* {x, y, z, 0} */);

  //  Total rotation = local rotation * base quaternion
  qMultiply(totalRotQ, localRotQ, baseQ);

  // Build rotation matrix
  // Reference: http://www.cprogramming.com/tutorial/3d/quaternions.html
  float w, x, y, z;
  w = totalRotQ[0];
  x = totalRotQ[1];
  y = totalRotQ[2];
  z = totalRotQ[3];
  float rotMatrix[4][4] = { { 1 - (2 * y * y) - (2 * z * z),
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

  // Apply rotation to original point
  float newPoint[4];
  pointDotProduct(newPoint, point, rotMatrix);

  printf("\n");
  showQuaternion(localRotQ);
  printf("\n");
  showQuaternion(baseQ);
  printf("\n");
  showQuaternion(totalRotQ);
  printf("\n");
  showMatrix(rotMatrix);
  printf("\n");
  showPoint(newPoint);
  printf("\n");

  return 0;
}
