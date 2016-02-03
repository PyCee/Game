#version 130

out vec4 fragColor;
in float brightness;
in vec2 TexCoord;

uniform sampler2D Texture;


in float col;

void main()
{
	fragColor = brightness * texture(Texture, TexCoord);
}





