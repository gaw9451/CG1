//
//  clipper.cpp
//  
//
//  Created by gel on 11/30/11.
//  Glenn Wallace
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//

#include <cassert>
#include <iostream>
#include "clipper.h"

using namespace std;

/**
 * Simple class that performs clipping
 *
 */

/**
 * Constructor
 */
clipper::clipper ()
{
}

bool inside( float px, float py, float bx0, float by0,
	float bx1, float by1 ) {
	bool result = false;
	assert( bx0 == bx1 || by0 == by1 );
	if( bx0 == bx1 ) {

		/*right edge*/
		if( by0 < by1 ) {
			result = ( px < bx0 );
		}

		/*left edge*/
		else {
			result = ( px >= bx0 );
		}
	} else {

		/*bottom edge*/
		if( bx0 < bx1 ) {
			result = ( py >= by0 );
		}

		/*top edge*/
		else {
			result = ( py < by0 );
		}
	}
	return result;
}

void intersect( float px0, float py0, float px1, float py1,
	float bx0, float by0, float bx1, float by1, float* ix, float* iy ) {
		assert( bx0 == bx1 || by0 == by1 );
		bool vertical = ( bx0 == bx1 );
		if( px1 == px0 ) {
			*ix = px0;
			*iy = by0;
		} else {
			float m = ( py1 - py0 )/( px1 - px0 ); 
			float b = ( py0 - m*px0 );
			if( vertical ) {
				*ix = bx0;
				*iy = m*bx0 + b;
			} else {
				*ix = ( by0 - b )/m;
				*iy = by0;
			}
		}
}

/*
 * Clips on one edge. Assumes that the shape is drawn counter-clockwise.
 * to the function.
 *
 * @param inx x coords of the polygon to be clipped
 * @param iny y coords of the polygon to be clipped
 * @param outx x coords of the polygon after clipping
 * @param outy y coords of the polygon after clipping 
 * @param x0 x coordinate of the first vertex in the boundary
 * @param y0 y coordinate of the first vertex in the boundary
 * @param x1 x coordinate of the second vertex in the boundary
 * @param y1 y coordinate of the second vertex in the boundary
 * @param in number of input vertices
 * @param out number of output vertices
 */
void shClip( const float inx[], const float iny[], float outx[],
	float outy[], float x0, float y0, float x1, float y1,
	int in, int* out ) {
	assert( x0 == x1 || y0 == y1 );

	int outLen = 0;
	float px = inx[ in - 1 ];
	float py = iny[ in - 1 ];
	for( int i = 0; i < in; i++ ) {
		float vx = inx[ i ];
		float vy = iny[ i ];
		if( inside( vx, vy, x0, y0, x1, y1 ) ) {
			if( inside( px, py, x0, y0, x1, y1 ) ) {

				/*case 1, entirely inside*/
				outx[ outLen ] = vx;
				outy[ outLen ] = vy;
				outLen++;
			} else {

				/*case 4, outside to in*/
				float ix; float iy;
				intersect( px, py, vx, vy,
					x0, y0, x1, y1, &ix, &iy );
				outx[ outLen ] = ix;
				outy[ outLen ] = iy;
				outLen++;
				outx[ outLen ] = vx;
				outy[ outLen ] = vy;
				outLen++;
			}
		} else {
			if( inside( px, py, x0, y0, x1, y1 ) ) {
				float ix; float iy;
				intersect( px, py, vx, vy,
					x0, y0, x1, y1, &ix, &iy );
				outx[ outLen ] = ix;
				outy[ outLen ] = iy;
				outLen++;
			}
		}
		px = vx;
		py = vy;
	}
	*out = outLen;
}

/**
 * clipPolygon
 * 
 * Clip the polygon with vertex count in and vertices inx/iny
 * against the rectangular clipping region specified by lower-left corner
 * (x0,y0) and upper-right corner (x1,y1). The resulting vertices are
 * placed in outx/outy.  
 * 
 * The routine should return the with the vertex count of polygon
 * resulting from the clipping.
 *
 * @param in the number of vertices in the polygon to be clipped
 * @param inx - x coords of vertices of polygon to be clipped.
 * @param int - y coords of vertices of polygon to be clipped.
 * @param outx - x coords of vertices of polygon resulting after clipping.
 * @param outy - y coords of vertices of polygon resulting after clipping.
 * @param x0 - x coord of lower left of clipping rectangle.
 * @param y0 - y coord of lower left of clipping rectangle.
 * @param x1 - x coord of upper right of clipping rectangle.
 * @param y1 - y coord of upper right of clipping rectangle.
 *
 * @return number of vertices in the polygon resulting after clipping
 * 
 */
int clipper::clipPolygon(int in, float inx[], float iny[], float outx[], 
                float outy[], float x0, float y0, float x1, float y1)
{
	float outx1[ 50 ]; float outy1[ 50 ]; int outLen1;
	float outx2[ 50 ]; float outy2[ 50 ]; int outLen2;
	float outx3[ 50 ]; float outy3[ 50 ]; int outLen3;
	int outLen4; 
	for( int i = 0; i < in; i++ ) {
		if( i < in - 1 ) {
		}
	}

	/*bottom clipping edge*/
	shClip( inx, iny, outx1, outy1, x0, y0, x1, y0, in, &outLen1 );

	/*right clipping edge*/
	shClip( outx1, outy1, outx2, outy2, x1, y0, x1, y1, outLen1, &outLen2 );

	/*top clipping edge*/
	shClip( outx2, outy2, outx3, outy3, x1, y1, x0, y1, outLen2, &outLen3 );

	/*left clipping edge*/
	shClip( outx3, outy3, outx, outy, x0, y1, x0, y0, outLen3, &outLen4 );

	return outLen4;  // should return number of verticies in clipped poly.

}

