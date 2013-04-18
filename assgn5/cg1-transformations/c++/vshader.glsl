attribute vec4 vPosition;

void main()
{    
	gl_Position =  vPosition;
	
	/*model transform*/
	float pi = 4.0 * atan( 1.0 );
	float angle = pi * 50.0/180.0;
	mat4 M = mat4( 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 );
	gl_Position = vPosition;
}
