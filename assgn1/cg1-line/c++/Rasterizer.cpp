//
//  Rasterizer.cpp
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//

#include "Rasterizer.h"
#include "simpleCanvas.h"

/**
 *
 * Simple class that performs rasterization algorithms
 *
 */

/**
 * Constructor
 *
 * @param n - number of scanlines
 *
 */
Rasterizer::Rasterizer (int n) : n_scanlines (n)
{
}

/**
 * Draw a line from (x0,y0) to (x1, y1) on the simpleCanvas C.
 *
 * Implementation should be using the Midpoint Method
 *
 * You are to add the implementation here using only calls
 * to C.setPixel()
 *
 * @param x0 - x coord of first endpoint
 * @param y0 - y coord of first endpoint
 * @param x1 - x coord of second endpoint
 * @param y1 - y coord of second endpoint
 * @param C - The canvas on which to apply the draw command.
 */
void Rasterizer::drawLine (int x0, int y0, int x1, int y1, simpleCanvas &C)
{

	int m;

	/*if the first x is greater than the second x, swap the points*/
	if( x0 > x1 ) {
		int temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	/*if it is a vertical line*/
	if( x0 == x1 ) {
		int i;
		for( i = y0; i <= y1; i++ ) {
			C.setPixel( x0, i );
		}
	}
}
