#version 130

in vec2 position;
in vec2 uv_coords;

out vec2 frag_uv_coords;
void main()
{
	gl_Position = vec4(position, 0.0, 1.0);
	frag_uv_coords = uv_coords;
}
