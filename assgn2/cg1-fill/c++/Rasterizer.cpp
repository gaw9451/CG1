//
//  Rasterizer.cpp
//  
//  Glenn Wallace
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//



#include <iostream>
#include "Rasterizer.h"
#include "simpleCanvas.h"

using namespace std;

/**
 *
 * Simple class that performs rasterization algorithms
 *
 */

struct EdgeBucket {
	int ymax;
	int x;
	int dx;
	int dy;
	int sum;
	EdgeBucket* link;
};

void insertEdge( int ymin, EdgeBucket* newEdge, EdgeBucket** edgeTable ) {
	EdgeBucket** curr = edgeTable + ymin;
	/*EdgeBucket* prev = 0;*/
	bool done = false;
	while( *curr != 0 && !done ) {
		
		/*if the new edge's x is smaller than the current x*/
		if( newEdge->x < (*curr)->x ||
		    ( newEdge->x == (*curr)->x &&
		      newEdge->dx/newEdge->dy < (*curr)->dx/(*curr)->dy
	    	    ) ) {

			/*swap them*/
			newEdge->link = *curr;
			*curr = newEdge;
			done = true;
		}
		
		/*if it got to the end of the chain*/

		if( !done ) {
			curr = &( ( *curr )->link );
		}
	}
	if( !done ) {
		*curr = newEdge;
	}
}

/*modulus function that works on negative numbers*/
int mod( int x, int m ) {
	return (x%m + m)%m;
}

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
 * Draw a filled polygon in the simpleCanvas C.
 *
 * The polygon has n distinct vertices. The 
 * coordinates of the vertices making up the polygon are stored in the 
 * x and y arrays.  The ith vertex will have coordinate  (x[i], y[i])
 *
 * You are to add the implementation here using only calls
 * to C.setPixel()
 */
