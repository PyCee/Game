#ifndef AI_COMPONENT
#define AI_COMPONENT

#define AI ai[getActor()]
#define AI_UPDATE AI->update

typedef struct AIComponent {
	void (*update)(unsigned short);
} AIComponent;

void genAIComponent();
void freeAIComponent();
void updateAIComponent(unsigned short);
void assignAIUpdate(void (*)(unsigned short));
void UselessUpdate(unsigned short);

#endif /* _AI_COMPONENT_ */
