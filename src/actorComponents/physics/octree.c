#include "octree.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include "collisionTypes/collisionAABox.h"
#include "collisionController.h"
#include "../../actorList.h"

unsigned short nextOctreeNodeID;
octreeNode globalOctree;

static octreeNode genOctreeNodeChild(octreeNode *, unsigned char);
static unsigned short addOctreeNode(void);

octreeNode genOctreeNode(void)
{
	octreeNode oct;
	oct.children = 0;
	oct.size = 1;
	oct.isChildIndex = 0;
	oct.parent = 0;
	oct.placement = malloc(sizeof(vec3));
	*oct.placement = genVec3(0.0, 0.0, 0.0);
	oct.octreeBox = malloc(sizeof(collisionController));
	resetOctreeBox(&oct);
	oct.octreeNodeID = addOctreeNode();
	oct.actList = malloc(sizeof(actorList));
	*oct.actList = genActorList();
	return oct;
}
void freeOctreeNode(octreeNode *oct)
{
	unsigned char index;
	if(oct->children){
		for(index = 0; index < 8; index++)
			freeOctreeNode(&oct->children[index]);
		free(oct->children);
	}
	if(oct->placement)
		free(oct->placement);
}
void genOctreeNodeChildren(octreeNode *par)
{
	par->children = malloc(sizeof(octreeNode) * 8);
	unsigned char index;
	for(index = 0; index < 8; index++){
		par->children[index] = genOctreeNodeChild(par, index);
	}
}
void resetOctreeBox(octreeNode *oct)
{
	*oct->octreeBox = genCollisionAABox(oct->placement, oct->size / 2, oct->size / 2, oct->size / 2);
}
static octreeNode genOctreeNodeChild(octreeNode *oct, unsigned char index)
{
	octreeNode child;
	child = genOctreeNode();
	child.parent = oct;
	child.isChildIndex = index;
	child.size = oct->size / 2;
	unsigned char lower = index % 4;
	*child.placement = addVec3Vec3(*oct->placement, scaleVec3(genVec3(lower >= 2, index >= 4, lower && lower != 3), child.size));
	*child.octreeBox = genCollisionAABox(child.placement, child.size / 2, child.size / 2, child.size / 2);
	return child;
}
static unsigned short addOctreeNode(void)
{
	unsigned short next = nextOctreeNodeID++;
	return next;
}
