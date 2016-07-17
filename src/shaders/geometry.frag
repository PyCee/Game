#version 130

in vec4 frag_position;
in vec4 frag_normal;
in vec2 frag_uv_coords;

uniform sampler2D texture_map;

out vec4 geometry_buffer_position_map;
out vec4 geometry_buffer_normal_map;
out vec4 geometry_buffer_color_specularity_map;
void main()
{
	geometry_buffer_position_map = frag_position;
	geometry_buffer_normal_map = frag_normal;
	geometry_buffer_color_specularity_map = vec4(texture(texture_map, frag_uv_coords).xyz, 1.0);// TODO replace the '1.0' with the material's specular reflectivity
}
