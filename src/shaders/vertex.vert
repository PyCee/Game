#version 130

uniform int FOV;

in vec3 localPosition;
in vec3 normal;
in vec2 texCoords;
uniform mat4 actorPlacement;
uniform mat4 worldPlacement;
uniform mat4 cameraPlacement;

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
	vec3 pointLight = normalize(liPos - gl_Position.xyz);// - liPos);
	// vec3 reflectedLight = 
	brightness = 1 - clamp(dot(pointCamera, pointLight), 0, 1);
}
