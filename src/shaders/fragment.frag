#version 130

out vec4 fragColor;
in float brightness;
in vec2 TexCoord;

uniform sampler2D Texture;

in float col;

vec4 ambiantLight;
void main()
{
	ambiantLight = vec4(0.2, 0.1, 0.0, 1.0);
	fragColor = ambiantLight + ((brightness*brightness) * texture(Texture, TexCoord));
}