void Rasterizer::drawPolygon(int n, int x[], int y[], simpleCanvas &C)
{
	EdgeBucket* edgeTable[ n_scanlines ];
	EdgeBucket* edges[ n ];
	int minScanline = n_scanlines;
	int maxScanline = -1;
	
	/*clear the edge table initially*/
	for( int i = 0; i < n_scanlines; i++ ) {
		edgeTable[ i ] = 0;
	}

	/*populate the edge table with edges*/
	for( int i = 0; i < n; i++ ) {
		if( y[ i ] != y[ ( i + 1 ) % n ] ) {
			EdgeBucket* newEdge = new EdgeBucket;
			int ymax;
			int minVertex;
			int maxVertex;
			if( y[ i ] > y[ ( i + 1 ) % n ] ) {
				ymax = y[ i ];
				minVertex = ( i + 1 ) % n;
				maxVertex = i;
			} else {
				ymax = y[ ( i + 1 ) % n ];
				minVertex =  i;
				maxVertex = ( i + 1 ) % n;
			}
			newEdge->ymax = ymax;
			newEdge->x = x[ minVertex ];
			newEdge->dx = x[ maxVertex ] - x[ minVertex ];
			newEdge->dy = y[ maxVertex ] - y[ minVertex ];
			newEdge->sum = 0;
			newEdge->link = 0;
			edges[ i ] = newEdge;
			insertEdge( y[ minVertex ], newEdge, edgeTable );
			
			/*update the mininum scan line*/
			if( y[ minVertex ] < minScanline ) {
				minScanline = y[ minVertex ];
			}

			/*update the maximum scan line*/
			if( y[ maxVertex ] > maxScanline ) {
				maxScanline = y[ maxVertex ];
			}
		} else {
			edges[ i ] = 0;
		}
		
	}

	/*now create active edge list, starting with the edge at the
	  minimum scanline*/
	EdgeBucket* ael;
	int scanline = minScanline;
	ael = edgeTable[ minScanline ];
	bool done = false;
	while( !done ) {

		/*initialize the variables to draw the current row*/
		EdgeBucket* currEdge1 = ael;
		EdgeBucket* currEdge2 = currEdge1->link;
		bool endChain = false;
		while( !endChain ) {
			int beginning = currEdge1->x;
			if( currEdge1->sum > 0 ) {
				beginning++;
			}
			for( int j = beginning; j < currEdge2->x; j++ ) {
				C.setPixel( j, scanline );
			}
			currEdge1->sum += currEdge1->dx;
			while( currEdge1->sum >= currEdge1->dy ) {
				currEdge1->x++;
				currEdge1->sum -= currEdge1->dy;
			}
			while( currEdge1->sum < 0 ) {
				currEdge1->x--;
				currEdge1->sum += currEdge1->dy;
			}
			currEdge2->sum += currEdge2->dx;
			while( currEdge2->sum >= currEdge2->dy ) {
				currEdge2->x++;
				currEdge2->sum -= currEdge2->dy;
			}
			while( currEdge2->sum < 0 ) {
				currEdge2->x--;
				currEdge2->sum += currEdge2->dy;
			}
			if( currEdge2->link == 0 ) {
				endChain = true;
			} else {
				currEdge1 = currEdge2->link;
				currEdge2 = currEdge1->link;
			}
		}

		/*update the scanline*/
		scanline++;
		if( scanline == maxScanline ) {
			done = true;
		} else {
			EdgeBucket* currEdge3;

			/*remove the necessary elements from the ael*/
			currEdge1 = ael;
			currEdge2 = 0;
			endChain = false;
			while( !endChain ) {
				
				/*if scanline is ymax, remove the edge*/
				if( scanline == currEdge1->ymax ) {
					if( currEdge2 == 0 ) {
						ael = currEdge1->link;
						currEdge2 = 0;
						currEdge1 = currEdge1->link;
					} else {
						currEdge2 = currEdge1;
						currEdge2->link = currEdge1->link;
					}
				}
				/*if scanline is not ymax, move on to the next edge*/
				else {
					currEdge2 = currEdge1;
					currEdge1 = currEdge1->link;
				}
				if( currEdge1 == 0 ) {
					endChain = true;
				}
			}

			/*add the necessary elements to the ael*/

			/*iterate through each element in the current et line*/
			/*currEdge 3 is the et pointer. currEdge 1 is the
			  ael pointer, currEdge 2 is the back ael pointer*/
			currEdge3 = edgeTable[ scanline ];
			currEdge1 = ael;
			currEdge2 = 0;
			endChain = false;
			if( currEdge3 == 0 ) {
				endChain = true;
			}
			while( !endChain ) {
				
				/*compare the currEdge3's x with currEdge1's x*/
				if( currEdge3->x < currEdge1->x ||
				   ( currEdge3->x == currEdge1->x &&  
				     currEdge3->dx/currEdge3->dy < currEdge1->dx/currEdge1->dy ) ) {
					
					/*if this is the first element in the ael chain*/
					if( currEdge2 == 0 ) {
						ael = currEdge3;
						currEdge3->link = currEdge1;
					} else {
						currEdge3->link = currEdge1;
						currEdge2->link = currEdge3;
					}
				}

				/*advance the pointers until a null is encountered*/
				currEdge2 = currEdge1;
				currEdge1 = currEdge1->link;
				while( currEdge1 != 0 ) {

					/*compare the currEdge3's x with currEdge1's x*/
					if( currEdge3->x < currEdge1->x ||
					   ( currEdge3->x == currEdge1->x &&  
					     currEdge3->dx*currEdge1->dy < currEdge1->dx*currEdge3->dy ) ) {
						
						/*if this is the first element in the ael chain*/
						if( currEdge2 == 0 ) {
							ael = currEdge3;
							currEdge3->link = currEdge1;
						} else {
							currEdge3->link = currEdge1;
							currEdge2->link = currEdge3;
						}
						
					}

					/*advance the pointers until a null is encountered*/
					currEdge2 = currEdge1;
					currEdge1 = currEdge1->link;
				
				}
				ael = edgeTable[ scanline ];
				currEdge1 = ael;
				currEdge2 = 0;
				/*move the pointer to the next edge in the et*/
				currEdge3 = currEdge3->link;
				if( currEdge3 == 0 ) {
					endChain = true;
				}
			}
		}
	}

	/*delete the edges*/
	for( int i = 0; i < n; i++ ) {
		if( edges[ i ] != 0 ) {
			delete edges[ i ];
		}
	}
}
