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
#include <GL/gl.h>
#endif

#include "simpleShape.h"
#include <math.h>



/**
 * makeDefaultShape - creates a "unit" shape of your choice using your tesselation routines.
*/
void makeDefaultShape ()
{
    // tesselate your favorite shape here.
	/*top hemisphere*/
	for( int i = 0; i < stacks; i++ ) {
		float theta = step1*i;
		for( int j = 0; j < slices; j++ ) {
			float phi = step2*j;
			float x1 = radius*sin( theta )*cos( phi );
			float y1 = radius*cos( theta );
			float z1 = radius*sin( theta )*sin( phi );
			float x2 = radius*sin( theta + step1 )*cos( phi );
			float y2 = radius*cos( theta + step1 );
			float z2 = radius*sin( theta + step1 )*sin( phi );
			float x3 = radius*sin( theta + step1 )*cos( phi + step2 );
			float y3 = radius*cos( theta + step1 );
			float z3 = radius*sin( theta + step1 )*sin( phi + step2 );
			float x4 = radius*sin( theta )*cos( phi + step2 );
			float y4 = radius*cos( theta );
			float z4 = radius*sin( theta )*sin( phi + step2 );
			addTriangle( x1, y1, z1, x2, y2, z2, x3, y3, z3 );
			addTriangle( x1, y1, z1, x3, y3, z3, x4, y4, z4 );
		}
	}
}
    
