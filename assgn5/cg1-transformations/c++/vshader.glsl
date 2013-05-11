attribute vec4 vPosition;
uniform vec3 scale;
uniform vec3 rotation;
uniform vec3 translation;

uniform vec3 eyepoint;
uniform vec3 lookat;
uniform vec3 up;

uniform float l;
uniform float r;
uniform float t;
uniform float b;
uniform float n;
uniform float f;

uniform int frustum;

void main()
{    
	
	/*model transform*/
	float pi = 4.0 * atan( 1.0 );
	float angle = pi*50.0/180.0;
	mat4 M = mat4( 0, 1, 0, 0,
		      -4.0*cos( angle ), 0, -4.0*sin( angle ), 0,
		      -sin( angle ), 0, cos( angle ), 0,
		      1, 0, -1, 1 );

	/*projection transform*/
	mat4 P;
	if( frustum == 0 ) {
		float sx = 2.0/(r-l);
		float sy = 2.0/(t-b);
		float sz = -2.0/(8.5-1.0);
		float tx = (r+l)/(r-l);
		float ty = (t+b)/(t-b);
		float tz = (8.5+1.0)/(8.5-1.0);
		P = mat4( sx,  0,  0, 0,
				0, sy,  0, 0,
				0,  0, sz, 0,
			       tx, ty, tz, 1 );
	} else {
		float sx = 2.0*1.0/(r-l);
		float sy = 2.0*1.0/(t-b);
		float sz = -8.5/(8.5-1.0);
		float tx = (r+l)/(r-l);
		float ty = (t+b)/(t-b);
		float tz = -(8.5+1.0)/(8.5-1.0);
		P = mat4( sx,  0,  0,  0,
			   0, sy,  0,  0,
			  tx, ty, tz, -1,
			   0,  0, -2.0*8.5*1.0/(8.5-1.0), 0 );
	}
	gl_Position = M*vPosition;
 }
