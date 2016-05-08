
#ifndef _MODEL_COMPONENT_
#define _MODEL_COMPONENT_

#include "model/mesh.h"
#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags

#define MESHES model[getActor()]->meshes
#define NUM_MESHES model[getActor()]->numMeshes
#define MODEL_PATH model[getActor()]->modelPath

typedef struct ModelComponent {
	Mesh *meshes;
	unsigned int numMeshes;
	unsigned char *modelPath;
} ModelComponent;

Mesh *loadModelFromFile(const unsigned char *);
void freeModelComponent(void);

#endif /* _MODEL_COMPONENT_ */
