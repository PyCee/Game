#ifndef AI_COMPONENT
#define AI_COMPONENT

#define AI ai[getActor()]
#define AI_UPDATE AI->update
#define AI_STATE AI->AIState
#define AI_MOVE_TARGET AI->moveTarget
#define AI_CONTROLLED_MOVEMENT AI->controlledMovement

typedef struct AIComponent {
	void (*update)(unsigned short);
	struct vec3 *moveTarget, *controlledMovement;
	unsigned char AIState; // Value meanings defined per actor.
} AIComponent;

void genAIComponent();
void freeAIComponent();
void updateAIComponent(unsigned short);
void assignAIUpdate(void (*)(unsigned short));
void UselessUpdate(unsigned short);

#endif /* AI_COMPONENT */
