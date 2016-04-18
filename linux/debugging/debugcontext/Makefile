# Sunday March 6, 2016
#
# Makefile
# Waheed Brown
#
# OpenGL Developers Toolbox
# Debugging and Profiling OpenGL
# Creating a Debug Context
#
#
# REFERENCES:
# Shreiner D., et al, OpenGL Programming Guide, Eighth Edition, (c)2013 Pearson Education, Inc 
#
#
# NOTES:
# - Uses GLX (OpenGL extension for X Window), Ubuntu environment

linux:
	gcc debugcontext.c -L/usr/include/GL -lGL -lGLU -lglut -o debugcontext
debug:
	gcc -g -O0 -Wall debugcontext.c -lGL -lGLU -lglut -o debugcontext
clean:
	rm -rf *~
	rm -rf debugcontext

