//
//  viewParams.cpp
//  
//
//  Created by Joe Geigel on 1/23/13.
//
//

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#endif

#include "viewParams.h"

/**
 * This functions sets up the view and projection parameter for a frustrum
 * projection of the scene. See the assignment description for the values
 * for the projection parameters.
 *
 * You will need to write this function, and maintain all of the values needed 
 * to be sent to the vertex shader.
 *
 * @param program - The ID of an OpenGL (GLSL) program to which parameter values
 *    are to be sent
 *
 */
void setUpFrustrum (GLuint program)
{
    // Add your code here.

}


/**
 * This functions sets up the view and projection parameter for an orthographic
 * projection of the scene. See the assignment description for the values
 * for the projection parameters.
 *
 * You will need to write this function, and maintain all of the values needed
 * to be sent to the vertex shader.
 *
 * @param program - The ID of an OpenGL (GLSL) program to which parameter values
 *    are to be sent
 *
 */
void setUpOrtho (GLuint program)
{
    // Add your code here.

}

