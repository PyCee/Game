#ifndef _AI_COMPONENT_
#define _AI_COMPONENT_

typedef struct _AIComponent_t {
	void (*update)(U8, U16);
} AIComponent_t;

void genAIComponent(U8);
void freeAIComponent(U8);
void updateAIComponent(U8, U16);
void assignAIUpdate(U8, void (*)(U8, U16));
void UselessUpdate(U8, U16);

#endif /* _AI_COMPONENT_ */
