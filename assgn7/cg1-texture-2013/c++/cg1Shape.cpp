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

#define PI ( 4 * atan( 1 ) )

/**
 * makeDefaultShape - creates a "unit" shape of your choice using your tesselation routines.
*/
void makeDefaultShape ()
{
	float radius = 1;
	float stacks = 100;
	float slices = 100;
	float step1 = PI/stacks;
	float step2 = 2.0*PI/slices;
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

			float u1 = asin( x1 )/PI + 0.5;
			float v1 = -asin( y1 )/PI + 0.5;
			float u2 = asin( x2 )/PI + 0.5;
			float v2 = -asin( y2 )/PI + 0.5;
			float u3 = asin( x3 )/PI + 0.5;
			float v3 = -asin( y3 )/PI + 0.5;
			float u4 = asin( x4 )/PI + 0.5;
			float v4 = -asin( y4 )/PI + 0.5;
			addTriangle( x1, y1, z1, u1, v1, x2, y2, z2, u2, v2, x3, y3, z3, u3, v3 );
			addTriangle( x1, y1, z1, u1, v1, x3, y3, z3, u3, v3, x4, y4, z4, u4, v4 );
		}
	}
	
}
    
