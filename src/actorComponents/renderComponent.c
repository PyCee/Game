
#include "renderComponent.h"

#include "../actors.h"
#include <stdio.h>
#include "../shaders/shaders.h"
#include <math.h>
#include <SDL2/SDL_opengl.h>
#include <string.h>
#include <math.h>
#include "../math/matrix.h"
#include "../math/quaternion.h"
#include "physics/physicsAttributeController.h"
#include "physics/vector.h"
#include "directionComponent.h"
#include "modelComponent.h"
#include "physicsComponent.h"

#include "../shaders/shaders.h"
#define PImm 3.1415926535897932384
void initRender(void)
{
	printf("Initializing Render.\n");
	genShaders();

	printf("Render Initialized.\n");
}
void genRenderComponent()
{
	SHOULD_RENDER = 1;
}
void freeRenderComponent()
{
}
void updateRenderComponent(unsigned short deltaMS)
{
	// TODO: more culling
	if(SHOULD_RENDER == 0){
		return;
	}// culling done, something is to be rendered
	
	if (WorldSpaceLoc != -1) {
		mat4 Translate = genIdentityMat4();
		Translate = translateMat4(Translate, *POSITION);
		mat4 Rotate = QuaternionToRotationMatrix(*FORWARDROTATION);
		mat4 transformation = mat4Product(Translate, Rotate);
		glUniformMatrix4fv(WorldSpaceLoc, 1, GL_TRUE, &transformation.mat[0][0]);
	} else
		printf("ERROR::WorldPlacementLoc is Equal to -1\n");
	if (DRAW_BOUNDS){// && getActor() != getControlledActor()) {
//		printf("Drawing Bounds for Actor %hhu\n", getActor());
		
		
//		printf("Bounds Drawn for Actor %hhu\n", getActor());
		return;
	}
//	printf("Drawing Model for Actor %hhu\n", getActor());
	GLuint index;
	for(index = 0; index < NUM_MESHES; index++){
		//TODO: use textures (correctly)
		
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(TextureLoc, 0);
		glBindTexture(GL_TEXTURE_2D, MESHES[index].textures[0].id);
		
		glBindVertexArray(MESHES[index].VAO);
		glDrawElements(GL_TRIANGLES, MESHES[index].numIndices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
//	printf("Model Drawn for Actor %hhu\n", getActor());
}
