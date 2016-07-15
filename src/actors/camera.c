
#include "camera.h"

#include <stdlib.h>
#include "../math/gMath.h"
#include "../math/matrix.h"
#include "../math/quaternion.h"
#include "../math/pythag.h"
#include "../actors.h"
#include "../shaders/shaders.h"
#include "../shaders/shaderProgram.h"
#include "../shaders/backBuffer.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>
#include <stdio.h>
#include "../userControl/options.h"
#include "../actorComponents/physics/vector.h"
#include "../actorComponents/physics/physicsAttributeController.h"

#include "../actorComponents/physicsComponent.h"
#include "../actorComponents/directionComponent.h"

void genFrustum(void)
{
	float aspectRatio = (float)Option[ASPECT_RATIO_X] / (float)Option[ASPECT_RATIO_Y];
	float fov = (M_PI / 180) * (float)Option[FIELD_OF_VIEW];
	float near = 0.101;
	float far = 100;
	mat4 clip = genZeroMat4();
	clip.mat[0][0] = 1 / tan(fov / 2);
	clip.mat[1][1] = 1 / tan(fov / 2) * aspectRatio;
	clip.mat[2][2] = -1 * far / (far - near);
	clip.mat[2][3] = -1 * 2 * (far * near) / (far - near);
	clip.mat[3][2] = -1;
	glUniformMatrix4fv(SMS_ClipSpaceLoc, 1, GL_TRUE,
				&clip.mat[0][0]);
}
unsigned char genCamera(void)
{
	return getActor();
}
void UpdateCamera(unsigned short deltaMS)
{
	unsigned char id = getActor();
	bindActor(getControlledActor());
	vec3 protagPos = *POSITION;
	bindActor(id);
	*POSITION = protagPos;
	mat4 Translate = genIdentityMat4();
	Translate = translateMat4(Translate, scaleVec3(*POSITION, -1));
	mat4 Rotate = QuaternionToRotationMatrix(*INVERSEFORWARDROTATION);
	
	mat4 transformation = mat4Product(Rotate, Translate);
	
	glUseProgram(*standardModelShader->program);
	glUniformMatrix4fv(SMS_ViewSpaceLoc, 1, GL_TRUE, &transformation.mat[0][0]);
	glUniform3fv(SMS_CameraPositionLoc, 1, POSITION);
	glUseProgram(0);
}
