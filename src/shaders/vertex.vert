#version 330

layout (location = 0) in vec3 position;

uniform vec3 actorWorldPosition;
uniform vec3 actorOrientation;
uniform vec3 cameraWorldPosition;
uniform vec3 cameraOrientation;

vec3 QuaternionRotation( vec3, vec3, float );

void main()
{
	gl_Position = vec4( position, 1.0 );
	/*
	vec3 k = vec3( 0.0, 0.0, 1.0 );
	
	float actorAngle = acos( dot( actorOrientation, k ) );
	vec3 actorOrient = cross( actorOrientation, k );
	vec3 actorTransformed = QuaternionRotation( position, actorOrient, actorAngle );
	
	vec3 worldPosition = actorTransformed + actorWorldPosition;
	
	float cameraAngle = acos( dot( cameraOrientation, k ) );
	vec3 cameraOrient = cross( cameraOrientation, k );
	vec3 cameraTransformed = QuaternionRotation( actorTransformed, cameraOrient, actorAngle );

	vec3 viewPosition = cameraTransform - cameraPosition;
	
	
	gl_Position = viewPosition;
	*/
}

// Hamilton Product
vec4 HProduct( vec4 quaOne, vec4 quaTwo )
{
	// x is the scalar component, yzw is the vector component
	vec3 one = quaOne.yzw;
	vec3 two = quaTwo.yzw;
	return vec4( quaOne.x * quaTwo.x + dot( one, two ), quaOne.x * two + quaTwo.x * one + cross( one, two ) );
}

vec3 QuaternionRotation( vec3 rotate, vec3 around, float angle )
{
	vec4 quaRotate = vec4( 0.0, rotate );
	vec4 quaAround = vec4( cos( angle / 2 ), sin( angle / 2 ) * around );
	vec4 quaConjugate = -1 * quaAround;
	return HProduct( HProduct( quaAround, quaRotate ), quaConjugate ).yzw;
	
}

