
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
void genRenderComponent (U8 actorID)
{
	Actors.render[actorID].render = 1;
	
	Actors.render[actorID].BoundingBoxVerticies[0] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[1] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[2] = getWidth(actorID) * -1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[3] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[4] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[5] = getWidth(actorID) * -1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[6] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[7] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[8] = getWidth(actorID) * -1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[9] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[10] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[11] = getWidth(actorID) * -1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[12] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[13] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[14] = getWidth(actorID) * 1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[15] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[16] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[17] = getWidth(actorID) * 1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[18] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[19] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[20] = getWidth(actorID) * 1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[21] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[22] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[23] = getWidth(actorID) * 1 * 0.5;
	
	glGenBuffers(1, &(Actors.render[actorID].BoundingBoxVBO));
	glBindBuffer(GL_ARRAY_BUFFER, Actors.render[actorID].BoundingBoxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Actors.render[actorID].BoundingBoxVerticies), Actors.render[actorID].BoundingBoxVerticies, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void freeRenderComponent (U8 actorID)
{
}
void updateRenderComponent (U8 actorID, U16 deltaMS)
{
	// TODO: more culling
	/*if ( Actors.render[actorID].render == 0 ) // we have chosen not to render this actor
		return;
	
	if (ActorRotateVectorLoc != -1) {
		vec3 cameraOrient = cross( k, Actors.direction[actorID].forward );
		glUniform3f( ActorRotateVectorLoc, cameraOrient.vec[0], cameraOrient.vec[1], cameraOrient.vec[2] );
	}
	if (ActorRotateAngleLoc != -1) {
		glUniform1f( ActorRotateAngleLoc, acos( dot( Actors.direction[actorID].forward, k ) ) );
	}
	*/
	// culling done, something is to be rendered
	if (WorldPlacementLoc != -1) {
		mat4 worldPlacement = genIdentityMat4();
		worldPlacement = translateMat4(worldPlacement, genVec3(getPosX(actorID), getPosY(actorID), getPosZ(actorID)));
		if(actorID == getControlledActor()){
		
			worldPlacement = QuaternionToRotationMatrix(UnitQuaternion(k, 45));
			worldPlacement = translateMat4(worldPlacement, genVec3(getPosX(actorID), getPosY(actorID), getPosZ(actorID)));
			//printMat4(worldPlacement);
		}
		//printf("now printing worldplacement mat4\n");
		//printMat4(worldPlacement);
		glUniformMatrix4fv(WorldPlacementLoc, 1, GL_TRUE, &worldPlacement.mat[0][0]);
	} else
		printf("ERROR::WorldPlacementLoc is Equal to -1\n");
	if ( Actors.collisions[actorID].drawBounds ) {//&& actorID == getControlledActor()) {
		//PrintVec3(Actors.physics[actorID].Pos);
		
		glBindBuffer(GL_ARRAY_BUFFER, Actors.render[actorID].BoundingBoxVBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BoundingBoxIBO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
		glDisableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		
		return;
	}
	// Draw model
	
}
