/**
 * header file for functions that manage the current shape 
 * being defined (including the addTriangles() function.
 *
 * Students are not to modify this file
 */

#ifndef __addTriangles__
#define __addTriangles__

void clearShape ();

void addTriangle (float x0, float y0, float z0,
                  float x1, float y1, float z1,
                  float x2, float y2, float z2);

GLushort *getElements ();

float *getVerticies ();

int nVerticies ();

#endif