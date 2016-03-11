
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
	model[getActor()].dir = malloc(sizeof(modelFileLoc));
	strcpy(model[getActor()].dir, modelFileLoc);
	const struct aiScene* scene = aiImportFile(modelFileLoc, aiProcess_CalcTangentSpace       | 
		aiProcess_FlipWindingOrder	 |
		aiProcess_Triangulate            |
		aiProcess_JoinIdenticalVertices  |
		aiProcess_GenNormals		 |
		//aiProcess_FlipUVs 		 |
		aiProcess_SortByPType);
	
	countMeshes(scene->mRootNode);
	model[getActor()].meshes = malloc(sizeof(Mesh) * model[getActor()].numMeshes);
	processNode(scene->mRootNode, scene);
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
