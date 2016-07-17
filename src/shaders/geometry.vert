#version 130

in vec3 position;
in vec3 normal;
in vec2 uv_coords;

uniform mat4 world_space;
uniform mat4 view_space;
uniform mat4 clip_space;

out vec4 frag_position;
out vec4 frag_normal;
out vec2 frag_uv_coords;

void main()
{
	frag_position = world_space * vec4(position, 1.0);
	gl_Position = clip_space * view_space * frag_position;
	frag_normal = vec4(normalize((world_space * vec4(normal, 0.0)).xyz), 0.0);
	frag_uv_coords = uv_coords;
}
