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
	unsigned char index;
	if(containingAABoxAABox(*oct->octreeBox, *PHYSICS->AABB)){
		if(oct->children == 0)
			genOctreeNodeChildren(oct);
		for(index = 0; index < 8; index++)
			if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB)){
				removeActorListID(oct->actList, getActor());
				return checkChildOctree(&oct->children[index]);
			}
		if(octreeChildrenActors(oct) == 0)
			freeOctreeNodeChildren(oct);
		addActorListID(oct->actList, getActor());
		return oct;
	}
	removeActorListID(oct->actList, getActor());
	if(oct->parent == 0){
		printf("ERROR::ACTOR %hhu NOT CONTAINED BY HIGHEST OCTREE\n", getActor());
		return oct;
	}
	return checkParentOctree(oct->parent, oct->isChildIndex);
}

// This function is used to have one less containingAABoxAABox per octree level, ommiting the first call in checkOctree
static octreeNode *checkChildOctree(octreeNode *oct)
{
	unsigned char index;
	if(oct->children == 0)
		genOctreeNodeChildren(oct);
	for(index = 0; index < 8; index++)
		if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB))
			return checkChildOctree(&oct->children[index]);
	if(octreeChildrenActors(oct) == 0)
		freeOctreeNodeChildren(oct);
	addActorListID(oct->actList, getActor());
	return oct;
}
static octreeNode *checkParentOctree(octreeNode *oct, unsigned char childIndex)
{
	unsigned char index;
	if(containingAABoxAABox(*oct->octreeBox, *PHYSICS->AABB)){
		if(oct->children == 0)
			genOctreeNodeChildren(oct);
		for(index = 0; index < 8; index++){
			if(index == childIndex)
				continue;
			if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB))
				return checkChildOctree(&oct->children[index]);
		}
		if(octreeChildrenActors(oct) == 0)
			freeOctreeNodeChildren(oct);
		addActorListID(oct->actList, getActor());
		return oct;
	}
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
