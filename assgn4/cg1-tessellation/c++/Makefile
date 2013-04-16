main: *.glsl cg1Shape.* shaderProgram.* simpleShape.* tessMain.cpp
	g++ -c shaderProgram.cpp simpleShape.cpp tessMain.cpp
	g++ -c -ansi -Wall -ggdb cg1Shape.cpp
	g++ -DGL_GLEXT_PROTOTYPES -o tessMain tessMain.o shaderProgram.o simpleShape.o cg1Shape.o -lglut -lGL -lm -lGLEW
