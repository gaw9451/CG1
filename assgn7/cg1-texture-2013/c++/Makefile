main: cg1Shape.cpp cg1Shape.h shaderProgram.cpp shaderProgram.h simpleShape.cpp simpleShape.h textureMain.cpp textureParams.cpp textureParams.h
	gcc -c cg1Shape.cpp shaderProgram.cpp simpleShape.cpp textureMain.cpp textureParams.cpp
	gcc -c -ansi -Wall -pedantic-errors
	gcc -o textureMain textureMain.o simpleShape.o shaderProgram.o cg1Shape.o textureParam.o
