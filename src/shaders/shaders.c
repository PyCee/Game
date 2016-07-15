
#include "shaders.h"
#include "../fileSupport/loadFiles.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../math/matrix.h"
#include <math.h>
#include "shaderProgram.h"
extern unsigned char IAMALIVE;

struct shaderProgram *frameBufferShader;
GLuint FBS_TextureLoc;

struct shaderProgram *standardModelShader;
GLuint SMS_WorldSpaceLoc;
GLuint SMS_ViewSpaceLoc;
GLuint SMS_ClipSpaceLoc;
GLuint SMS_CameraPositionLoc;
GLuint SMS_TextureLoc;
void genShaders(void)
{
	frameBufferShader = malloc(sizeof(shaderProgram));
	*frameBufferShader = genShaderProgramVertFrag(SHADER_BACKBUFFER_VERT_PATH, SHADER_BACKBUFFER_FRAG_PATH);
	
	glBindAttribLocation(*frameBufferShader->program, 0, "localPosition");
	glBindAttribLocation(*frameBufferShader->program, 1, "texCoords");
	glLinkProgram(*frameBufferShader->program);
	glValidateProgram(*frameBufferShader->program);
	
	FBS_TextureLoc = glGetUniformLocation(*frameBufferShader->program, "Texture");
	if(FBS_TextureLoc == -1) printf("ERROR::FBS_TextureLoc Not Found\n");
	
	
	standardModelShader = malloc(sizeof(shaderProgram));
	*standardModelShader = genShaderProgramVertFrag(SHADER_STANDARD_VERT_PATH, SHADER_STANDARD_FRAG_PATH);
	
	glBindAttribLocation(*standardModelShader->program, 0, "localPosition");
	glBindAttribLocation(*standardModelShader->program, 1, "normal");
	glBindAttribLocation(*standardModelShader->program, 2, "texCoords");
	glLinkProgram(*standardModelShader->program);
	glValidateProgram(*standardModelShader->program);
	
	SMS_WorldSpaceLoc = glGetUniformLocation(*standardModelShader->program, "worldSpace");
	if(SMS_WorldSpaceLoc == -1) printf("ERROR::FBS_WorldSpaceLoc Not Found\n");
	
	SMS_ViewSpaceLoc = glGetUniformLocation(*standardModelShader->program, "viewSpace");
	if(SMS_ViewSpaceLoc == -1) printf("ERROR::FBS_ViewSpaceLoc Not Found\n");
	
	SMS_ClipSpaceLoc = glGetUniformLocation(*standardModelShader->program, "clipSpace");
	if(SMS_ClipSpaceLoc == -1) printf("ERROR::FBS_ClipSpaceLoc Not Found\n");
	
	SMS_CameraPositionLoc = glGetUniformLocation(*standardModelShader->program, "cameraPosition");
	if(SMS_CameraPositionLoc == -1) printf("ERROR::SMS_CameraPositionLoc Not Found\n");
	
	SMS_TextureLoc = glGetUniformLocation(*standardModelShader->program, "Texture");
	if(SMS_TextureLoc == -1) printf("ERROR::SMS_TextureLoc Not Found\n");
	
	glUseProgram(0);
}

