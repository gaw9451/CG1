main: fillTest.cpp Rasterizer.cpp Rasterizer.h simpleCanvas.cpp simpleCanvas.h
	g++ -c -ggdb fillTest.cpp simpleCanvas.cpp
	g++ -c -ggdb -ansi -Wall Rasterizer.cpp
	g++ -o fillTest fillTest.o Rasterizer.o simpleCanvas.o -lsfml-graphics -lsfml-window -lsfml-system
