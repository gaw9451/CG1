attribute vec4 vPosition;
attribute vec4 vColor;
attribute vec2 vTexCoord;

varying vec4 color;
varying vec2 texCoord;

void main()
{    
    color = vColor;
    texCoord = vTexCoord;
    gl_Position = vPosition;
}
