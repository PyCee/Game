#version 130

in vec2 localPosition;
in vec2 texCoords;

out vec2 TexCoords;
void main()
{
	gl_Position = vec4(localPosition, 0.0, 1.0);
	TexCoords = texCoords;
}
