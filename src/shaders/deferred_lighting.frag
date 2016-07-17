#version 130

#define AMBIANT_LIGHT vec4(0.1, 0.0, 0.3, 0.0)

in vec2 frag_uv_coords;

uniform sampler2D deferred_lighting_position_map;
uniform sampler2D deferred_lighting_normal_map;
uniform sampler2D deferred_lighting_color_specularity_map;
uniform vec3 camera_position;

out vec4 frag_color;
void main()
{
	vec3 frag_position = texture(deferred_lighting_position_map, frag_uv_coords).xyz;
	vec3 frag_normal = normalize(texture(deferred_lighting_normal_map, frag_uv_coords).xyz);
	//TODO why call it frag_diffuse if it represents overall color???
	vec3 frag_diffuse = texture(deferred_lighting_color_specularity_map, frag_uv_coords).rgb;
	float frag_specular = texture(deferred_lighting_color_specularity_map, frag_uv_coords).a;
	
	
	float brightness = 0;
	
	vec3 lightPosition = vec3(0, 1.0, -1 * 5.0); // in world space
	
	float dReflectivity = 1;
	float sReflectivity = frag_specular;
	float specularPow = 50;
	{
		vec3 point_light_dir = normalize(lightPosition - frag_position);
		vec3 reflected_light = reflect(-1 * point_light_dir, frag_normal);
		
		
		float diffuse = clamp(dot(point_light_dir, frag_normal), 0, 1);
		brightness += dReflectivity * diffuse;
		
		if(dot(reflected_light, frag_normal) > 0){
			float specular = clamp(dot(normalize(camera_position - frag_position), reflected_light), 0, 1);
			brightness += 1 * pow(specular, specularPow);
		}
		float distSq = dot(point_light_dir, point_light_dir);
		brightness = brightness / distSq;
	}
	frag_color = vec4(frag_diffuse * brightness, 1.0) + AMBIANT_LIGHT;
}
