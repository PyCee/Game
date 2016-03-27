#version 130

uniform int FOV;

in vec3 localPosition;
in vec3 normal;
in vec2 texCoords;
uniform mat4 localSpace;
uniform mat4 worldSpace;
uniform mat4 viewSpace;
uniform mat4 clipSpace;

out float brightness;
out vec2 TexCoords;
out float col;

void main()
{
	gl_Position = worldSpace * vec4(localPosition, 1.0);
	TexCoords = texCoords;
	col = localPosition.z;
	
	vec3 lightPosition = vec3(0.0, 2.5, -5.0); // in view space
	vec3 pointCamera = normalize(-1 * gl_Position.xyz);
	vec3 pointLight = normalize(lightPosition - gl_Position.xyz);
	vec3 reflectedLight = 2 * normal - pointLight;
	brightness = 1 - clamp(dot(pointCamera, pointLight), 0, 1);
	//brightness *= 2;
	//brightness = 1;// temp remove effects of brightness
	gl_Position = clipSpace * viewSpace * gl_Position;
}
