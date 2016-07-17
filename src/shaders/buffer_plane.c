#include "buffer_plane.h"
#include <SDL2/SDL_opengl.h>
#include "shader_program.h"
#include <stdio.h>
#include <stdlib.h>

struct shader_program *buffer_plane_shader;
unsigned int BPS_texture_map_loc;

unsigned int buffer_plane_vao, buffer_plane_vbo, buffer_plane_ebo;

GLfloat buffer_plane[4][4];
GLushort buffer_plane_indicies[6];
void init_buffer_plane_buffer(void)
{
	
	char index;
	for(index = 0; index < 4; index++){
		int x = index / 2;
		int y = index % 2;
		buffer_plane[index][0] = x * 2 - 1;
		buffer_plane[index][1] = y * 2 - 1;
		buffer_plane[index][2] = x;
		buffer_plane[index][3] = y;
	}
	
	buffer_plane_indicies[0] = 0;
	buffer_plane_indicies[1] = 2;
	buffer_plane_indicies[2] = 1;
	buffer_plane_indicies[3] = 2;
	buffer_plane_indicies[4] = 3;
	buffer_plane_indicies[5] = 1;
	
	glGenVertexArrays(1, &buffer_plane_vao);
	glGenBuffers(1, &buffer_plane_vbo);
	glGenBuffers(1, &buffer_plane_ebo);
	
	glBindVertexArray(buffer_plane_vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, buffer_plane_vbo);
	glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(GLfloat), buffer_plane, GL_STATIC_DRAW); 
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_plane_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLushort), buffer_plane_indicies, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0 * sizeof(GLfloat));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 2 * sizeof(GLfloat));
	
	glBindVertexArray(0);
}
void init_buffer_plane_shader(void)
{
	buffer_plane_shader = malloc(sizeof(shader_program));
	*buffer_plane_shader = gen_shader_program_vert_frag(SHADER_BUFFER_PLANE_VERTEX_PATH, SHADER_BUFFER_PLANE_FRAGMENT_PATH);
	
	glBindAttribLocation(*buffer_plane_shader->program, 0, "localPosition");
	glBindAttribLocation(*buffer_plane_shader->program, 1, "texCoords");
	glLinkProgram(*buffer_plane_shader->program);
	glValidateProgram(*buffer_plane_shader->program);
	
	BPS_texture_map_loc = glGetUniformLocation(*buffer_plane_shader->program, "texture_map");
	if(BPS_texture_map_loc == -1) printf("ERROR::BPS_texture_map_loc of buffer_plane_shader Not Found\n");
	
	glUseProgram(*buffer_plane_shader->program);
	glUniform1i(BPS_texture_map_loc, 0);
	glUseProgram(0);
	
}
void draw_buffer_plane(void)
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	
	glBindVertexArray(buffer_plane_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}
