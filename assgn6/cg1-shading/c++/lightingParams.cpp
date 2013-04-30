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

#include "lightingParams.h"

// materials values
GLfloat lightpos[4] = {0.0, 5.0, 2.0, 1.0};
GLfloat lightcolor[4] = {1.0, 1.0, 0.0, 1.0};

GLfloat diffuse[4] = {0.89, 0.0, 0.0, 1.0};


/**
 * This functions sets up the lighting, material, and shading parameters 
 * for the Phong shader.
 *
 * You will need to write this function, and maintain all of the values needed 
 * to be sent to the vertex shader.
 *
 * @param program - The ID of an OpenGL (GLSL) program to which parameter values
 *    are to be sent
 *
 */
void setUpPhong (GLuint program)
{
    // Here's code for the diffuse component.
    GLuint light = glGetUniformLocation( program , "lightPosition" );
    GLuint lightc = glGetUniformLocation( program , "lightColor" );
    GLuint diff = glGetUniformLocation( program , "diffuseColor" );
   
    glUniform4fv( light , 1 , lightpos );
    glUniform4fv( lightc , 1 , lightcolor );
    glUniform4fv( diff , 1 , diffuse );
       
    // You need to add code for the specular component

}


