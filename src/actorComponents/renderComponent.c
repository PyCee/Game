
#include "renderComponent.h"

#include "../actors.h"
#include "collisionsComponent.h"
#include <stdio.h>
#include "../shaders/shaders.h"
#include <math.h>
#include <SDL2/SDL_opengl.h>
#include <string.h>
#include <math.h>
#include "../math/matrix.h"
#include "../math/quaternion.h"
#include "physics/physicsAttributeController.h"
#include "directionComponent.h"
#include "modelComponent.h"
#include "physicsComponent.h"

#include "../shaders/shaders.h"
#define PImm 3.1415926535897932384
void initRender(void) {
	printf("Initializing Render.\n");
	genShaders();

	printf("Render Initialized.\n");
}
void genRenderComponent() {

	SHOULD_RENDER = 1;
}
void freeRenderComponent() {
}
void updateRenderComponent(unsigned short deltaMS) {
	// TODO: more culling
	if( SHOULD_RENDER == 0 ){ // I have chosen not to render this actor
		return;
	}// culling done, something is to be rendered
	
	static unsigned short tlm = 0;
	tlm += deltaMS/10;
	while (tlm > 360)
		tlm -= 360;
	if (WorldSpaceLoc != -1) {
		mat4 worldPlacement = genIdentityMat4();
		if (getActor() == getControlledActor()) {

			worldPlacement = QuaternionToRotationMatrix(UnitQuaternion(*FORWARD, 0));
			//printMat4(worldPlacement);
		}
		worldPlacement = translateMat4(worldPlacement, *POSITION);
		glUniformMatrix4fv(WorldSpaceLoc, 1, GL_TRUE,
				&worldPlacement.mat[0][0]);
	} else
		printf("ERROR::WorldPlacementLoc is Equal to -1\n");
	if (DRAW_BOUNDS){// && getActor() != getControlledActor()) {
		printf("Drawing Bounds for Actor %hhu\n", getActor());
		
		
		printf("Bounds Drawn for Actor %hhu\n", getActor());
		return;
	}
	// Draw model
	printf("Drawing Model for Actor %hhu\n", getActor());
	GLuint index;
	for(index = 0; index < NUM_MESHES; index++){
		//TODO: use textures
		
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(TextureLoc, 0);
		glBindTexture(GL_TEXTURE_2D, MESHES[index].textures[0].id);
		
		glBindVertexArray(MESHES[index].VAO);
		glDrawElements(GL_TRIANGLES, MESHES[index].numIndices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
	printf("Model Drawn for Actor %hhu\n", getActor());
	
	
}
