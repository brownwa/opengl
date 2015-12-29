# December 28, 2015
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
	g++ debugcontext.cpp -lGL -lGLU -lglut -o debugcontext
debug:
	g++ -g debugcontext.cpp -lGL -lGLU -lglut -o debugcontext
clean:
	rm -rf *~
	rm -rf *#
	rm -rf *~
	rm -rf *dSYM
	rm -rf debugcontext

