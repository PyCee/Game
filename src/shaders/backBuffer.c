#include "backBuffer.h"
#include <SDL2/SDL_opengl.h>
#include "shader_program.h"
#include "../actorComponents/model/vertex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer_plane.h"
#include "deferred_lighting.h"

GLuint backBuffer, backBufferTexture, backBufferDepthStencil;

GLuint buffer_plane_vao, buffer_plane_vbo, buffer_plane_ebo;


void genBackBuffer(void)
{
	glGenFramebuffers(1, &backBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, backBuffer);
	
	glGenTextures(1, &backBufferTexture);
	glBindTexture(GL_TEXTURE_2D, backBufferTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1000, 650, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);//TODO get screen size from options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, backBufferTexture, 0);
	
	glGenRenderbuffers(1, &backBufferDepthStencil);
	glBindRenderbuffer(GL_RENDERBUFFER, backBufferDepthStencil); 
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1000, 650);//TODO get screen size from options
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, backBufferDepthStencil);
	
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) printf("ERROR::backBuffer not complete.\n");
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
void bringForthBackBuffer(void)
{
	printf("Working on the back buffer.\n");
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glUseProgram(*buffer_plane_shader->program);
	
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(BPS_texture_loc, 0);
	glBindTexture(GL_TEXTURE_2D, backBufferTexture);
	
	draw_buffer_plane();
	
	glUseProgram(0);
	glBindFramebuffer(GL_FRAMEBUFFER, backBuffer);
	
	printf("Done working on the back buffer.\n");
}
