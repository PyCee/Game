#ifndef _IDENTIFIER_COMPONENT_
#define _IDENTIFIER_COMPONENT

#define NAME identifier[getActor()].name
#define TYPE identifier[getActor()].type
#define ORIGIN_FILE identifier[getActor()].originFile

typedef struct IdentifierComponent {
	unsigned char *name;
	unsigned char *type;
	unsigned char *originFile;
} IdentifierComponent;

void genIdentifierComponent();
void freeIdentifierComponent();

#endif /* _IDENTIFIER_COMPONENT_ */
