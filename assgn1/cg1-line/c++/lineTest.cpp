//
//  lineTest.cpp
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//
 
#include <SFML/Graphics.hpp>
#include "simpleCanvas.h"
#include "Rasterizer.h"

/**
 * 
 * main program for line drawing assignment
 *
 */

int main (int argc, char *argv[])
{
    simpleCanvas T (300, 300);
    Rasterizer R(300);
    T.setColor (0.0, 0.0, 0.0);
    T.clear();
    T.setColor (1.0, 1.0, 1.0);
    
    R.drawLine( 100, 100, 100, 150, T );  /* Vertical */
    R.drawLine( 100, 100, 100, 50, T );   /* Vertical */
    
    R.drawLine( 100, 100, 50, 100, T );   /* Horizontal */
    R.drawLine( 100, 100, 150, 100, T );  /* Horizontal */
    
    R.drawLine( 100, 100, 150, 150, T );  /* + diagonal */
    R.drawLine( 100, 100, 50, 50, T );    /* + diagonal */
    
    R.drawLine( 100, 100, 50, 150, T );   /* - diagonal */
    R.drawLine( 100, 100, 150, 50, T );   /* - diagonal */
    
    R.drawLine( 100, 100, 150, 125, T );  /* shallow + slope */
    R.drawLine( 100, 100, 50, 75, T );    /* shallow + slope */
    
    R.drawLine( 100, 100, 150, 75, T );   /* shallow - slope */
    R.drawLine( 100, 100, 50, 125, T );   /* shallow - slope */
    
    R.drawLine( 100, 100, 125, 150, T );  /* steep + slope */
    R.drawLine( 100, 100, 75, 50, T );    /* steep + slope */
    
    R.drawLine( 100, 100, 125, 50, T );   /* steep - slope */
    R.drawLine( 100, 100, 75, 150, T );   /* steep - slope */
    
    sf::RenderWindow App(sf::VideoMode(300, 300), "Line Test");
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }
        
        // Clear screen
        App.Clear();
        
        // Draw your canvas
        T.draw (App);
    
        App.Display();
    }
    
    return 0;

}
