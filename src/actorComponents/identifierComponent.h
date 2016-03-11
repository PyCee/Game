#ifndef _IDENTIFIER_COMPONENT_
#define _IDENTIFIER_COMPONENT_

typedef struct _IdentifierComponent {
	unsigned char *name;
	unsigned char *type;
	unsigned char *file;
} IdentifierComponent;

void genIdentifierComponent();
void freeIdentifierComponent();

#endif /* _IDENTIFIER_COMPONENT_ */
