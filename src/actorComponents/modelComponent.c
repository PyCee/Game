
#include "modelComponent.h"
#include <stdlib.h>
#include "../actors.h"
#include "stdio.h"
#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags

static void countMeshes(struct aiNode *);
static void countIndices(struct aiMesh *);
static void processNode(struct aiNode *, const struct aiScene *);
Mesh *loadModelFromFile(const unsigned char *modelFileLoc)
{
	model[getActor()].directory = malloc(sizeof(modelFileLoc));
	strcpy(model[getActor()].directory, modelFileLoc);
	// TODO: replace all of the assimp stuff with own library
	//	2 parts:
		// 1. convert file into custom file type.
		// 2. import vertex info (positions, textures, normals)
		
		// later~
		// import animations
	const struct aiScene* scene = aiImportFile(modelFileLoc, //aiProcess_CalcTangentSpace       |
		aiProcess_Triangulate            | // Needed
		aiProcess_JoinIdenticalVertices  | // Needed
		aiProcess_GenNormals		 | // Needed
		//aiProcess_FlipUVs 		 |
		aiProcess_GenUVCoords		 | // Needed
		aiProcess_SortByPType);
	
	countMeshes(scene->mRootNode);
	model[getActor()].meshes = malloc(sizeof(Mesh) * model[getActor()].numMeshes);
	processNode(scene->mRootNode, scene);
}
void freeModelComponent(void)
{
	unsigned char index;
	for(index = 0; index < model[getActor()].numMeshes; index++)
		freeMesh(model[getActor()].meshes);
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
		processMesh(mesh, scene, index);
	}
	for(index = 0; index < node->mNumChildren; index++){
		processNode(node->mChildren[index], scene);
	}
}
