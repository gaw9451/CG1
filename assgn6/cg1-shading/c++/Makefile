main: cg1Shape.cpp cg1Shape.h shaderProgram.cpp shaderProgram.h simpleShape.cpp simpleShape.h lightingParams.cpp lightingParams.h vshader.glsl fshader.glsl shaderMain.cpp
	g++ -c cg1Shape.cpp shaderProgram.cpp simpleShape.cpp shaderMain.cpp
	g++ -c -ggdb -ansi -Wall -pedantic-errors lightingParams.cpp
	g++ -DGL_GLEXT_PROTOTYPES -o shaderMain shaderMain.o simpleShape.o shaderProgram.o cg1Shape.o lightingParams.o -lglut -lGL -lm -lGLEW
