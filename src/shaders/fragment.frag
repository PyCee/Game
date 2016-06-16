#version 130

#define AMBIANT_LIGHT vec3(0.0, 0.0, 0.0)


uniform sampler2D Texture;

in float brightness;
in vec2 UV;
out vec3 color;
void main()
{
	color = AMBIANT_LIGHT + ((brightness) * texture(Texture, UV).rgb);
}


