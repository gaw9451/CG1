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

using namespace std;

#define PI ( 4 * atan( 1 ) )


/**
 * makeCube - Create a unit cube, centered at the origin, with a given number
 * of subdivisions in each direction on each face.
 *
 * @param subdivision - number of equal subdivisons to be made in each 
 *        direction along each face
 *
 * Can only use calls to addTriangle()
 */
void makeCube (int subdivisions)
{
	/*front face 0.5*(-1,-1,1) to 0.5*(1,1,1)*/
	for( int i = 0; i < subdivisions; i++ ) {
		for( int j = 0; j < subdivisions; j++ ) {
			float step = 1.0/subdivisions;
			float cx = step*i - 0.5; 
			float cy = step*j - 0.5;
			addTriangle( cx, cy, 0.5, cx + step, cy, 0.5, cx + step, cy + step, 0.5 );
			addTriangle( cx, cy, 0.5, cx + step, cy + step, 0.5, cx, cy + step, 0.5 );
		}
	}

	/*back face 0.5*(1,-1,-1) to 0.5*(-1,1,-1)*/
	for( int i = 0; i < subdivisions; i++ ) {
		for( int j = 0; j < subdivisions; j++ ) {
			float step = 1.0/subdivisions;
			float cx = -step*i + 0.5;
			float cy = step*j - 0.5;
			addTriangle( cx, cy, -0.5, cx - step, cy, -0.5, cx - step, cy + step, -0.5 );
			addTriangle( cx, cy, -0.5, cx - step, cy + step, -0.5, cx, cy + step, -0.5 );
		}
	}
	
	/*right face 0.5*(1,-1,1) to 0.5*(1,1,-1)*/
	for( int i = 0; i < subdivisions; i++ ) {
		for( int j = 0; j < subdivisions; j++ ) {
			float step = 1.0/subdivisions;
			float cy = step*i - 0.5;
			float cz = -step*j + 0.5;
			addTriangle( 0.5, cy, cz, 0.5, cy, cz - step, 0.5, cy + step, cz - step );
			addTriangle( 0.5, cy, cz, 0.5, cy + step, cz - step, 0.5, cy + step, cz );
		}
	}

	/*left face 0.5*(-1,-1,-1) to 0.5*(-1,1,1)*/
	for( int i = 0; i < subdivisions; i++ ) {
		for( int j = 0; j < subdivisions; j++ ) {
			float step = 1.0/subdivisions;
			float cy = step*i - 0.5;
			float cz = step*j - 0.5;
			addTriangle( -0.5, cy, cz, -0.5, cy, cz + step, -0.5, cy + step, cz + step );
			addTriangle( -0.5, cy, cz, -0.5, cy + step, cz + step, -0.5, cy + step, cz );
		}
	}

	/*top face 0.5*(-1,1,1) to 0.5*(1,1,-1)*/
	for( int i = 0; i < subdivisions; i++ ) {
		for( int j = 0; j < subdivisions; j++ ) {
			float step = 1.0/subdivisions;
			float cx = step*i - 0.5;
			float cz = -step*j + 0.5;
			addTriangle( cx, 0.5, cz, cx + step, 0.5, cz, cx + step, 0.5, cz - step );
			addTriangle( cx, 0.5, cz, cx + step, 0.5, cz - step, cx, 0.5, cz - step );
		}
	}

	/*bottom face 0.5*(1,-1,-1) to (-1,-1,1)*/
	for( int i = 0; i < subdivisions; i++ ) {
		for( int j = 0; j < subdivisions; j++ ) {
			float step = 1.0/subdivisions;
			float cx = -step*i + 0.5;
			float cz = step*j - 0.5;
			addTriangle( cx, -0.5, cz, cx - step, -0.5, cz + step, cx - step, -0.5, cz );
			addTriangle( cx, -0.5, cz, cx, -0.5, cz + step, cx - step, -0.5, cz + step );
		}
	}
}


