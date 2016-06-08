#ifndef OCTREE
#define OCTREE

struct vec3;
struct actorList;
//TODO: consider having some overlapping octreeNodes to allow for less calculations when an actor is inside multiple nodes.
//	if actor is completely contained in center, ignore the outer nodes
//	+12.5% octrees (+one per octree with children, in the center)
typedef struct octreeNode{
	struct octreeNode *children;
	struct octreeNode *parent;
	float size;
	struct collisionController *octreeBox;
	struct vec3 *placement;
	unsigned char isChildIndex;
	unsigned short octreeNodeID;
	struct actorList *actList;
	
} octreeNode;

extern unsigned short nextOctreeNodeID;
extern octreeNode globalOctree;

octreeNode genOctreeNode(void);
void freeOctreeNode(octreeNode *);
void genOctreeNodeChildren(octreeNode *);
void freeOctreeNodeChildren(octreeNode *);
void resetOctreeBox(octreeNode *);
unsigned char isOctreeParent(octreeNode *, octreeNode *);


#endif /* OCTREE */
