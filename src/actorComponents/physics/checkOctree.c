#include "checkOctree.h"
#include "octree.h"
#include "../physicsComponent.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../actorList.h"
#include "collisionTypes/collisionAABox.h"
#include "collisionController.h"

static octreeNode *checkChildOctree(octreeNode *);
static octreeNode *checkParentOctree(octreeNode *, unsigned char);
static int octreeChildrenActors(octreeNode *);

octreeNode *checkOctree(octreeNode *oct)//TODO: test checkOctree
{
	printf("ooo1\n");
	unsigned char index;
	if(containingAABoxAABox(*oct->octreeBox, *PHYSICS->AABB)){
		printf("ooo1.1\n");
		if(oct->children == 0)
			genOctreeNodeChildren(oct);
		printf("ooo1.2\n");
		for(index = 0; index < 8; index++)
			if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB)){
				removeActorListID(oct->actList, getActor());
				return checkChildOctree(&oct->children[index]);
			}
		printf("ooo1.3\n");
			
		//see if children need to destroyed.  Check actor list of each. if no actors, delete children.
		if(octreeChildrenActors(oct) == 0){
			for(index = 0; index < 8; index++){
				freeOctreeNode(&oct->children[index]);
			}
			oct->children = 0;
		}
		printf("ooo1.4\n");
		addActorListID(oct->actList, getActor());
		return oct;
	}
	printf("ooo2\n");
	removeActorListID(oct->actList, getActor());
	printf("ooo2.1\n");
	if(oct->parent == 0){
		printf("ooo2.2\n");
		printf("ERROR::ACTOR %hhu NOT CONTAINED BY HIGHEST OCTREE\n", getActor());
		return oct;
	}
	printf("ooo3\n");
	return checkParentOctree(oct->parent, oct->isChildIndex);
}

// This function is used to have one less containingAABoxAABox per octree level, ommiting the first call in checkOctree
static octreeNode *checkChildOctree(octreeNode *oct)
{
	unsigned char index;
	if(oct->children == 0)
		genOctreeNodeChildren(oct);
	for(index = 0; index < 8; index++)
		if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB)){
			return checkChildOctree(&oct->children[index]);
		}
	addActorListID(oct->actList, getActor());
	return oct;
}
static octreeNode *checkParentOctree(octreeNode *oct, unsigned char childIndex)
{
	printf("ooo4\n");
	unsigned char index;
	if(containingAABoxAABox(*oct->octreeBox, *PHYSICS->AABB)){
		printf("ooo4.1\n");
		if(oct->children == 0)
			genOctreeNodeChildren(oct);
		printf("ooo4.2\n");
		for(index = 0; index < 8; index++){
			if(index == childIndex)
				continue;
			if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB)){
				return checkChildOctree(&oct->children[index]);
			}
		}
		printf("ooo4.3\n");
		if(octreeChildrenActors(oct) == 0){
			for(index = 0; index < 8; index++){
				freeOctreeNode(&oct->children[index]);
			}
			free(oct->children);
			oct->children = 0;
		}
		printf("ooo4.4\n");
		addActorListID(oct->actList, getActor());
		return oct;
	}
	printf("ooo5\n");
	if(oct->parent == 0){
		printf("ERROR::ACTOR %hhu NOT CONTAINED BY HIGHEST OCTREE\n", getActor());
		return oct;
	}
	return checkOctree(oct->parent);
}
static int octreeChildrenActors(octreeNode *oct)
{
	unsigned char index;
	if(oct->children == 0)
		return oct->actList->numActors;
	int numChildren = 0;
	for(index = 0; index < 8; index++){
		numChildren += octreeChildrenActors(&oct->children[index]);
	}
	return numChildren;
}
