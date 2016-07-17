#version 130

uniform sampler2D Texture;

in vec2 frag_uv_coords;
out vec4 frag_color;

void main()
{
	frag_color = texture(Texture, frag_uv_coords);
	
	// opposite color
	//frag_color = vec4(vec3(1.0, 1.0, 1.0) - texture(Texture, frag_uv_coords).xyz, texture(Texture, frag_uv_coords).w);
	
	// b & w, not color corrected
	//vec3 color = texture(Texture, frag_uv_coords).xyz;
	//float average = (color.r + color.g + color.b) / 3;
	//frag_color = vec4(average, average, average, texture(Texture, frag_uv_coords).w);
	
	// b & w, color corrected
	//vec3 color = texture(Texture, frag_uv_coords).xyz;
	//float average = 0.2126 * color.r + 0.7152 * color.g + 0.0722 * color.b;
	//frag_color = vec4(average, average, average, texture(Texture, frag_uv_coords).w);
}


