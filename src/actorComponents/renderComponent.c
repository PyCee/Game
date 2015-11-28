
#include "../dataTypes.h"
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
void initRender ( void )
{
	printf("Initializing Render.\n");
	genShaders();
	BoundingBoxIndices[0] = 0;// Front
	BoundingBoxIndices[1] = 1;
	BoundingBoxIndices[2] = 2;
	BoundingBoxIndices[3] = 0;
	BoundingBoxIndices[4] = 2;
	BoundingBoxIndices[5] = 3;
	BoundingBoxIndices[6] = 0;// Left
	BoundingBoxIndices[7] = 3;
	BoundingBoxIndices[8] = 7;
	BoundingBoxIndices[9] = 0;
	BoundingBoxIndices[10] = 7;
	BoundingBoxIndices[11] = 4;
	BoundingBoxIndices[12] = 0;// Down
	BoundingBoxIndices[13] = 1;
	BoundingBoxIndices[14] = 5;
	BoundingBoxIndices[15] = 0;
	BoundingBoxIndices[16] = 5;
	BoundingBoxIndices[17] = 4;
	BoundingBoxIndices[18] = 6;// Top
	BoundingBoxIndices[19] = 7;
	BoundingBoxIndices[20] = 3;
	BoundingBoxIndices[21] = 6;
	BoundingBoxIndices[22] = 3;
	BoundingBoxIndices[23] = 2;
	BoundingBoxIndices[24] = 6;// Right
	BoundingBoxIndices[25] = 2;
	BoundingBoxIndices[26] = 1;
	BoundingBoxIndices[27] = 6;
	BoundingBoxIndices[28] = 1;
	BoundingBoxIndices[29] = 5;
	BoundingBoxIndices[30] = 6;// Back
	BoundingBoxIndices[31] = 7;
	BoundingBoxIndices[32] = 4;
	BoundingBoxIndices[33] = 6;
	BoundingBoxIndices[34] = 4;
	BoundingBoxIndices[35] = 5;
	glGenBuffers(1, &BoundingBoxIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BoundingBoxIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(BoundingBoxIndices), BoundingBoxIndices, GL_STATIC_DRAW); 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	
	ActorPlacementLoc = glGetUniformLocation( shaderProgram, "actorPlacement" );
	if (ActorWorldPositionLoc == -1) {
		printf("ERROR::actorPlacementLoc Not Found\n");
	}
	WorldPlacementLoc = glGetUniformLocation( shaderProgram, "worldPlacement" );
	if (ActorWorldPositionLoc == -1) {
		printf("ERROR::worldPlacementLoc Not Found\n");
	}
	CameraPlacementLoc = glGetUniformLocation( shaderProgram, "cameraPlacement" );
	if (ActorWorldPositionLoc == -1) {
		printf("ERROR::cameraPlacementLoc Not Found\n");
	}
	
	
	glEnable(GL_CULL_FACE); // enables face culling    
	glCullFace(GL_BACK); // tells OpenGL to cull back faces (the sane default setting)
	glFrontFace(GL_CCW); // tells OpenGL which faces are considered 'front' (use GL_CW or GL_CCW)
	printf("Render Initialized.\n");
}
void genRenderComponent()
{
	Actors.render[getActor()].render = 1;
	
	Actors.render[getActor()].BoundingBoxVerticies[0] = getWidth() * -1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[1] = 0.0;
	Actors.render[getActor()].BoundingBoxVerticies[2] = getWidth() * -1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[3] = getWidth() * 1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[4] = 0.0;
	Actors.render[getActor()].BoundingBoxVerticies[5] = getWidth() * -1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[6] = getWidth() * 1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[7] = getHeight();
	Actors.render[getActor()].BoundingBoxVerticies[8] = getWidth() * -1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[9] = getWidth() * -1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[10] = getHeight();
	Actors.render[getActor()].BoundingBoxVerticies[11] = getWidth() * -1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[12] = getWidth() * -1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[13] = 0.0;
	Actors.render[getActor()].BoundingBoxVerticies[14] = getWidth() * 1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[15] = getWidth() * 1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[16] = 0.0;
	Actors.render[getActor()].BoundingBoxVerticies[17] = getWidth() * 1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[18] = getWidth() * 1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[19] = getHeight();
	Actors.render[getActor()].BoundingBoxVerticies[20] = getWidth() * 1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[21] = getWidth() * -1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[22] = getHeight();
	Actors.render[getActor()].BoundingBoxVerticies[23] = getWidth() * 1 * 0.5;
	
	glGenBuffers(1, &(Actors.render[getActor()].BoundingBoxVBO));
	glBindBuffer(GL_ARRAY_BUFFER, Actors.render[getActor()].BoundingBoxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Actors.render[getActor()].BoundingBoxVerticies), Actors.render[getActor()].BoundingBoxVerticies, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void freeRenderComponent()
{
}
void updateRenderComponent(U16 deltaMS)
{
	// TODO: more culling
	/*if ( Actors.render[getActor()].render == 0 ) // we have chosen not to render this actor
		return;
	
	if (ActorRotateVectorLoc != -1) {
		vec3 cameraOrient = cross( k, Actors.direction[getActor()].forward );
		glUniform3f( ActorRotateVectorLoc, cameraOrient.vec[0], cameraOrient.vec[1], cameraOrient.vec[2] );
	}
	if (ActorRotateAngleLoc != -1) {
		glUniform1f( ActorRotateAngleLoc, acos( dot( Actors.direction[getActor()].forward, k ) ) );
	}
	*/
	// culling done, something is to be rendered
	if (WorldPlacementLoc != -1) {
		mat4 worldPlacement = genIdentityMat4();
		worldPlacement = translateMat4(worldPlacement, Actors.physics[getActor()].Pos);
		if(getActor() == getControlledActor()){
		
			worldPlacement = QuaternionToRotationMatrix(UnitQuaternion(j, 0));
			worldPlacement = translateMat4(worldPlacement, Actors.physics[getActor()].Pos);
			//printMat4(worldPlacement);
		}
		//printf("now printing worldplacement mat4\n");
		//printMat4(worldPlacement);
		glUniformMatrix4fv(WorldPlacementLoc, 1, GL_TRUE, &worldPlacement.mat[0][0]);
	} else
		printf("ERROR::WorldPlacementLoc is Equal to -1\n");
	if ( Actors.collisions[getActor()].drawBounds ) {//&& getActor() == getControlledActor()) {
		//printVec3(Actors.physics[getActor()].Pos);
		
		glBindBuffer(GL_ARRAY_BUFFER, Actors.render[getActor()].BoundingBoxVBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BoundingBoxIBO);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		
		return;
	}
	// Draw model
	
}
