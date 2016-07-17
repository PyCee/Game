#version 130

#define AMBIANT_LIGHT vec4(0.2, 0.0, 0.1, 0.0)

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
	vec3 frag_diffuse = texture(deferred_lighting_color_specularity_map, frag_uv_coords).rgb;
	float frag_specular = texture(deferred_lighting_color_specularity_map, frag_uv_coords).a;
	
	
	float brightness = 0;
	
	vec3 lightPosition = vec3(0, 1.0, -1 * 5.0); // in world space
	
	float dReflectivity = 1;
	float sReflectivity = frag_specular;
	float specularPow = 12;
	
		vec3 point_camera = normalize(camera_position - frag_position);
		vec3 point_light = lightPosition - frag_position;
		vec3 point_light_dir = normalize(point_light);
		
		vec3 reflected_light = 2 * dot(point_light_dir, frag_normal) * frag_normal - point_light_dir;
		
		
		float diffuse = clamp(dot(point_light_dir, frag_normal), 0, 1);
		brightness += dReflectivity * diffuse;
		
		if(dot(reflected_light, frag_normal) > 0){
			float specular = clamp(dot(point_camera, reflected_light), 0, 1);
			brightness += 1 * pow(specular, specularPow);
		}
		//float distSq = point_light.x * point_light.x + point_light.y * point_light.y + point_light.z * point_light.z;
		//brightness /= distSq;
	
	frag_color = AMBIANT_LIGHT + vec4(frag_diffuse * brightness, 1.0);
	
}
