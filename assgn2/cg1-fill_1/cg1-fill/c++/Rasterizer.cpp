//
//  Rasterizer.cpp
//  
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

struct Edge {
	int ymax;
	int x;
	int dx;
	int dy;
	int sum;
	Edge* link;
};

void insertEdge( int ymin, Edge** et, Edge* newEdge ) {
	Edge** curr;
	Edge** prev;
	bool inserted = false;
	curr = et + ymin;
	prev = 0;
	while( *curr != 0 && !inserted ) {
		bool smaller;
		smaller = newEdge->x < (*curr)->x ||
			  ( newEdge->x == (*curr)->x &&
			    newEdge->dx*(*curr)->dy < (*curr)->dx*newEdge->dy );
		if( smaller ) {
			if( prev == 0 ) {
				newEdge->link = *curr;
				*curr = newEdge;
			} else {
				newEdge->link = *curr;
				(*prev)->link = newEdge;
			}
			inserted = true;
		}
		prev = curr;
		curr = &( (*curr)->link );
	}
	if( !inserted ) {
		*curr = newEdge;
	}
}

/*adds each edge in the chain to ael*/
void addEdge( Edge* newEdge, Edge** ael ) {
	Edge** curr;
	Edge** prev;
	bool inserted = false;
	curr = ael;
	prev = 0;
	while( *curr != 0 && !inserted ) {
		bool smaller;
		smaller = newEdge->x < (*curr)->x ||
			  ( newEdge->x == (*curr)->x &&
			    newEdge->dx*(*curr)->dy < (*curr)->dx*newEdge->dy );
		if( smaller ) {
			if( prev == 0 ) {
				newEdge->link = *curr;
				*curr = newEdge;
			} else {
				newEdge->link = *curr;
				(*prev)->link = newEdge;
			}
			inserted = true;
		}
		prev = curr;
		curr = &( (*curr)->link );
	}
	if( !inserted ) {
		*curr = newEdge;
	}
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

	Edge* edgeTable[ n_scanlines ];
	Edge* edgeList[ n ];
	Edge* ael;
	int minScanline, maxScanline;
	minScanline = n_scanlines;
	maxScanline = -1;

	/*populate the edge table*/
	for( int i = 0; i < n_scanlines; i++ ) {
		edgeTable[ i ] = 0;
	}
	for( int i = 0; i < n; i++ ) {
		edgeList[ i ] = 0;
	}
	for( int i = 0; i < n; i++ ) {
		if( y[ i ] != y[ ( i + 1 ) % n ] ) {
			Edge* newEdge = new Edge;
			int minIndex, maxIndex;
			edgeList[ i ] = newEdge;
			if( y[ i ] < y[ ( i + 1 ) % n ] ) {
				minIndex = i;
				maxIndex = ( i + 1 ) % n;
			} else {
				minIndex = ( i + 1 ) % n;
				maxIndex = i;
			}
			newEdge->ymax = y[ maxIndex ];
			newEdge->x = x[ minIndex ];
			newEdge->dx = x[ maxIndex ] - x[ minIndex ];
			newEdge->dy = y[ maxIndex ] - y[ minIndex ];
			newEdge->sum = 0;
			newEdge->link = 0;
			insertEdge( y[ minIndex ], edgeTable, newEdge );
			if( y[ minIndex ] < minScanline ) {
				minScanline = y[ minIndex ];
			}
			if( y[ maxIndex ] > maxScanline ) {
				maxScanline = y[ maxIndex ];
			}
		}
	}

	/*fill scanlines*/
	ael = edgeTable[ minScanline ];
	for( int sl = minScanline; sl < maxScanline; sl++ ) {
		Edge* curr1 = ael;
		Edge* curr2 = curr1->link;
		Edge* prev = 0;
		bool done = false;
		while( !done ) {
			int start; int end;
			start = curr1->x;
			if( curr1->sum > 0 ) {
				start++;
			}
			end = curr2->x;
			for( int j = start; j < end; j++ ) {
				C.setPixel( j, sl );
			}
			curr1->sum += curr1->dx;
			curr2->sum += curr2->dx;
			while( curr1->sum >= curr1->dy ) {
				curr1->x++;
				curr1->sum -= curr1->dy;
			}
			while( curr1->sum < 0 ) {
				curr1->x--;
				curr1->sum += curr1->dy;
			}
			while( curr2->sum >= curr2->dy ) {
				curr2->x++;
				curr2->sum -= curr2->dy;
			}
			while( curr2->sum < 0 ) {
				curr2->x--;
				curr2->sum += curr2->dy;
			}
			if( curr1->ymax == sl + 1 ) {

				/*remove the first edge from the ael*/
				if( prev == 0 ) {
					ael = curr1->link;
				} else {
					prev->link = curr1->link;
				}
			}
			if( curr2->ymax == sl + 1 ) {

				/*remove the second edge from the ael*/
				if( ael == curr2 ) {
					ael = curr2->link;
				}
				curr1->link = curr2->link;
				
			}
			/*add edges from the et at sl*/
			if( edgeTable[ sl + 1 ] != 0 && sl != minScanline ) {
				Edge** newEdgeList;
				int numEdges = 0;
				int count = 0;
				Edge* curr = edgeTable[ sl + 1 ];

				/*count the number of edges*/
				while( curr != 0 ) {
					numEdges++;
					curr = curr->link;
				}
				newEdgeList = new Edge*[ numEdges ];
				curr = edgeTable[ sl + 1 ];

				/*add each edge's pointer to the list*/
				while( curr != 0 ) {
					newEdgeList[ count ] = curr;
					curr = curr->link;
					count++;
				}

					addEdge( newEdgeList[ 0 ], &ael );

				/*free the array*/
				delete [] newEdgeList;
			}

			/*if not done, advance the pointers*/
			if( curr2->link == 0 ) {
				done = true;
			} else {
				prev = curr2;
				curr1 = curr2->link;
				curr2 = curr1->link;
			}
		}
	}

	/*delete all edges allocated*/
	for( int i = 0; i < n; i++ ) {
		if( edgeList[ i ] != 0 ) {
			delete edgeList[ i ];
		}
	}

}
