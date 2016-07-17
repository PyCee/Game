#include "geometry.h"
#include <SDL2/SDL_opengl.h>
#include "shader_program.h"
#include "buffer_plane.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int geometry_buffer, geometry_buffer_position_map,
		geometry_buffer_normal_map, geometry_buffer_color_specularity_map, geometry_buffer_depth_stencil;

struct shader_program *geometry_shader;
unsigned int GS_world_space_loc, GS_view_space_loc, GS_clip_space_loc, GS_texture_map_loc;

void init_geometry_buffer(void)
{
	glGenFramebuffers(1, &geometry_buffer);
	glBindFramebuffer(GL_FRAMEBUFFER, geometry_buffer);
	
	glGenTextures(1, &geometry_buffer_position_map);
	glBindTexture(GL_TEXTURE_2D, geometry_buffer_position_map);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, 1000, 650, 0, GL_RGB, GL_FLOAT, NULL);//TODO get screen size from options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glGenTextures(1, &geometry_buffer_normal_map);
	glBindTexture(GL_TEXTURE_2D, geometry_buffer_normal_map);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, 1000, 650, 0, GL_RGB, GL_FLOAT, NULL);//TODO get screen size from options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glGenTextures(1, &geometry_buffer_color_specularity_map);
	glBindTexture(GL_TEXTURE_2D, geometry_buffer_color_specularity_map);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1000, 650, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);//TODO get screen size from options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glGenRenderbuffers(1, &geometry_buffer_depth_stencil);
	glBindRenderbuffer(GL_RENDERBUFFER, geometry_buffer_depth_stencil); 
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1000, 650);//TODO get screen size from options
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, geometry_buffer_depth_stencil);
	
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, geometry_buffer_position_map, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, geometry_buffer_normal_map, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, geometry_buffer_color_specularity_map, 0);
	
	GLuint attachments[3] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2};
	glDrawBuffers(3, attachments);
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) printf("\nERROR::geometry_buffer incomplete.\n\n");
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
void init_geometry_shader(void)
{
	geometry_shader = malloc(sizeof(shader_program));
	*geometry_shader = gen_shader_program_vert_frag(SHADER_GEOMETRY_VERTEX_PATH, SHADER_GEOMETRY_FRAGMENT_PATH);
	glBindAttribLocation(*geometry_shader->program, 0, "position");
	glBindAttribLocation(*geometry_shader->program, 1, "normal");
	glBindAttribLocation(*geometry_shader->program, 2, "uv_coords");
	glBindFragDataLocation(*geometry_shader->program, 0, "geometry_buffer_position_map");
	glBindFragDataLocation(*geometry_shader->program, 1, "geometry_buffer_normal_map");
	glBindFragDataLocation(*geometry_shader->program, 2, "geometry_buffer_color_specularity_map");
	glLinkProgram(*geometry_shader->program);
	glValidateProgram(*geometry_shader->program);

	GS_world_space_loc = glGetUniformLocation(*geometry_shader->program, "world_space");
	if(GS_world_space_loc == -1) printf("ERROR::GS_world_space_loc Not Found\n");
	GS_view_space_loc = glGetUniformLocation(*geometry_shader->program, "view_space");
	if(GS_view_space_loc == -1) printf("ERROR::GS_view_space_loc Not Found\n");
	GS_clip_space_loc = glGetUniformLocation(*geometry_shader->program, "clip_space");
	if(GS_clip_space_loc == -1) printf("ERROR::GS_clip_space_loc Not Found\n");
	GS_texture_map_loc = glGetUniformLocation(*geometry_shader->program, "texture_map");
	if(GS_texture_map_loc == -1) printf("ERROR::GS_texture_map_loc Not Found\n");
	
	glUseProgram(*geometry_shader->program);
	glUniform1i(GS_texture_map_loc, 0);
	glUseProgram(0);
}
