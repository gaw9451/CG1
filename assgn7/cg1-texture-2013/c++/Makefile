main: cg1Shape.cpp cg1Shape.h shaderProgram.cpp shaderProgram.h simpleShape.cpp simpleShape.h textureMain.cpp textureParams.cpp textureParams.h
	g++ -c -I /usr/include/SOIL cg1Shape.cpp shaderProgram.cpp simpleShape.cpp textureMain.cpp textureParams.cpp
	g++ -o textureMain textureMain.o simpleShape.o shaderProgram.o cg1Shape.o textureParams.o -lglut -lGL -lm -lGLEW -lSOIL
