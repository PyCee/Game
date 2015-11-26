#ifndef _IDENTIFIER_COMPONENT_
#define _IDENTIFIER_COMPONENT_

#define UNDEFINED_NAME "UNDEFINED_NAME"

typedef struct _IdentifierComponent_t {
	U8 * ActorName;
} IdentifierComponent_t;

void genIdentifierComponent();
void freeIdentifierComponent();

#endif /* _IDENTIFIER_COMPONENT_ */
