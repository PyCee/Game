
#include "shaders.h"
#include "../fileSupport/loadFiles.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../math/matrix.h"
#include <math.h>
extern unsigned char IAMALIVE;
void genShaders(void)
{
	printf("Loading Vertex Shader.\n");
	shaderVertex = loadShaderFromFile(SHADER_VERT_PATH, GL_VERTEX_SHADER);
	printf("Vertex Shader Loaded.\nLoading Fragment Shader.\n");
	shaderFragment = loadShaderFromFile(SHADER_FRAG_PATH, GL_FRAGMENT_SHADER);
	printf("Vertex Shader Loaded.\n");

	shaderProgram = glCreateProgram();
	printf("shaderProgram Gened.\nshaderProgram Attaching Shaders.\n");
	glAttachShader(shaderProgram, shaderVertex);
	glAttachShader(shaderProgram, shaderFragment);
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glBindAttribLocation(shaderProgram, 0, "localPosition");
	glBindAttribLocation(shaderProgram, 1, "normal");
	glBindAttribLocation(shaderProgram, 2, "texCoords");

	printf("shaderProgram Shaders Attached.\nLinking shaderProgram.\n");
	glLinkProgram(shaderProgram);
	printf("Linked shaderProgram.\n");
	
	GLint Success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0) {
		GLchar ErrorLog[1024];
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "ERROR::linking shader program: '%s'\n", ErrorLog);
		printf("Setting\n");
		IAMALIVE = 0;
	}
	
	glValidateProgram(shaderProgram);
	glUseProgram(shaderProgram);
	
	TextureLoc = glGetUniformLocation(shaderProgram, "Texture");
	if (TextureLoc == -1) {
		printf("ERROR::TextureLoc Not Found\n");
	}
	WorldSpaceLoc = glGetUniformLocation(shaderProgram, "worldSpace");
	if (WorldSpaceLoc == -1) {
		printf("ERROR::WorldSpaceLoc Not Found\n");
	}
	ViewSpaceLoc = glGetUniformLocation(shaderProgram, "viewSpace");
	if (ViewSpaceLoc == -1) {
		printf("ERROR::ViewSpaceLoc Not Found\n");
	}
	ClipSpaceLoc = glGetUniformLocation(shaderProgram, "clipSpace");
	if (ClipSpaceLoc == -1) {
		printf("ERROR::ClipSpaceLoc Not Found\n");
	}
	CameraPositionLoc = glGetUniformLocation(shaderProgram, "cameraPosition");
	if (TextureLoc == -1) {
		printf("ERROR::CameraPositionLoc Not Found\n");
	}
	
	
	glEnable(GL_CULL_FACE); // enables face culling    
	glCullFace(GL_BACK); // tells OpenGL to cull back faces (the sane default setting)
	glFrontFace(GL_CCW); // tells OpenGL which faces are considered 'front' (use GL_CW or GL_CCW)
}
GLuint loadShaderFromFile( const unsigned char * path, GLenum shaderType )
{
	const GLchar * shaderSource[1];
	unsigned char *fileSource = readFile(path);
	shaderSource[0] = fileSource;
	GLuint length[1];
	GLuint result;

	FILE *source;
	if ((source = fopen(path, "r")) == NULL)
		return 0;
	fseek(source, 0, SEEK_END);
	length[0] = ftell(source);
	fseek(source, 0, SEEK_SET);
	fclose(source);
	
	GLuint shader = glCreateShader(shaderType);
	printf("shader Gened.\nshader Linking.\n");
	glShaderSource(shader, 1, shaderSource, length);
	printf("shader Linked.\nshader Compiling.\n");
	glCompileShader(shader);
	
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shader, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", shaderType, InfoLog);
		
		IAMALIVE = 0; // Ends game so error may be fixed.
	}
	free(fileSource);
	return shader;
}
