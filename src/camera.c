
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
#include "userControl/options.h"


unsigned char genCamera
(void)
{
	addSta_Actor();
	assignAIUpdate(updateCamera);
	setPos(genVec3(0.0, 0.0, 0.0));
	setBounds(0.0, 0.0);
	return getActor();
}
void updateCamera(unsigned short deltaMS)
{

	// TODO: make rotation fit circle. Complete circle.
	//	Currently, mouse circle ts about 1/2 of screen.
	//	change value in keyboard.c and directionComponent.c
	setPos(genVec3(0, 0, 0));
	GLint CameraPlacementLoc = glGetUniformLocation( shaderProgram, "cameraPlacement" );
	
	// creates rotation matrix
	//printf("creating camera rotation matrix\n");
	//printVec3(direction[getActor()].forward);
	float angle = (float) (-120 * acos(dotVec3(k, direction[getActor()].forward)));
	//printf("angle = %f\n", angle);
	vec3 around = crossVec3(k, direction[getActor()].forward);
	around = normalizeVec3(around);
	mat4 cameraPlacement = QuaternionToRotationMatrix(UnitQuaternion(around, angle));
	cameraPlacement = translateMat4(cameraPlacement, scaleVec3(physics[getActor()].Pos, -1));
	//printMat4(cameraPlacement);
	
	glUniformMatrix4fv(CameraPlacementLoc, 1, GL_TRUE, &cameraPlacement.mat[0][0]);
}
