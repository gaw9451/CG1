main: cg1Shape.cpp cg1Shape.h shaderProgram.cpp shaderProgram.h simpleShape.cpp simpleShape.h viewParams.cpp viewParams.h vshader.glsl fshader.glsl transMain.cpp
	g++ -c cg1Shape.cpp shaderProgram.cpp simpleShape.cpp transMain.cpp
	g++ -c -ggdb -ansi -Wall -pedantic-errors viewParams.cpp
	g++ -DGL_GLEXT_PROTOTYPES -o transMain transMain.o simpleShape.o shaderProgram.o cg1Shape.o viewParams.o -lglut -lGL -lm -lGLEW
