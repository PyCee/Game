
#include "draw.h"
#include <stdio.h>
GLfloat sunasd[] =
{
	-0.2f, 0.9f, 0.0f,
	-0.2f, 0.7f, 0.0f,
	//0.2f, 0.7f, 0.0f,
	0.2f, 0.9f, 0.0f
};
void drawInit()
{
	
	printf("Starting Draw Initialization.\nshaderVertex Initializing.\nshaderVertex Gening.\n");
	
	
	char *shaderSourceVertex = SHADER_VERT_PATH;
	char *shaderSourceFragment = SHADER_FRAG_PATH;
	
	shaderVertex = glCreateShader(GL_VERTEX_SHADER);
	printf("shaderVertex Gened.\nshaderVertex Linking.\n");
	glShaderSource(shaderVertex, 1, &shaderSourceVertex, NULL);
	printf("shaderVertex Linked.\nshaderVertex Compiling.\n");
	glCompileShader(shaderVertex);
	printf("shaderVertex Compiled.\nshaderVertex Initialized.\nshaderFragment Initialilzing.\nshaderFragment Gening.\n");
	
	shaderFragment = glCreateShader(GL_FRAGMENT_SHADER);
	printf("shaderFragment Gened.\nshaderFragment Linking.\n");
	glShaderSource(shaderFragment, 1, &shaderSourceFragment, NULL);
	printf("shaderFragment Linked.\nshaderFragment Compiling.\n");
	glCompileShader(shaderFragment);
	printf("shaderFragment Compiled.\nshaderFragment Initialized.\nshaderProgram Initializing.\nshaderProgram Gening.\n");
	
	shaderProgram = glCreateProgram();
	printf("shaderProgram Gened.\nshaderProgram Attaching Shaders.\n");
	glAttachShader(shaderProgram, shaderVertex);
	glAttachShader(shaderProgram, shaderFragment);
	glLinkProgram(shaderProgram);
	
	printf("shaderProgram Shaders Attached.\nshaderProgram Shaders Deleting.\n");
	glDeleteShader(shaderVertex);
	glDeleteShader(shaderFragment);
	
	glUseProgram(shaderProgram);
	printf("shaderProgram Shaders Deleted\nshaderProgram Initialized.\nVBO Gening.\n");
	glGenBuffers(1, &VBO);
	printf("VBO Gened.\nVAO Gening.\n");
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(sunasd), sunasd, GL_STATIC_DRAW);
		
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	
	printf("VAO Gened.\n");
	
	printf("Draw Initialization Ended.\n");
	
	
	GLint success;
	GLchar infoLog[512];
	FILE *hsd;
	if((hsd = fopen(SHADER_VERT_PATH, "a")) == 0)
	{
		fprintf(hsd, "lllio");
		printf("asdasd\nasdasd\nasdasd\nadsasdno good path vertex sh.");
	}
	glGetShaderiv(shaderVertex, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		GLint logLength;
		glGetShaderiv(shaderVertex, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength > 0) {
		GLchar * log = malloc(logLength);
		glGetShaderInfoLog(shaderVertex, logLength, &logLength, log);
		fprintf(stderr, "Shader compile log:\n%s\n", log);
		free(log);
    //glGetShaderInfoLog(shaderVertex, 512, NULL, infoLog);
    //printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED %s\n", infoLog);
    }
	}
	glGetShaderiv(shaderFragment, GL_COMPILE_STATUS, &success);
	if(!success)
	{
    glGetShaderInfoLog(shaderFragment, 512, NULL, infoLog);
    printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED %s\n", infoLog);
	}
}
void draw()
{
	/*printf("Draw Starting.\n");
	
	glUseProgram(shaderProgram);
	printf("program used\n");
	glBindVertexArray(VAO);
	printf("drawing array\n");
	printf("%d ho\n", glGetError());
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	printf("array drawn\n");
	glBindVertexArray(0);
	printf("unbound array\n");
	*/
	
}
void drawDel()
{
}
