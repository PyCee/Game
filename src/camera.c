
#include "dataTypes.h"
#include "camera.h"

#include <stdlib.h>
#include "math/gMath.h"
#include "actors.h"
#include "shaders/shaders.h"
#include "actorComponents/physicsComponent.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>


U8 genCamera
(void)
{
	U8 actorID = addSta_Actor();
	assignAIUpdate( actorID, updateCamera );
	setPos(actorID, genVec3(0.0, 0.0, 1.0));
	setBounds(actorID, 0.0, 0.0);
}
void updateCamera (U8 actorID, U16 deltaMS)
{
	GLint cameraWorldPositionLoc = glGetUniformLocation( shaderProgram, "cameraWorldPosition" );
	GLint cameraRotateVectorLoc = glGetUniformLocation( shaderProgram, "cameraRotateVector" );
	GLint cameraRotateAngleLoc = glGetUniformLocation( shaderProgram, "cameraRotateAngle" );
	
	glUniform3f( cameraWorldPositionLoc, getPosX( actorID ), getPosY( actorID ), getPosZ( actorID ) );
	
	vec3 cameraOrient = cross( k, Actors.direction[actorID].forward );
	glUniform3f( cameraRotateVectorLoc, cameraOrient.vec[0], cameraOrient.vec[1], cameraOrient.vec[2] );
	
	glUniform1f( cameraRotateAngleLoc, acos( dot( Actors.direction[actorID].forward, k ) ) );
}
