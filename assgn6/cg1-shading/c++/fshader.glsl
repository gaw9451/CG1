// Light color
uniform vec4 lightColor;

// Diffuse reflection color
uniform vec4 diffuseColor;

// Specular exponent for sphere
uniform float specExp;

// Specular color for sphere
uniform vec4 specColor;

// Vectors "attached" to vertex and get sent to fragment shader
varying vec3 lPos;
varying vec3 vPos;
varying vec3 vNorm;


void main()
{        
    // calculate your vectors
    vec3 L = normalize (lPos - vPos);
    vec3 N = normalize (vNorm);
    vec3 V = normalize (-vPos);
    vec3 R = normalize((dot(L,2.0*N))*N - L);
    
     // calculate components
    vec4 diffuse = lightColor * diffuseColor * (dot(N, L));
    vec4 specular;
    if( dot(V,R) > 0.0 && dot(N,L) > 0.0 ) {
        specular = lightColor * specColor * (pow(dot(V,R), specExp));
    } else {
	specular = vec4(0.0,0.0,0.0,0.0);
    }

    // set the final color
    gl_FragColor = diffuse + specular;

}
