//
//  viewParams.h
//  
//
//  Created by Joe Geigel on 1/23/13.
//
//

#ifndef __viewParams__
#define __viewParams__

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#endif

void setUpFrustrum (GLuint program);
void setUpOrtho (GLuint program);


#endif 
