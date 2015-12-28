# Makefile
#
# 2015/12/16
# Waheed Brown
#
# OpenGL Tutorial
# http://www.cprogramming.com/tutorial/3d/rotationMatrices.html
#
# NOTES:
# This implementation suffers from gimble lock
# Matricies are defined as MxN, row by column
# All trig calculations require angles in radians
# All points are ROW vectors, which must be of exactly 1x4 dimension
# All matricies are of exactly 4x4 dimension

all:
	g++ matrotation.cpp matrix.cpp -o matrotation
debug:
	g++ -g matrotation.cpp matrix.cpp -o matrotation
clean:
	rm -rf *o
	rm -rf *#
	rm -rf *~
	rm -rf *dSYM
	rm -rf matrotation

