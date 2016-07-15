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
out vec2 TexCoords;

void main()
{
	gl_Position = worldSpace * vec4(localPosition, 1.0);
	TexCoords = texCoords;
	
	
	vec3 lightPosition = vec3(0, 1.0, -1 * 5.0); // in world space
	
	float dReflectivity = 0.75;
	float sReflectivity = 1.0;
	float specularPow = 1;
	
	vec3 vertNormal = normalize((worldSpace * vec4(normal, 0.0)).xyz);
	vec3 lightPoint = normalize(lightPosition - gl_Position.xyz);
	vec3 pointCamera = normalize(cameraPosition - gl_Position.xyz);
	vec3 pointLight = normalize(gl_Position.xyz - lightPosition);
	vec3 reflectedLight = reflect(pointLight, vertNormal);
	
	brightness = 0;
	
	float diffuse = clamp(dot(vertNormal, lightPoint), 0, 1);
	brightness += dReflectivity * diffuse;
	
	if(dot(reflectedLight, vertNormal) >= 0){
		float specular = clamp(dot(pointCamera, reflectedLight), 0, 1);
		brightness += sReflectivity * pow(specular, specularPow);
	}
	float distSq = pointLight.x * pointLight.x + pointLight.y * pointLight.y + pointLight.z * pointLight.z;
	brightness = brightness / distSq;
	gl_Position = clipSpace * viewSpace * gl_Position;
}
