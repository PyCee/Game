#include "deferred_lighting.h"
#include <SDL2/SDL_opengl.h>
#include "shader_program.h"
#include "buffer_plane.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int deferred_lighting_buffer, deferred_lighting_texture, deferred_lighting_depth_stencil;

struct shader_program *deferred_lighting_shader;
unsigned int DLS_deferred_lighting_position_map_loc, DLS_deferred_lighting_normal_map_loc,
			DLS_deferred_lighting_color_specularity_map_loc, DLS_camera_position_loc;

void init_deferred_lighting_buffer(void)
{
	glGenFramebuffers(1, &deferred_lighting_buffer);
	glBindFramebuffer(GL_FRAMEBUFFER, deferred_lighting_buffer);
	
	glGenTextures(1, &deferred_lighting_texture);
	glBindTexture(GL_TEXTURE_2D, deferred_lighting_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1000, 650, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);//TODO get screen size from options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glGenRenderbuffers(1, &deferred_lighting_depth_stencil);
	glBindRenderbuffer(GL_RENDERBUFFER, deferred_lighting_depth_stencil); 
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1000, 650);//TODO get screen size from options
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, deferred_lighting_depth_stencil);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, deferred_lighting_texture, 0);
	
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) printf("\nERROR::deferred_lighting_buffer not complete.\n\n");
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
}
void init_deferred_lighting_shader(void)
{
	deferred_lighting_shader = malloc(sizeof(shader_program));
	*deferred_lighting_shader = gen_shader_program_vert_frag(SHADER_BUFFER_PLANE_VERTEX_PATH, SHADER_DEFERRED_LIGHTING_FRAGMENT_PATH);
	glBindAttribLocation(*deferred_lighting_shader->program, 0, "position");
	glBindAttribLocation(*deferred_lighting_shader->program, 1, "uv_coords");
	glLinkProgram(*deferred_lighting_shader->program);
	glValidateProgram(*deferred_lighting_shader->program);

	DLS_deferred_lighting_position_map_loc = glGetUniformLocation(*deferred_lighting_shader->program, "deferred_lighting_position_map");
	if(DLS_deferred_lighting_position_map_loc == -1) printf("ERROR::DLS_deferred_lighting_position_map_loc Not Found\n");
	DLS_deferred_lighting_normal_map_loc = glGetUniformLocation(*deferred_lighting_shader->program, "deferred_lighting_normal_map");
	if(DLS_deferred_lighting_normal_map_loc == -1) printf("ERROR::DLS_deferred_lighting_normal_map_loc Not Found\n");
	DLS_deferred_lighting_color_specularity_map_loc = glGetUniformLocation(*deferred_lighting_shader->program, "deferred_lighting_color_specularity_map");
	if(DLS_deferred_lighting_color_specularity_map_loc == -1) printf("ERROR::DLS_deferred_lighting_color_specularity_map_loc Not Found\n");
	DLS_camera_position_loc = glGetUniformLocation(*deferred_lighting_shader->program, "camera_position");
	if(DLS_camera_position_loc == -1) printf("ERROR::DLS_camera_position_loc Not Found\n");
	glUseProgram(0);
}
