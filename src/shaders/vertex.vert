#version 130

uniform int FOV;

in vec3 localPosition;
in vec3 normal;
in vec2 texCoords;
uniform mat4 actorPlacement;
uniform mat4 worldPlacement;
uniform mat4 cameraPlacement;
uniform mat4 projection;

out float brightness;
out vec2 TexCoords;

//vec3 QuaternionRotation( vec3, vec3, float );

void main()
{
	gl_Position = worldPlacement * vec4(localPosition, 1.0);
	TexCoords = texCoords;
	
	vec3 liPos = vec3(0.0, 0.5, 0.0);
	vec3 lightPosition = (worldPlacement * vec4(liPos, 1.0)).xyz;
	vec3 pointCamera = normalize(-1 * gl_Position.xyz);
	vec3 pointLight = normalize(liPos - gl_Position.xyz);
	//vec3 reflectedLight = 2 * normal - pointLight;
	brightness = 1 - clamp(dot(pointCamera, pointLight), 0, 1);
	gl_Position = gl_Position * projection;
}
