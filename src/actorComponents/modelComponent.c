
#include "modelComponent.h"
#include <stdlib.h>
#include "../actors.h"
#include "stdio.h"
#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags

static unsigned int meshNumber = 0;
static void countMeshes(struct aiNode *);
static void countIndices(struct aiMesh *);
static void processNode(struct aiNode *, const struct aiScene *);
static void processMesh(struct aiMesh *);
Mesh *loadModelFromFile(const unsigned char *modelFileLoc)
{
	  const struct aiScene* scene = aiImportFile(modelFileLoc, aiProcess_CalcTangentSpace       | 
		aiProcess_Triangulate            |
		aiProcess_JoinIdenticalVertices  |
		aiProcess_SortByPType);
	
	countMeshes(scene->mRootNode);
	model[getActor()].meshes = malloc(sizeof(Mesh) * model[getActor()].numMeshes);
	meshNumber = 0;
	processNode(scene->mRootNode, scene);
	meshNumber = 0;
}
void drawModel(void)
{
	GLuint index;
	for(index = 0; index < model[getActor()].numMeshes; index++){
		glBindVertexArray(model[getActor()].meshes[index].VAO);
		glDrawElements(GL_TRIANGLES, model[getActor()].meshes[index].numIndices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}
static void countMeshes(struct aiNode *node)
{
	model[getActor()].numMeshes += node->mNumMeshes;
	GLuint index = 0;
	for(index = 0; index < node->mNumChildren; index++){
		countMeshes(node->mChildren[index]);
	}
}
static void processNode(struct aiNode *node, const struct aiScene *scene)
{
	GLuint index = 0;
	for(index = 0; index < node->mNumMeshes; index++){
		struct aiMesh *mesh = scene->mMeshes[node->mMeshes[index]];
		processMesh(mesh);
		meshNumber++;
	}
	for(index = 0; index < node->mNumChildren; index++){
		processNode(node->mChildren[index], scene);
	}
}
static void processMesh(struct aiMesh *mesh)
{
	model[getActor()].meshes[meshNumber].numVertices = mesh->mNumVertices;
	model[getActor()].meshes[meshNumber].numIndices = mesh->mNumFaces * 3;
		
	model[getActor()].meshes[meshNumber].vertices = malloc(sizeof(Vertex) * model[getActor()].meshes[meshNumber].numVertices);
	model[getActor()].meshes[meshNumber].indices = malloc(sizeof(GLuint) * model[getActor()].meshes[meshNumber].numIndices);
	
	GLuint index;
	
	Vertex vert;
	printf("vertices: %d\n", mesh->mNumVertices);
	for(index = 0; index < mesh->mNumVertices; index++){
		vert.pos.vec[0] = mesh->mVertices[index].x;
		vert.pos.vec[1] = mesh->mVertices[index].y;
		vert.pos.vec[2] = mesh->mVertices[index].z;
		printVec3(vert.pos);
		vert.normal.vec[0] = mesh->mNormals[index].x;
		vert.normal.vec[1] = mesh->mNormals[index].y;
		vert.normal.vec[2] = mesh->mNormals[index].z;
		if(mesh->mTextureCoords[0]){
			vert.texCoords.vec[0] = mesh->mTextureCoords[0][index].x;
			vert.texCoords.vec[1] = mesh->mTextureCoords[0][index].y;
		}
		model[getActor()].meshes[meshNumber].vertices[index] = vert;
	}
	printf("mesh->mNumFaces: %d\n", mesh->mNumFaces);
	for(index = 0; index < mesh->mNumFaces; index++){
			struct aiFace face = mesh->mFaces[index];
			GLuint indiceIndex = 0;
			printf("indices on a face: %i\n", face.mNumIndices);
			for(indiceIndex = 0; indiceIndex < face.mNumIndices; indiceIndex++){
				model[getActor()].meshes[meshNumber].indices[(3 * index) + indiceIndex] = face.mIndices[indiceIndex];
			}	
	}
	printf(" ind %i\n", model[getActor()].meshes[meshNumber].numIndices);
	printf(" vert %i\n", model[getActor()].meshes[meshNumber].numVertices);
}
