#version 130

uniform int FOV;

in vec3 localPosition;
in vec3 normal;
in vec2 texCoords;
uniform mat4 localSpace;
uniform mat4 worldSpace;
uniform mat4 viewSpace;
uniform mat4 clipSpace;

uniform vec3 cameraPosition;

out float brightness;
out vec2 TexCoords;
out float col;

void main()
{
	gl_Position = worldSpace * vec4(localPosition, 1.0);
	TexCoords = texCoords;
	col = localPosition.z;
	
	vec3 vertNormal = normalize((worldSpace * vec4(normal, 1.0)).xyz);
	
	vec3 lightPosition = vec3(1.0, 2.5, -5.0); // in view space
	vec3 pointCamera = normalize(cameraPosition - gl_Position.xyz);
	
	vec3 lightPoint = normalize(gl_Position.xyz - lightPosition);
	vec3 pointLight = normalize(lightPosition - gl_Position.xyz);
	vec3 reflectedLight = lightPoint - 2 * normal * dot(lightPoint, normal);
	//brightness = 1 - clamp(dot(pointCamera, reflectedLight), 0, 1);
	brightness = 1 - clamp(dot(vec3(0.0, 1.0, 0.0), pointLight), 0, 1);
	//brightness = 1;// remove effects of lighting
	gl_Position = clipSpace * viewSpace * gl_Position;
}
