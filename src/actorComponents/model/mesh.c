
#include "mesh.h"
#include "../../actors.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SOIL/SOIL.h"
#include "../modelComponent.h"

void setupMesh(Mesh *mesh)
{
	printf("error?0\n");
	glGenVertexArrays(1, &(mesh->VAO));
	glGenBuffers(1, &(mesh->VBO));
	glGenBuffers(1, &(mesh->EBO));
	
	glBindVertexArray(mesh->VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	
	glBufferData(GL_ARRAY_BUFFER, mesh->numVertices * sizeof(Vertex), mesh->vertices, GL_STATIC_DRAW); 
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->numIndices * sizeof(GLuint), mesh->indices, GL_STATIC_DRAW);
	
	// Vertex Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 * sizeof(float));
	// Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 3 * sizeof(float));
	// Vertex Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 6 * sizeof(float));
	
	glBindVertexArray(0);
	printf("error?0\n");
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
		
	MESHES[activeMesh].vertices = malloc(sizeof(Vertex) * MESHES[activeMesh].numVertices);
	MESHES[activeMesh].indices = malloc(sizeof(GLuint) * MESHES[activeMesh].numIndices);
	MESHES[activeMesh].textures = malloc(sizeof(Texture) * MESHES[activeMesh].numTextures);
	
	GLuint index;
	printf("error?0\n");
	
	Vertex vert;
	for(index = 0; index < mesh->mNumVertices; index++){
		vert.attribute[0] = mesh->mVertices[index].x;
		vert.attribute[1] = mesh->mVertices[index].y;
		vert.attribute[2] = mesh->mVertices[index].z;
		vert.attribute[3] = mesh->mNormals[index].x;
		vert.attribute[4] = mesh->mNormals[index].y;
		vert.attribute[5] = mesh->mNormals[index].z;
		//if(PythagoreanTheorum(vert.attribute[3], vert.attribute[4], vert.attribute[5]) == 0)
		//	printf("normal has zero length\n");
		if(mesh->mTextureCoords[0]){
			vert.attribute[6] = mesh->mTextureCoords[0][index].x;
			vert.attribute[7] = mesh->mTextureCoords[0][index].y;
//			printf("[%f, %f]\n", vert.attribute[6], vert.attribute[7]);
		}
		MESHES[activeMesh].vertices[index] = vert;
	}
	
	printf("error?0.5\n");
	for(index = 0; index < mesh->mNumFaces; index++){
			struct aiFace face = mesh->mFaces[index];
			GLuint indiceIndex = 0;
			for(indiceIndex = 0; indiceIndex < face.mNumIndices; indiceIndex++){
				MESHES[activeMesh].indices[(3 * index) + indiceIndex] = face.mIndices[indiceIndex];
			}	
	}
	printf("error?1\n");
	Texture *texture = &(MESHES[activeMesh].textures[0]);
	struct aiString textureString;
	aiGetMaterialString(scene->mMaterials[mesh->mMaterialIndex], AI_MATKEY_TEXTURE(aiTextureType_DIFFUSE, 0), &textureString);
	texture->path = malloc(sizeof(textureString.data));
	strcpy(texture->path, textureString.data);
	printf("texture = %s\n", texture->path);
	printf("error?2\n");
	
	texture->id = SOIL_load_OGL_texture(texture->path, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, texture->id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// Generate mipmaps, by the way.
	glGenerateMipmap(GL_TEXTURE_2D);
	printf("error?3\n");


	glBindTexture(GL_TEXTURE_2D, 0);
	
	/*if(mesh->mMaterialIndex >= 0){//TODO
		struct aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		for(index = 0; index < aiGetMaterialTextureCount(material, aiTextureType_DIFFUSE); index++)
		{
			struct aiString str;
			aiGetMaterialString(material, AI_MATKEY_TEXTURE(aiTextureType_DIFFUSE, index), &str);
			
			unsigned char *path = malloc(strlen(model[getActor()].dir) + sizeof(&str));
			strcat(path, &(str.data));
			strcat(path, model[getActor()].dir);
			//SOIL-code below
			//texture.id = loadImageFrom(path)
			
			Texture *texture = model[getActor()].meshes[activeMesh].textures[index];
			glGenTextures(1, &(texture->id));
			glBindTexture(GL_TEXTURE_2D, texture->id);
			// Set the texture wrapping/filtering options (on the currently bound texture object)
			// Load and generate the texture
			int width, height;
			unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB); 
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);
			//TODO: lookup system around 'aiGetMaterialString' 'TEXTURE(t, n)
			
			texture->type = malloc(sizeof("texture_diffuse"));
			ctrcpy(texture->type, "texture_diffuse");
			texture->path = str;
		}
		/*
		vector<Texture> diffuseMaps = this->loadMaterialTextures(material, 
						aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		vector<Texture> specularMaps = this->loadMaterialTextures(material, 
						aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		
	} */
}
