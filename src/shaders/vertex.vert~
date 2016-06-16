#version 130

in vec3 localPosition;
in vec3 normal;
in vec2 texCoords;
uniform mat4 localSpace;
uniform mat4 worldSpace;
uniform mat4 viewSpace;
uniform mat4 clipSpace;

uniform vec3 cameraPosition;

out float brightness;
out vec2 UV;

void main()
{
	gl_Position = worldSpace * vec4(localPosition, 1.0);
	UV = texCoords;
	
	
	vec3 lightPosition = vec3(0.0, 0.0, 0.0); // in world space
	
	
	
	vec3 vertNormal = normalize((worldSpace * vec4(normal, 0.0)).xyz);
	vec3 pointLight = lightPosition - gl_Position.xyz;
	
	
	
	float diffuse = clamp(dot(vertNormal, pointLight), 0, 1);
	brightness = diffuse;
	
	float distSq = pointLight.x * pointLight.x + pointLight.y * pointLight.y + pointLight.z * pointLight.z;
	brightness = brightness*30 / distSq;
	//brightness = clamp(dot(pointCamera, reflectedLight), 0, 1);
	//brightness = clamp(dot(vec3(0.0, 1.0, 0.0), pointLight), 0, 1);
	
//	brightness = 1 - brightness;// Reverse Brightness
//	brightness = 1;// remove effects of lighting
	gl_Position = clipSpace * viewSpace * gl_Position;
}
