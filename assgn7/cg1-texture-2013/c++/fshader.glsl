
varying vec4 color;
varying vec2 texCoord;

uniform sampler2D textureSample;

void main() 
{ 
  // replace with proper texture function
  gl_FragColor = texture2D( textureSample, texCoord );
} 
