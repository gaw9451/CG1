//
//  simpleCanvas.cpp
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//

#include <SFML/System.hpp>
#include "extendedCanvas.h"
#include <SFML/Config.hpp>
#include <SFML/Graphics/Sprite.hpp>

/**
 * This is a special subclass of simpleCanvas with functionality
 * for testing out the clipping assignment.
 *
 * Note, this class should only be used for clipping assignment and
 * only for testing purposes!!! *
 */

/**
 * Constructor
 *
 * @param w width of canvas
 * @param h height of canvas
 */
extendedCanvas::extendedCanvas(int w, int h) : simpleCanvas(w,h)
{
}

/**
 * prints a poly outline -- for cliptest assignment
 */
void extendedCanvas::printLoop (int n, float x[], float y[] )
{
    sf::Shape P;
    for (int i=0; i < n; i++)
        P.AddPoint (x[i], height - y[i], myColor, myColor);
    
    P.EnableFill (false);
    P.EnableOutline (true);
    P.SetOutlineWidth (1);
    
    polys.push_back (P);
}

/**
 * draws a filled poly -- for cliptest assignment
 */
void extendedCanvas::printPoly (int n, float x[], float y[] )
{
    sf::Shape P;
    for (int i=0; i < n; i++)
        P.AddPoint (x[i], height - y[i], myColor, myColor);
    
    P.EnableFill (true);
    P.EnableOutline (true);
    
    polys.push_back (P);
}



/**
 * draw yourself into a given renderWindow
 *
 * @param R - the window in which to draw.
 */
void extendedCanvas::draw (sf::RenderWindow &R)
{
    // draw as usual
    simpleCanvas::draw (R);
    
    // draw your polys
    vector<sf::Shape>::iterator it;
    for (it = polys.begin(); it != polys.end(); it++) {
        R.Draw ((*it));
    }
}


