#version 330

#define PI 3.14159265358979323846

layout (location = 0) in vec3 position;

uniform vec3 actorWorldPosition;
uniform vec3 actorRotateVector;
uniform vec3 actorRotateAngle;
uniform vec3 cameraWorldPosition;
uniform vec3 cameraRotateVector;
uniform vec3 cameraRotateAngle;
uniform float ScreenScale;
uniform int FOV;


vec3 QuaternionRotation( vec3, vec3, float );

void main()
{
	
	vec3 k = vec3( 0.0, 0.0, 1.0 );
	vec3 j = vec3( 0.0, 1.0, 0.0 );
	
	position = QuaternionRotation(position, j, PI / 2);
	
	vec3 worldPosition = rotated + actorWorldPosition;
	
	gl_Position = vec4(worldPosition , 1.0);
	/*
	vec3 actorTransformed = QuaternionRotation( position, actorRotateVector, actorRotateAngle );
	
	vec3 worldPosition = actorTransformed + actorWorldPosition;

	vec3 cameraTransformed = QuaternionRotation( worldPosition, cameraRotateVector, cameraRotateAngle );

	vec3 viewPosition = cameraTransform - cameraPosition;
	if (viewPosition.z <= 0)
		//cancel draw of this point.
	//TODO: reaserch canceling draw of single point in shader.
	
	gl_Position = viewPosition;
	
	float FOVMultiplier = 90 / FOV;
	// gl_Position = vec4(projectionTranformed, viewPosition.y * FOVMultiplier);
	*/
}

// Hamilton Product
vec4 HProduct( vec4 quaOne, vec4 quaTwo )
{
	// x is the scalar component, yzw is the vector component
	vec3 one = quaOne.yzw;
	vec3 two = quaTwo.yzw;
	return vec4( quaOne.x * quaTwo.x - dot( one, two ), quaOne.x * two + quaTwo.x * one + cross( one, two ) );
}

vec3 QuaternionRotation( vec3 rotate, vec3 around, float angle )
{
	vec4 quaRotate = vec4( 0.0, rotate );
	vec4 quaAround = vec4( cos( angle / 2 ), sin( angle / 2 ) * around );
	vec4 quaConjugate = -1 * quaAround;
	return HProduct( HProduct( quaAround, quaRotate ), quaConjugate ).yzw;
	
}

