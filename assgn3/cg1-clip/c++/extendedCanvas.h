//
//  simpleCanvas.h
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//

#ifndef _extendedCanvas_h
#define _extendedCanvas_h

#include "simpleCanvas.h"

#include <vector>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Color.hpp>

using namespace std;

/**
 * This is a special subclass of simpleCanvas with functionality
 * for testing out the clipping assignment.
 *
 * Note, this class should only be used for clipping assignment and
 * only for testing purposes!!! *
 */
class extendedCanvas : public simpleCanvas {
    
private:
    /**
     * SFML polygons
     */
    vector<sf::Shape> polys;
    
public:
    /**
     * Constructor
     *
     * @param w width of canvas
     * @param h height of canvas
     */
    extendedCanvas(int w, int h);
    
    /**
     * draw yourself into a given renderWindow
     *
     * @param R - the window in which to draw.
     */
    void draw (sf::RenderWindow &R);
    
    /**
     * prints a poly outline -- for cliptest assignment
     */
    void printLoop (int n, float x[], float y[] );
    
    /**
     * draws a filled poly -- for cliptest assignment
     */
    void printPoly (int n, float x[], float y[] );
    
};


#endif
