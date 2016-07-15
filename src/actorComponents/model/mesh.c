
#include "mesh.h"
#include "../../actors.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SOIL/SOIL.h"
#include "../modelComponent.h"

void setupMesh(Mesh *mesh)
{
	glGenVertexArrays(1, &(mesh->VAO));
	glGenBuffers(1, &(mesh->VBO));
	glGenBuffers(1, &(mesh->EBO));
	
	glBindVertexArray(mesh->VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	
	glBufferData(GL_ARRAY_BUFFER, mesh->numVertices * sizeof(vertex), mesh->vertices, GL_STATIC_DRAW); 
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->numIndices * sizeof(GLuint), mesh->indices, GL_STATIC_DRAW);
	
	// Vertex Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0 * sizeof(float));
	// Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 3 * sizeof(float));
	// Vertex Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), 6 * sizeof(float));
	
	glBindVertexArray(0);
}
void freeMesh(Mesh *mesh)
{
	if(mesh->vertices)
		free(mesh->vertices);
	if(mesh->indices)
		free(mesh->indices);
	if(mesh->textures)
		free(mesh->textures);
}
void processMesh(struct aiMesh *mesh, const struct aiScene *scene, unsigned int activeMesh)
{
	MESHES[activeMesh].numVertices = mesh->mNumVertices;
	MESHES[activeMesh].numIndices = mesh->mNumFaces * 3;
	MESHES[activeMesh].numTextures = 1;//mesh->mNumTextures;//TODO
		
	MESHES[activeMesh].vertices = malloc(sizeof(vertex) * MESHES[activeMesh].numVertices);
	MESHES[activeMesh].indices = malloc(sizeof(GLuint) * MESHES[activeMesh].numIndices);
	MESHES[activeMesh].textures = malloc(sizeof(Texture) * MESHES[activeMesh].numTextures);
	
	GLuint index;
	
	vertex vert;
	for(index = 0; index < mesh->mNumVertices; index++){
		vert.attribute[0] = mesh->mVertices[index].x;
		vert.attribute[1] = mesh->mVertices[index].y;
		vert.attribute[2] = mesh->mVertices[index].z;
		vert.attribute[3] = mesh->mNormals[index].x;
		vert.attribute[4] = mesh->mNormals[index].y;
		vert.attribute[5] = mesh->mNormals[index].z;
		if(mesh->mTextureCoords[0]){
			vert.attribute[6] = mesh->mTextureCoords[0][index].x;
			vert.attribute[7] = mesh->mTextureCoords[0][index].y;
		}
		MESHES[activeMesh].vertices[index] = vert;
	}
	
	for(index = 0; index < mesh->mNumFaces; index++){
			struct aiFace face = mesh->mFaces[index];
			GLuint indiceIndex = 0;
			for(indiceIndex = 0; indiceIndex < face.mNumIndices; indiceIndex++){
				MESHES[activeMesh].indices[(3 * index) + indiceIndex] = face.mIndices[indiceIndex];
			}	
	}
	Texture *texture = &(MESHES[activeMesh].textures[0]);
	struct aiString textureString;
	aiGetMaterialString(scene->mMaterials[mesh->mMaterialIndex], AI_MATKEY_TEXTURE(aiTextureType_DIFFUSE, 0), &textureString);
	texture->path = malloc(sizeof(textureString.data));
	strcpy(texture->path, textureString.data);
//	printf("Texture Filename = %s\n", texture->path);
	
	texture->id = SOIL_load_OGL_texture(texture->path, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, texture->id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}
