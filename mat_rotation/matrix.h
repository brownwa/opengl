/*
 * matrix.h
 *
 * 2015/12/18
 * Waheed Brown
 *
 * OpenGL Tutorial
 * http://www.cprogramming.com/tutorial/3d/rotationMatrices.html
 */

class Point {
 public:
  static void dotProduct(double* result, double* p, double m[][4]);
  static void showPoint(double* p);
  static double radToDeg(const double rad);
  static double degToRad(const double deg);
};

class Matrix {
 public:
  // Pass by reference
  static void dotProduct(double result[][4], double A[][4], double B[][4]);
  static void showMatrix(double matrix[][4]);
};
