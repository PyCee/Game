
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

#include "../shaders/shaders.h"
#define PImm 3.1415926535897932384
void initRender(void) {
	printf("Initializing Render.\n");
	genShaders();
	BoundingBoxIndices[0] = 0; // Front
	BoundingBoxIndices[1] = 1;
	BoundingBoxIndices[2] = 2;
	BoundingBoxIndices[3] = 0;
	BoundingBoxIndices[4] = 2;
	BoundingBoxIndices[5] = 3;
	BoundingBoxIndices[6] = 0; // Left
	BoundingBoxIndices[7] = 3;
	BoundingBoxIndices[8] = 7;
	BoundingBoxIndices[9] = 0;
	BoundingBoxIndices[10] = 7;
	BoundingBoxIndices[11] = 4;
	BoundingBoxIndices[12] = 0; // Down
	BoundingBoxIndices[13] = 5;
	BoundingBoxIndices[14] = 1;
	BoundingBoxIndices[15] = 0;
	BoundingBoxIndices[16] = 4;
	BoundingBoxIndices[17] = 5;
	BoundingBoxIndices[18] = 6; // Top
	BoundingBoxIndices[19] = 7;
	BoundingBoxIndices[20] = 3;
	BoundingBoxIndices[21] = 6;
	BoundingBoxIndices[22] = 3;
	BoundingBoxIndices[23] = 2;
	BoundingBoxIndices[24] = 6; // Right
	BoundingBoxIndices[25] = 2;
	BoundingBoxIndices[26] = 1;
	BoundingBoxIndices[27] = 6;
	BoundingBoxIndices[28] = 1;
	BoundingBoxIndices[29] = 5;
	BoundingBoxIndices[30] = 6; // Back
	BoundingBoxIndices[31] = 4;
	BoundingBoxIndices[32] = 7;
	BoundingBoxIndices[33] = 6;
	BoundingBoxIndices[34] = 5;
	BoundingBoxIndices[35] = 4;
	glGenBuffers(1, &BoundingBoxIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BoundingBoxIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(BoundingBoxIndices),
			BoundingBoxIndices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	printf("Render Initialized.\n");
}
void genRenderComponent() {

	render[getActor()].render = 1;

	render[getActor()].BoundingBoxVerticies[0] = getWidth() * -1 * 0.5;
	render[getActor()].BoundingBoxVerticies[1] = 0.0;
	render[getActor()].BoundingBoxVerticies[2] = getWidth() * -1 * 0.5;

	render[getActor()].BoundingBoxVerticies[3] = getWidth() * 1 * 0.5;
	render[getActor()].BoundingBoxVerticies[4] = 0.0;
	render[getActor()].BoundingBoxVerticies[5] = getWidth() * -1 * 0.5;

	render[getActor()].BoundingBoxVerticies[6] = getWidth() * 1 * 0.5;
	render[getActor()].BoundingBoxVerticies[7] = getHeight();
	render[getActor()].BoundingBoxVerticies[8] = getWidth() * -1 * 0.5;

	render[getActor()].BoundingBoxVerticies[9] = getWidth() * -1 * 0.5;
	render[getActor()].BoundingBoxVerticies[10] = getHeight();
	render[getActor()].BoundingBoxVerticies[11] = getWidth() * -1 * 0.5;

	render[getActor()].BoundingBoxVerticies[12] = getWidth() * -1 * 0.5;
	render[getActor()].BoundingBoxVerticies[13] = 0.0;
	render[getActor()].BoundingBoxVerticies[14] = getWidth() * 1 * 0.5;

	render[getActor()].BoundingBoxVerticies[15] = getWidth() * 1 * 0.5;
	render[getActor()].BoundingBoxVerticies[16] = 0.0;
	render[getActor()].BoundingBoxVerticies[17] = getWidth() * 1 * 0.5;

	render[getActor()].BoundingBoxVerticies[18] = getWidth() * 1 * 0.5;
	render[getActor()].BoundingBoxVerticies[19] = getHeight();
	render[getActor()].BoundingBoxVerticies[20] = getWidth() * 1 * 0.5;

	render[getActor()].BoundingBoxVerticies[21] = getWidth() * -1 * 0.5;
	render[getActor()].BoundingBoxVerticies[22] = getHeight();
	render[getActor()].BoundingBoxVerticies[23] = getWidth() * 1 * 0.5;
	
	glGenBuffers(1, &(render[getActor()].BoundingBoxVBO));
	glBindBuffer(GL_ARRAY_BUFFER, render[getActor()].BoundingBoxVBO);
	glBufferData(GL_ARRAY_BUFFER,
			sizeof(render[getActor()].BoundingBoxVerticies),
			render[getActor()].BoundingBoxVerticies, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void freeRenderComponent() {
}
void updateRenderComponent(unsigned short deltaMS) {
	// TODO: more culling
	if( render[getActor()].render == 0 ){ // we have chosen not to render this actor
		return;
	}// culling done, something is to be rendered
	
	static unsigned short tlm = 0;
	tlm += deltaMS/10;
	while (tlm > 360)
		tlm -= 360;
	if (WorldSpaceLoc != -1) {
		mat4 worldPlacement = genIdentityMat4();
		if (getActor() == getControlledActor()) {

			worldPlacement = QuaternionToRotationMatrix(UnitQuaternion(direction[getActor()].forward, 0));
			//printMat4(worldPlacement);
		}
		worldPlacement = translateMat4(worldPlacement,
					physics[getActor()].Pos);
		glUniformMatrix4fv(WorldSpaceLoc, 1, GL_TRUE,
				&worldPlacement.mat[0][0]);
	} else
		printf("ERROR::WorldPlacementLoc is Equal to -1\n");
	if (collisions[getActor()].drawBounds){// && getActor() != getControlledActor()) {
		printf("Drawing Bounds for Actor %hhu\n", getActor());
		
		glBindBuffer(GL_ARRAY_BUFFER, render[getActor()].BoundingBoxVBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BoundingBoxIBO);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		
		printf("Bounds Drawn for Actor %hhu\n", getActor());
		return;
	}
	// Draw model
	printf("Drawing Model for Actor %hhu\n", getActor());
	GLuint index;
	for(index = 0; index < model[getActor()].numMeshes; index++){
		//TODO: use textures
		
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(TextureLoc, 0);
		glBindTexture(GL_TEXTURE_2D, model[getActor()].meshes[index].textures[0].id);
		
		glBindVertexArray(model[getActor()].meshes[index].VAO);
		glDrawElements(GL_TRIANGLES, model[getActor()].meshes[index].numIndices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
	printf("Model Drawn for Actor %hhu\n", getActor());
	
	
}
