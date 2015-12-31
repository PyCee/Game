
#include "mesh.h"
#include <stddef.h>
#include <stdio.h>

void setupMesh(Mesh *mesh)
{
	glGenVertexArrays(1, &(mesh->VAO));
	glGenBuffers(1, &(mesh->VBO));
	glGenBuffers(1, &(mesh->EBO));
	
	glBindVertexArray(mesh->VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	
	//TODO: test identifier.type (static or dynamic) for final parameter to glBufferData
	glBufferData(GL_ARRAY_BUFFER, mesh->numVertices * sizeof(Vertex), mesh->vertices, GL_DYNAMIC_DRAW); 
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->numIndices * sizeof(GLuint), mesh->indices, GL_STATIC_DRAW);
	
	// Vertex Positions
	glEnableVertexAttribArray(0);	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	// Vertex Normals
	glEnableVertexAttribArray(1);	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	// Vertex Texture Coords
	glEnableVertexAttribArray(2);	
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));
	
	glBindVertexArray(0);
}
