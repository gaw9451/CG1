/**
 *
 * simpleShape.cpp
 *
 * routines for adding triangles to create a new mesh
 *
 * Students are not to modify this file.
 *
 */

#ifdef __APPLE__
#include <OPENGL/gl.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#include <vector>
#include <iostream>

using namespace std;

/**
 * common variables...should probably make this a class and make these
 * data members
 */
vector<float> points;
float *pointArray = 0;
GLushort *elemArray = 0;


/**
 * clear the current shape
 */
void clearShape ()
{
    if (pointArray) {
        delete pointArray;
        delete elemArray;
        pointArray = 0;
        elemArray = 0;
    }
    points.clear();
}


/**
 * adds a triangle to the current shape
 */
void addTriangle (float x0, float y0, float z0,
                  float x1, float y1, float z1,
                  float x2, float y2, float z2)
{
    points.push_back (x0);
    points.push_back (y0);
    points.push_back (z0);
    points.push_back (1.0);
    
    points.push_back (x1);
    points.push_back (y1);
    points.push_back (z1);
    points.push_back (1.0);
    
    points.push_back (x2);
    points.push_back (y2);
    points.push_back (z2);
    points.push_back (1.0);
  
}


/**
 * gets the vertex points for the current shape
 */
float *getVerticies ()
{
    // delete the old point array of we have one
    if (pointArray) {
        delete pointArray;
    }
    
    // create and fill a new point array
    pointArray = new float[points.size()];
    elemArray = new GLushort[points.size()];
    for (int i=0; i < points.size(); i++) {
        pointArray[i] = points[i];
    }
        
    return pointArray;
}

/**
 * gets the  array of elements for the  current shape
 */
GLushort *getElements ()
{
    // delete the old point array of we have one
    if (elemArray) {
        delete elemArray;
    }
    
    // create and fill a new point array
    elemArray = new GLushort[points.size()];
    for (int i=0; i < points.size(); i++) {
        elemArray[i] = i;
    }
    
    return elemArray;
}



/**
 * returns number of verticies in current shape
 */
int nVerticies ()
{
    return points.size() / 4;
}
