/*
 * quaternion.h
 *
 * 2015/12/21
 * Waheed Brown
 *
 * OpenGL Tutorial - Quaternions
 * http://www.cprogramming.com/tutorial/3d/quaternions.html
 */

#include <iostream>
using namespace std;

class Point {
 private:
  float _x, _y, _z;

 public:
  Point() {}
  Point(const float newX, const float newY, const float newZ) :
    _x(newX), _y(newY), _z(newZ) {}
  const float getX() const { return _x; }
  const float getY() const { return _y; }
  const float getZ() const { return _z; }  
  static void dotProduct(float* result, float* p, float m[][4]);
  static void show(float* p);
  static float radToDeg(const float rad);
  static float degToRad(const float deg);
};

class Matrix4x4 {
 private:
  float _elements[4][4];

 public:
  Matrix4x4() {}
  Matrix4x4(const float newElements[][4]);
  
  typedef float (*_mPtr)[4];
  _mPtr getElements() { return _elements; }

  static void dotProduct(float result[][4], float A[][4], float B[][4]);
  void show() const;
};

class Quaternion {
 private:
  float _w /* angle in degrees */ , _x, _y, _z;

 public:
  Quaternion() {}
  Quaternion(const float newW, const float newX,
	     const float newY, const float newZ) :
    _w(newW), _x(newX), _y(newY), _z(newZ) {}
  const float getW() const { return _w; }
  const float getX() const { return _x; }
  const float getY() const { return _y; }
  const float getZ() const { return _z; }
  Quaternion operator*(const Quaternion &o);
  static float calcMagnitude(const float w, const float x,
			      const float y, const float z);
  void normalize();
  static Quaternion genLocalRot(const float angle, const Point &axis);
  void show() const;
};
