//
//  tessMain.cpp
//  
//
//  Main program for tessellation assignment.
//
//  Students should not be modifying this file.
//

#include <stdlib.h>
#include <iostream>

#ifdef __APPLE__ 
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#endif

#include "shaderProgram.h"
#include "simpleShape.h"
#include "cg1Shape.h"

using namespace std;

// The shapes that we can draw
#define CUBE 0
#define CYLINDER 1
#define CONE 2
#define SPHERE 3
int currentShape = CUBE;

// subdivision for tessellation
int division1 = 3;
int division2 = 3;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

// buffer information
bool bufferInit = false;
GLuint buffer, ebuffer;
GLuint program;

// shader arguments...rotation of object.
GLuint theta; // theta uniform location
float angles[3] = {30.0, 30.0, 0.0};
float angleInc = 5.0;


/**
 * create a new shape by tesselating one of 
 * the 4 basic objects
 */
void createNewShape()
{
    // clear your old shape
    clearShape();
    
    // create the new shape..
    switch (currentShape)
    {
        case CUBE: makeCube (division1); break;
        case CYLINDER: makeCylinder (0.5, division1, division2); break;
        case CONE: makeCone (0.5, division1, division2); break;
        case SPHERE: makeSphere (0.5, division1, division2); break;
            
    }
    
    // get and load the verticies for your shape
    int NumElements = nVerticies() / 3;
    float *points = getVerticies();
    int dataSize = nVerticies() * 4 * sizeof (float);
    
    // get and load the element data
    GLushort *elements = getElements();
    int edataSize = nVerticies() * sizeof (GLushort);
    
    // setup the vertex buffer
    if (bufferInit) glDeleteBuffers (1, &buffer);
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, dataSize, points, GL_STATIC_DRAW );
    bufferInit = true;
    
    // setup the element buffer
    if (bufferInit) glDeleteBuffers (1, &ebuffer);
    glGenBuffers( 1, &ebuffer );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, edataSize, elements, GL_STATIC_DRAW );
}


// OpenGL initialization 
void init() {
    
    // Load shaders and use the resulting shader program
    program = setUpAShader( "vshader.glsl", "fshader.glsl" );
    if (!program) {
        cerr << "Error setting up shaders" << endl;
        exit(1);
    }
    
    glEnable( GL_DEPTH_TEST ); 
    glEnable(GL_CULL_FACE);
    glClearColor( 1.0, 1.0, 1.0, 1.0 );
    glCullFace(GL_BACK);
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    
    // initally create a cube
    createNewShape();
}


void
display( void )
{
    // clear your frame buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    // bind your vertex buffer
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    
    // bind your element array buffer
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebuffer );
    
    // set up your attribute variables
    glUseProgram( program );
    GLuint vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0,
                          BUFFER_OFFSET(0) );
       
    // pass in your rotation as a uniform variable
    theta = glGetUniformLocation(program, "theta");
    glUniform3fv (theta, 1, angles);
    
    // draw your shape
    glDrawElements (GL_TRIANGLES, nVerticies(),  GL_UNSIGNED_SHORT, (void *)0);
    
    // swap the buffers
    glutSwapBuffers();
}


void
keyboard( unsigned char key, int x, int y )
{
    switch( key ) {
        case 'x': angles[0] -= angleInc; break;
        case 'y': angles[1] -= angleInc; break;
        case 'z': angles[2] -= angleInc; break;  
        case 'X': angles[0] += angleInc; break;
        case 'Y': angles[1] += angleInc; break;
        case 'Z': angles[2] += angleInc; break; 
            
        case 'c' : currentShape = CUBE; createNewShape(); break;
        case 'C' : currentShape = CYLINDER; createNewShape(); break;
        case 'n' : currentShape = CONE; createNewShape(); break;
        case 's' : currentShape = SPHERE; createNewShape(); break;
            
        case '+': division1++; createNewShape(); break;
        case '=': division2++; createNewShape(); break;
        case '-': if (division1 > 1 ) {division1--; createNewShape();}break;
        case '_': if (division2 > 1)  {
                    division2--; 
                    if (currentShape != CUBE) createNewShape();
                }
        break;
    
            
        case 033:  // Escape key
        case 'q': case 'Q':
            exit( 0 );
        break;
    } 
    
    glutPostRedisplay();
}

int main (int argc, char **argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 512, 512 );
    glutCreateWindow( "CG1 - Tessellation Assignment" );
    
#ifndef __APPLE__
    glewInit();
#endif
    
    init();
    
    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    
    glutMainLoop();
    return 0;
}

