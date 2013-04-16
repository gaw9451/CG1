main: extendedCanvas.h simpleCanvas.h clipper.h clipper.cpp extendedCanvas.cpp simpleCanvas.cpp clipTest.cpp
	g++ -c -ggdb extendedCanvas.cpp simpleCanvas.cpp clipTest.cpp
	g++ -c -Wall -ansi -ggdb -c clipper.cpp
	g++ -o clipTest clipTest.o clipper.o extendedCanvas.o simpleCanvas.o -lsfml-graphics -lsfml-window -lsfml-system
