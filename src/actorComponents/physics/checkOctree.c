#include "checkOctree.h"
#include "octree.h"
#include "../physicsComponent.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../actorList.h"
#include "collisionTypes/collisionAABox.h"
#include "collisionController.h"

static octreeNode *checkChildOctree(octreeNode *);
static octreeNode *checkParentOctree(octreeNode *, unsigned char, unsigned char);
static int octreeChildrenActors(octreeNode *);
static octreeNode *checkOctreeParentExistence(octreeNode *, char);

octreeNode *checkOctree(octreeNode *oct)//TODO: test checkOctree
{
	unsigned char childTest = 1;
	if(CONTAINING_OCTREE_NODE->size < oct->size){
		if(containingAABoxAABox(*oct->octreeBox, *PHYSICS->AABB)){
			if(CONTAINING_OCTREE_NODE->size < oct->size / 2.0){
				if(oct->children == 0)
					genOctreeNodeChildren(oct);
				unsigned char index;
				for(index = 0; index < 8; index++)
					if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB)){
						removeActorListID(oct->actList, getActor());
						return checkChildOctree(&oct->children[index]);
					}
				if(octreeChildrenActors(oct) == 0)
					freeOctreeNodeChildren(oct);
			}
			addActorListID(oct->actList, getActor());
			return oct;
		}
	} else childTest = 0;
	removeActorListID(oct->actList, getActor());
	return checkOctreeParentExistence(oct, childTest);
}

// This function is used to have one less containingAABoxAABox per octree level, ommiting the first call in checkOctree
static octreeNode *checkChildOctree(octreeNode *oct)
{
	if(CONTAINING_OCTREE_NODE->size < oct->size / 2.0){
		if(oct->children == 0)
			genOctreeNodeChildren(oct);
		unsigned char index;
		for(index = 0; index < 8; index++)
			if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB))
				return checkChildOctree(&oct->children[index]);
		if(octreeChildrenActors(oct) == 0)
			freeOctreeNodeChildren(oct);
	}
	addActorListID(oct->actList, getActor());
	return oct;
}
static octreeNode *checkParentOctree(octreeNode *oct, unsigned char childIndex, unsigned char testChildren)
{
	unsigned char childTest = 1;
	if(CONTAINING_OCTREE_NODE->size < oct->size){
		if(containingAABoxAABox(*oct->octreeBox, *PHYSICS->AABB)){
			if(testChildren){
				if(oct->children == 0)
					genOctreeNodeChildren(oct);
				unsigned char index;
				for(index = 0; index < 8; index++){
					if(index == childIndex)
						continue;
					if(containingAABoxAABox(*oct->children[index].octreeBox, *PHYSICS->AABB))
						return checkChildOctree(&oct->children[index]);
				}
				if(octreeChildrenActors(oct) == 0)
					freeOctreeNodeChildren(oct);
			}
			addActorListID(oct->actList, getActor());
			return oct;
		}
	} else childTest = 0;
	return checkOctreeParentExistence(oct, childTest);
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
static octreeNode *checkOctreeParentExistence(octreeNode *oct, char childTest)
{
	if(oct->parent == 0){
		printf("ERROR::ACTOR %hhu NOT CONTAINED BY HIGHEST OCTREE\n", getActor());
		return oct;
	}
	return checkParentOctree(oct->parent, oct->isChildIndex, childTest);
}
