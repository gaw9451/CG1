//
//  Rasterizer.java
//  
//
//  Created by Joe Geigel on 1/21/10.
//  Copyright 2010 Glenn Wallace. All rights reserved.
//

/**
 * 
 * A simple class for performing rasterization algorithms.
 *
 */

import java.util.*;

public class Rasterizer {
    
    /**
     * number of scanlines
     */
    int n_scanlines;
    
    /**
     * Constructor
     *
     * @param n - number of scanlines
     *
     */
    Rasterizer (int n)
    {
        n_scanlines = n;
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
	public void drawLine (int x0, int y0, int x1, int y1, simpleCanvas C)
	{
		/*if x0 is greater than x1, swap the points*/
		if( x0 > x1 ) {
			int temp;
			temp = x0;
			x0 = x1;
			x1 = temp;
			temp = y0;
			y0 = y1;
			y1 = temp;
		}

		/*if the line is vertical*/
		if( x0 == x1 ) {
			int inc;
			inc = ( y1 - y0 > 0 ) ? 1 : -1;
			for( int i = y0; i != y1 + inc; i += inc ) {
				C.setPixel( x0, i );
			}
		}

		/*if the line is horizontal*/
		else if( y0 == y1 ) {
			for( int i = x0; i <= x1; i++ ) {
				C.setPixel( i, y0 );
			}
		}

		/*if the line is diagonal*/
      		else if( Math.abs( y1 - y0 ) == x1 - x0 ) {
			int inc;
			inc = ( y1 - y0 > 0 ) ? 1 : -1;
			for( int i = 0; i <= x1 - x0; i++ ) {
				C.setPixel( i + x0, inc*i + y0 );
			}
		} else {
			midpointLineDraw( x0, x1, y0, y1, C );
		}
	}

	/*assumes that x0 is smaller than x1*/
	private void midpointLineDraw( int x0, int x1, int y0, int y1, simpleCanvas C ) {

		/*first figure out which octant we're working in..*/
int inc; int dx = x1 - x0;
		int dy = y1 - y0;
		int d;

		/*if y0 is smaller than y1, we will increment y*/
		if( dy > 0 ) {
			inc = 1;
		}

		/*otherwise, we'll decrement y*/
		else {
			inc = -1;
		}

		/*The magnitude of the slope is less than 1*/
		if( Math.abs( dy ) < dx ) {
			d = 2*dy - inc*dx;
			int y = y0;
			for( int x = x0; x <= x1; x++ ) {
				C.setPixel( x, y );
				if( Math.abs( d ) <= 0 ) {
					d += 2*dy;
					y += ( inc - 1 )/2;
				} else {
					d += 2*( dy - inc*dx );
					y += ( inc + 1 )/2;
				}
			}
		}

		/*The magnitude of the slope is greater than 1*/
		else {
			d = 2*dx - inc*dy;
			int x = x0;
			for( int y = y0; inc*y <= inc*y1; y += inc ) {
				C.setPixel( x, y );
				if( Math.abs( d ) <= 0 ) {
					d += 2*dx;
				} else {
					d += 2*( dx - inc*dy );
					x++;
				}
			}
		}
	}
}
