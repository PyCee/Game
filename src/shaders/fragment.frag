#version 130

#define AMBIANT_LIGHT vec4(0.1, 0.0, 0.0, 0.0);


uniform sampler2D Texture;

in float brightness;
in vec2 TexCoords;
out vec4 fragColor;
void main()
{
	//fragColor = AMBIANT_LIGHT + ((brightness) * texture(Texture, TexCoords));
	fragColor = texture(Texture, TexCoords) * brightness + AMBIANT_LIGHT;
	
}


