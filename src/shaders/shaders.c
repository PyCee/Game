
#include "../dataTypes.h"
#include "shaders.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// take file and load it into c-string
static U8 * loadShaderSource(const U8 * path)
{
	U8 * shaderSource;
	FILE *source;
	if ( (source = fopen( path, "r" ) ) == NULL )
		return 0;
	fseek( source,  0, SEEK_END );
	U32 length = ftell( source );
	fseek( source,  0, SEEK_SET );
	shaderSource = malloc( length );
	fread( shaderSource, length, 1, source );
	fclose( source );
	return shaderSource;
}
GLuint loadShaderFromFile( const U8 * path, GLenum shaderType )
{
	const GLchar * shaderSource[1];
	shaderSource[0] = loadShaderSource( path );
	GLuint length[1];
	GLuint result;

	FILE *source;
	if ( (source = fopen( path, "r" ) ) == NULL )
		return 0;
	fseek( source,  0, SEEK_END );
	length[0] = ftell( source );
	fseek( source,  0, SEEK_SET );
	fclose( source );
	
	
	GLuint shader = glCreateShader(shaderType);
	printf("shader Gened.\nshader Linking.\n");
	glShaderSource(shader, 1, shaderSource, length);
	printf("shader Linked.\nshader Compiling.\n");
	glCompileShader(shader);
	
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if ( !success ) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shader, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", shaderType, InfoLog);
	}

	return shader;
}
GLfloat sunasd[] =
{
	-0.2f, 0.9f, 0.0f,
	-0.2f, 0.7f, 0.0f,
	0.2f, 0.9f, 0.0f
};
void genShaders(void)
{
	
	shaderVertex = loadShaderFromFile(SHADER_VERT_PATH, GL_VERTEX_SHADER);
	shaderFragment = loadShaderFromFile(SHADER_FRAG_PATH, GL_FRAGMENT_SHADER);

	shaderProgram = glCreateProgram();
	printf("shaderProgram Gened.\nshaderProgram Attaching Shaders.\n");
	glAttachShader(shaderProgram, shaderVertex);
	glAttachShader(shaderProgram, shaderFragment);
	glLinkProgram(shaderProgram);
	
	GLint Success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0) {
		GLchar ErrorLog[1024];
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
	}
	
	glValidateProgram(shaderProgram);
	glUseProgram(shaderProgram);
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sunasd), sunasd, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	
}
void tmpDraw(void)
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);	
}
