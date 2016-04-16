#ifndef _AI_COMPONENT_
#define _AI_COMPONENT_

typedef struct AIComponent {
	void (*update)(unsigned short);
} AIComponent;

void genAIComponent();
void freeAIComponent();
void updateAIComponent(unsigned short);
void assignAIUpdate(void (*)(unsigned short));
void UselessUpdate(unsigned short);

#endif /* _AI_COMPONENT_ */