/**
 * makeCylinder - Create polygons for a cylinder with unit height, centered at
 * the origin, with separate number of radial subdivisions and height 
 * subdivisions.
 *
 * @param radius - Radius of the base of the cylinder
 * @param radialDivision - number of subdivisions on the radial base
 * @param heightDivisions - number of subdivisions along the height
 *
 * Can only use calls to addTriangle()
 */
void makeCylinder (float radius, int radialDivisions, int heightDivisions)
{

	/*top face*/
	float step1 = 2.0*PI/radialDivisions;
	float step2 = 1.0/heightDivisions;
	for( int i = 0; i < radialDivisions; i++ ) {

		/*draw the top face*/
		float theta = step1*i;
		addTriangle( 0, 0.5, 0, radius*cos( theta ), 0.5, radius*sin( theta ), radius*cos( theta + step1 ), 0.5, radius*sin( theta + step1 ) );

		/*draw the bottom face*/
		addTriangle( 0, -0.5, 0, radius*cos( theta ), -0.5, radius*sin( theta ), radius*cos( theta - step1 ), -0.5, radius*sin( theta - step1 ) );
		for( int j = 0; j < heightDivisions; j++ ) {
			float cy = -0.5 + step2*j;
			addTriangle( radius*cos( theta ), cy, radius*sin( theta ),
				     radius*cos( theta + step1 ), cy, radius*sin( theta + step1 ),
				     radius*cos( theta + step1 ), cy + step2, radius*sin( theta + step1 ) );
			addTriangle( radius*cos( theta ), cy, radius*sin( theta ),
				     radius*cos( theta + step1 ), cy + step2, radius*sin( theta + step1 ),
				     radius*cos( theta ), cy + step2, radius*sin( theta ) );
		}
	}
}


/**
 * makeCone - Create polygons for a cone with unit height, centered at the
 * origin, with separate number of radial subdivisions and height 
 * subdivisions
 *
 * @param radius - Radius of the base of the cone
 * @param radialDivision - number of subdivisions on the radial base
 * @param heightDivisions - number of subdivisions along the height
 *
 * Can only use calls to addTriangle()
 */
void makeCone (float radius, int radialDivisions, int heightDivisions)
{
	
	float step1 = 2.0*PI/radialDivisions;
	float step2 = 1.0/heightDivisions;
	for( int i = 0; i < radialDivisions; i++ ) {
		float theta = step1*i;
		addTriangle( 0, -0.5, 0, radius*cos( theta ), -0.5, radius*sin( theta ), radius*cos( theta - step1 ), -0.5, radius*sin( theta - step1 ) );
		for( int j = 0; j < heightDivisions; j++ ) {
				float cy = -0.5 + step2*j;
				float r1 = radius - (radius/heightDivisions)*j;
				float r2 = radius - ( (radius/heightDivisions)*(j + 1) );
			addTriangle( r1*cos( theta ), cy, r1*sin( theta ),
				     r1*cos( theta + step1 ), cy, r1*sin( theta + step1 ),
				     r2*cos( theta + step1 ), cy + step2, r2*sin( theta + step1 ) );
			addTriangle( r1*cos( theta ), cy, r1*sin( theta ),
				     r2*cos( theta + step1 ), cy + step2, r2*sin( theta + step1 ),
				     r2*cos( theta ), cy + step2, r2*sin( theta ) );
		}
	}
}


/**
 * makeSphere - Create sphere of a given radius, centered at the origin, 
 * using spherical coordinates with separate number of thetha and 
 * phi subdivisions.
 *
 * @param radius - Radius of the sphere
 * @param slides - number of subdivisions in the theta direction
 * @param stacks - Number of subdivisions in the phi direction.
 *
 * Can only use calls to addTriangle
 *
 *  This implementation is still a bit buggy at the poles.
 */
void makeSphere (float radius, int slices, int stacks)
{
	float step1 = PI/stacks;
	float step2 = 2.0*PI/slices;

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
