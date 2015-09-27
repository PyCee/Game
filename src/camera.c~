
#include "dataTypes.h"
#include "camera.h"

#include <stdlib.h>
#include "math/gMath.h"
#include "math/matrix.h"
#include "math/quaternion.h"
#include "actors.h"
#include "shaders/shaders.h"
#include "actorComponents/physicsComponent.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>
#include <stdio.h>


U8 genCamera
(void)
{
	U8 actorID = addSta_Actor();
	assignAIUpdate( actorID, updateCamera );
	setPos(actorID, genVec3(0.0, 0.0, 0.0));
	setBounds(actorID, 0.0, 0.0);
	return actorID;
}
void updateCamera (U8 actorID, U16 deltaMS)
{
	setPos(actorID, genVec3(0, 0, 0));
	GLint CameraPlacementLoc = glGetUniformLocation( shaderProgram, "cameraPlacement" );
	
	// creates rotation matrix
	printf("creating camera rotation matrix\n");
	F32 angle = (F32) (-1 * acos(dotVec3(k, Actors.direction[actorID].forward)));
	//printf("angle = %f\n", angle);
	vec3 around = crossVec3(k, Actors.direction[actorID].forward);
	around = NormalizeNormal(around);
	//PrintVec3(around);
	mat4 cameraPlacement = QuaternionToRotationMatrix(UnitQuaternion(around, angle));
	cameraPlacement = translateMat4(cameraPlacement, scaleVec3(genVec3(getPosX(actorID), getPosY(actorID), getPosZ(actorID)), -1));
	//printMat4(cameraPlacement);
	
	glUniformMatrix4fv(CameraPlacementLoc, 1, GL_TRUE, &cameraPlacement.mat[0][0]);
}
