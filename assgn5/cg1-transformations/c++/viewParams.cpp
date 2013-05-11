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
#include <iostream>

using namespace std;

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
	GLint scale = glGetUniformLocation( program, "scale" );
	GLint rotation = glGetUniformLocation( program, "rotation" );
	GLint translation = glGetUniformLocation( program, "translation" );
	GLint eyepoint = glGetUniformLocation( program, "eyepoint" );
	GLint lookat = glGetUniformLocation( program, "lookat" );
	GLint up = glGetUniformLocation( program, "u" );
	GLint left = glGetUniformLocation( program, "l" );
	GLint right = glGetUniformLocation( program, "r" );
	GLint top = glGetUniformLocation( program, "t" );
	GLint bottom = glGetUniformLocation( program, "b" );
	GLint near = glGetUniformLocation( program, "n" );
	GLint far = glGetUniformLocation( program, "f" );
	GLint frustum = glGetUniformLocation( program, "frustum" );

	/*model transformations*/
	glUniform3f( scale, 1.0, 4.0, 1.0 );
	glUniform3f( rotation, 0.0, 50.0, 90.0 );
	glUniform3f( translation, 1.0, 0.0, -1.0 );

	/*view transformations*/
	glUniform3f( eyepoint, 0.0, 3.0, 3.0 );
	glUniform3f( lookat, 1.0, 0.0, 0.0 );
	glUniform3f( up, 0.0, 1.0, 0.0 );

	/*projection transformations*/
	glUniform1f( left, -1.5 );
	glUniform1f( right, 1.0 );
	glUniform1f( top, 1.5 );
	glUniform1f( bottom, -1.5 );
	glUniform1f( near, 1.0 );
	glUniform1f( far, 8.5 );

	glUniform1f( frustum, 1 );

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

	GLint scale = glGetUniformLocation( program, "scale" );
	GLint rotation = glGetUniformLocation( program, "rotation" );
	GLint translation = glGetUniformLocation( program, "translation" );
	GLint eyepoint = glGetUniformLocation( program, "eyepoint" );
	GLint lookat = glGetUniformLocation( program, "lookat" );
	GLint up = glGetUniformLocation( program, "u" );
	GLint left = glGetUniformLocation( program, "l" );
	GLint right = glGetUniformLocation( program, "r" );
	GLint top = glGetUniformLocation( program, "t" );
	GLint bottom = glGetUniformLocation( program, "b" );
	GLint near = glGetUniformLocation( program, "n" );
	GLint far = glGetUniformLocation( program, "f" );
	GLint frustum = glGetUniformLocation( program, "frustum" );

	/*model transformations*/
	glUniform3f( scale, 1.0, 4.0, 1.0 );
	glUniform3f( rotation, 0.0, 50.0, 90.0 );
	glUniform3f( translation, 1.0, 0.0, -1.0 );

	/*view transformations*/
	glUniform3f( eyepoint, 0.0, 3.0, 3.0 );
	glUniform3f( lookat, 1.0, 0.0, 0.0 );
	glUniform3f( up, 0.0, 1.0, 0.0 );

	/*projection transformations*/
	glUniform1f( left, -1.5 );
	glUniform1f( right, 1.0 );
	glUniform1f( top, 1.5 );
	glUniform1f( bottom, -1.5 );
	glUniform1f( near, 1.0 );
	glUniform1f( far, 8.5 );

	glUniform1f( frustum, 0 );
}

