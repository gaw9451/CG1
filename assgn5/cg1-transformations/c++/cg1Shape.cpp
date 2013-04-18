/**
 * shapes.cpp
 *
 * Routines for tessellating a number of basic shapes
 *
 * Students are to supply their implementations for the
 * functions in this file using the function "addTriangle()" to do the 
 * tessellation.
 *
 */

#ifdef __APPLE__
#include <OPENGL/gl.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#include "simpleShape.h"
#include <math.h>

/**
 *  
 * Feel free to cut/paste, and use working tesselation code from last assignment here
 *
 */

/**
 * makeLameCube - creates triangles for a pretty lame cube...Only use if you don't have working tesselation code
 *
 */
void makeLameCube()
{
    addTriangle (-0.5,-0.5,-0.5,-0.5,-0.5,0,-0.5,0,0);
    addTriangle (-0.5,0,0,-0.5,0,-0.5,-0.5,-0.5,-0.5);
    addTriangle (-0.5,0,-0.5,-0.5,0,0,-0.5,0.5,0);
    addTriangle (-0.5,0.5,0,-0.5,0.5,-0.5,-0.5,0,-0.5);
    addTriangle (-0.5,-0.5,0,-0.5,-0.5,0.5,-0.5,0,0.5);
    addTriangle (-0.5,0,0.5,-0.5,0,0,-0.5,-0.5,0);
    addTriangle (-0.5,0,0,-0.5,0,0.5,-0.5,0.5,0.5);
    addTriangle (-0.5,0.5,0.5,-0.5,0.5,0,-0.5,0,0);
    addTriangle (0.5,-0.5,-0.5,0.5,0,-0.5,0.5,0,0);
    addTriangle (0.5,0,0,0.5,-0.5,0,0.5,-0.5,-0.5);
    addTriangle (0.5,0,-0.5,0.5,0.5,-0.5,0.5,0.5,0);
    addTriangle (0.5,0.5,0,0.5,0,0,0.5,0,-0.5);
    addTriangle (0.5,-0.5,0,0.5,0,0,0.5,0,0.5);
    addTriangle (0.5,0,0.5,0.5,-0.5,0.5,0.5,-0.5,0);
    addTriangle (0.5,0,0,0.5,0.5,0,0.5,0.5,0.5);
    addTriangle (0.5,0.5,0.5,0.5,0,0.5,0.5,0,0);
    addTriangle (-0.5,-0.5,-0.5,0,-0.5,0,-0.5,-0.5,0);
    addTriangle (-0.5,-0.5,-0.5,0,-0.5,-0.5,0,-0.5,0);
    addTriangle (0,-0.5,-0.5,0.5,-0.5,0,0,-0.5,0);
    addTriangle (0,-0.5,-0.5,0.5,-0.5,-0.5,0.5,-0.5,0);
    addTriangle (-0.5,-0.5,0,0,-0.5,0.5,-0.5,-0.5,0.5);
    addTriangle (-0.5,-0.5,0,0,-0.5,0,0,-0.5,0.5);
    addTriangle (0,-0.5,0,0.5,-0.5,0.5,0,-0.5,0.5);
    addTriangle (0,-0.5,0,0.5,-0.5,0,0.5,-0.5,0.5);
    addTriangle (-0.5,0.5,-0.5,-0.5,0.5,0,0,0.5,0);
    addTriangle (-0.5,0.5,-0.5,0,0.5,0,0,0.5,-0.5);
    addTriangle (0,0.5,-0.5,0,0.5,0,0.5,0.5,0);
    addTriangle (0,0.5,-0.5,0.5,0.5,0,0.5,0.5,-0.5);
    addTriangle (-0.5,0.5,0,-0.5,0.5,0.5,0,0.5,0.5);
    addTriangle (-0.5,0.5,0,0,0.5,0.5,0,0.5,0);
    addTriangle (0,0.5,0,0,0.5,0.5,0.5,0.5,0.5);
    addTriangle (0,0.5,0,0.5,0.5,0.5,0.5,0.5,0);
    addTriangle (-0.5,-0.5,0.5,0,-0.5,0.5,0,0,0.5);
    addTriangle (-0.5,-0.5,0.5,0,0,0.5,-0.5,0,0.5);
    addTriangle (0,-0.5,0.5,0.5,-0.5,0.5,0.5,0,0.5);
    addTriangle (0,-0.5,0.5,0.5,0,0.5,0,0,0.5);
    addTriangle (-0.5,0,0.5,0,0,0.5,0,0.5,0.5);
    addTriangle (-0.5,0,0.5,0,0.5,0.5,-0.5,0.5,0.5);
    addTriangle (0,0,0.5,0.5,0,0.5,0.5,0.5,0.5);
    addTriangle (0,0,0.5,0.5,0.5,0.5,0,0.5,0.5);
    addTriangle (-0.5,-0.5,-0.5,-0.5,0,-0.5,0,-0.5,-0.5);
    addTriangle (0,-0.5,-0.5,-0.5,0,-0.5,0,0,-0.5);
    addTriangle (0,-0.5,-0.5,0,0,-0.5,0.5,-0.5,-0.5);
    addTriangle (0.5,-0.5,-0.5,0,0,-0.5,0.5,0,-0.5);
    addTriangle (-0.5,0,-0.5,-0.5,0.5,-0.5,0,0,-0.5);
    addTriangle (0,0,-0.5,-0.5,0.5,-0.5,0,0.5,-0.5);
    addTriangle (0,0,-0.5,0,0.5,-0.5,0.5,0,-0.5);
    addTriangle (0.5,0,-0.5,0,0.5,-0.5,0.5,0.5,-0.5);
}


/**
 * makeDefaultShape - creates a "unit" shape of your choice using your tesselation routines.
 *  If you don't have working tessellation code for any of the shapes, you can use the supplied
 *  makeLameCube routine.
 *
 */
void makeDefaultShape ()
{
    makeLameCube();
}

