#version 130

uniform sampler2D Texture;

in vec2 TexCoords;
out vec4 fragColor;

#define tex(x, y) texture(Texture, vec2(x, y))
void main()
{
	fragColor = texture(Texture, TexCoords);
	
	// opposite color
	//fragColor = vec4(vec3(1.0, 1.0, 1.0) - texture(Texture, TexCoords).xyz, texture(Texture, TexCoords).w);
}


