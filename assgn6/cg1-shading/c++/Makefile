main: lightingParams.h lightingParams.cpp shaderProgram.cpp shaderProgram.h simpleShape.cpp simpleShape.h fshader.glsl vshader.glsl shaderMain.cpp cg1Shape.cpp cg1Shape.h
	g++ -c -ansi -Wall -pedantic-errors lightingParams.cpp
	g++ -c shaderProgram.cpp shaderMain.cpp simpleShape.cpp cg1Shape.cpp
	g++ -o shaderMain shaderMain.o simpleShape.o cg1Shape.o lightingParams.o -lglut -lGL -lm -lGLEW
