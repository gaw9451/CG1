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
#include <SOIL.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <SOIL.h>
#endif


#include "textureParams.h"

#include <stdio.h>


/**
 * This functions loads texture data to the GPU.
 *
 * You will need to write this function, and maintain all of the values needed 
 * to be sent to the various shaders.
 *
 * @param filename - The name of the texture file.
 *
 */
void loadTexture (char *filename)
{
	GLuint tex_2d = SOIL_load_OGL_texture( "texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS );

	if( tex_2d == 0 ) {
		printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
	}
}

/**
 * This functions sets up the parameters
 * for texture use.
 *
 * You will need to write this function, and maintain all of the values needed
 * to be sent to the various shaders.
 *
 * @param program - The ID of an OpenGL (GLSL) program to which parameter values
 *    are to be sent
 *
 */
void setUpTexture (GLuint program)
{
	glUseProgram( program );
	GLint baseImageLoc = glGetUniformLocation( program, "baseImage" );
	GLint normalMapLoc = glGetUniformLocation( program, "normalMap" );
	GLint shadowMapLoc = glGetUniformLocation( program, "shadowMap" );


}



