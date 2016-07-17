
#include "renderComponent.h"

#include "../actors.h"
#include <stdio.h>
#include "../shaders/shader_program.h"
#include "../shaders/deferred_lighting.h"
#include "../shaders/backBuffer.h"
#include "../shaders/geometry.h"
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
#include "physics/collisionController.h"

void initRender(void)
{
	printf("Initializing Render.\n");
	genBackBuffer();
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	
	init_buffer_plane_buffers();
	init_buffer_plane_shaders();
	init_deferred_lighting_buffer();
	init_deferred_lighting_shader();
	init_geometry_buffer();
	init_geometry_shader();
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
//	Should be using grometry_shader
	if(SHOULD_RENDER == 0){
		return;
	}
	// TODO: more culling
	
//	Culling done. Render something.
	mat4 Translate = genIdentityMat4();
	Translate = translateMat4(Translate, *POSITION);
	mat4 Rotate = QuaternionToRotationMatrix(*FORWARDROTATION);
	mat4 transformation = mat4Product(Translate, Rotate);
	glUniformMatrix4fv(GS_world_space_loc, 1, GL_TRUE, &transformation.mat[0][0]);
	if (DRAW_BOUNDS){
//		printf("Drawing Bounds for Actor %hhu\n", getActor());
		// TODO: create system to draw outline of boxes.
//		printf("Bounds Drawn for Actor %hhu\n", getActor());
		return;
	}
//	printf("Drawing Model for Actor %hhu\n", getActor());
	GLuint index;
	for(index = 0; index < NUM_MESHES; index++){
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(GS_texture_map_loc, 0);
		glBindTexture(GL_TEXTURE_2D, MESHES[index].textures[0].id);
		
		glBindVertexArray(MESHES[index].VAO);
		glDrawElements(GL_TRIANGLES, MESHES[index].numIndices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
//	printf("Model Drawn for Actor %hhu\n", getActor());
}
