#ifndef _AI_COMPONENT_
#define _AI_COMPONENT_

typedef struct _AIComponent_t {
	void (*update)(U16);
} AIComponent_t;

void genAIComponent();
void freeAIComponent();
void updateAIComponent(U16);
void assignAIUpdate(void (*)(U16));
void UselessUpdate(U16);

#endif /* _AI_COMPONENT_ */
