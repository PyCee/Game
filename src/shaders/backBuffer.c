#include "backBuffer.h"
#include <SDL2/SDL_opengl.h>
#include "shaders.h"
#include "shaderProgram.h"
#include "../actorComponents/model/vertex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

GLuint backBuffer, backBufferTexture, backBufferDepthStencil;

GLuint backBufferVAO, backBufferVBO, backBufferEBO;

GLfloat bufferPlane[4][4];
GLuint bufferPlaneIndicies[6];

void genBackBuffer(void)
{
	glGenFramebuffers(1, &backBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, backBuffer);
	
	glGenTextures(1, &backBufferTexture);
	glBindTexture(GL_TEXTURE_2D, backBufferTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1000, 650, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, backBufferTexture, 0);
	
	glGenRenderbuffers(1, &backBufferDepthStencil);
	glBindRenderbuffer(GL_RENDERBUFFER, backBufferDepthStencil); 
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1000, 650);  
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, backBufferDepthStencil);
	
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) printf("ERROR::backBuffer not complete.\n");
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
	char index;
	for(index = 0; index < 4; index++){
		int x = index / 2;
		int y = index % 2;
		bufferPlane[index][0] = x * 2 - 1;
		bufferPlane[index][1] = y * 2 - 1;
		bufferPlane[index][2] = x;
		bufferPlane[index][3] = y;
	}
	
	bufferPlaneIndicies[0] = 0;
	bufferPlaneIndicies[1] = 2;
	bufferPlaneIndicies[2] = 1;
	bufferPlaneIndicies[3] = 2;
	bufferPlaneIndicies[4] = 3;
	bufferPlaneIndicies[5] = 1;
	
	glGenVertexArrays(1, &backBufferVAO);
	glGenBuffers(1, &backBufferVBO);
	glGenBuffers(1, &backBufferEBO);
	
	glBindVertexArray(backBufferVAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, backBufferVBO);
	glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(GLfloat), bufferPlane, GL_STATIC_DRAW); 
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, backBufferEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLuint), bufferPlaneIndicies, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0 * sizeof(GLfloat));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 2 * sizeof(GLfloat));
	
	glBindVertexArray(0);
	 
}
void bringForthBackBuffer(void){//TODO: make this work
	printf("Working on the back buffer.\n");
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glUseProgram(*frameBufferShader->program);
	
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(FBS_TextureLoc, 0);
	glBindTexture(GL_TEXTURE_2D, backBufferTexture);
	
	glBindVertexArray(backBufferVAO);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
	glBindVertexArray(0);
	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	glUseProgram(0);
	glBindFramebuffer(GL_FRAMEBUFFER, backBuffer);
	
	printf("Done working on the back buffer.\n");
}
