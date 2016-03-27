
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
#include "actorComponents/physics/vector.h"

void genFrustum(void)
{
	float aspectRatio = (float)Option[ASPECT_RATIO_X] / (float)Option[ASPECT_RATIO_Y];
	float fov = (M_PI / 180) * (float)Option[FIELD_OF_VIEW];
	float near = 0.3;
	float far = 100;
	mat4 clip = genZeroMat4();
	clip.mat[0][0] = 1 / tan(fov / 2);
	clip.mat[1][1] = 1 / tan(fov / 2) * aspectRatio;
	clip.mat[2][2] = -1 * far / (far - near);
	clip.mat[2][3] = -1 * 2 * (far * near) / (far - near);
	clip.mat[3][2] = -1;
	glUniformMatrix4fv(ClipSpaceLoc, 1, GL_TRUE,
				&clip.mat[0][0]);
}
unsigned char genCamera(void)
{
	addSta_Actor();
	assignAIUpdate(updateCamera);
	POS = genVec3(0.0, 0.0, 0.0);
	setBounds(0.0, 0.0);
	return getActor();
}
void updateCamera(unsigned short deltaMS)
{
	FORWARD = genVec3(0.0, 0.0, 1.0);
	if(cameraPitch > 360)
		cameraPitch -=360;
	if(cameraYaw > 360)
		cameraYaw -=360;
	if(cameraRoll > 360)
		cameraRoll -=360;
	
	if(cameraPitch < 0)
		cameraPitch += 360;
	if(cameraYaw < 0)
		cameraYaw += 360;
	if(cameraRoll < 0)
		cameraRoll += 360;
	
	vec4 cameraQua = UnitQuaternion(genVec3(0, 0, 1), 0);
	cameraQua = QuatMultiply(UnitQuaternion(j, -1 * cameraYaw), cameraQua);
	cameraQua = QuatMultiply(UnitQuaternion(i, -1 * cameraPitch), cameraQua);
	
	mat4 Translate = genIdentityMat4();
	Translate = translateMat4(Translate, scaleVec3(physics[getControlledActor()].Pos, -2));
	mat4 Rotate = QuaternionToRotationMatrix(cameraQua);
	
	mat4 transformation = mat4Product(Rotate, Translate);
	
	glUniformMatrix4fv(ViewSpaceLoc, 1, GL_TRUE, &transformation.mat[0][0]);
}
