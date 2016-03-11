
#include "XML.h"
#include "loadFiles.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void freeXMLElement(XMLElement xml)
{
	free(xml.tag);
	free(xml.attribute);
	free(xml.children);
}
XMLElement readXMLElements(const unsigned char *source, const unsigned char *elementOpen)
{
	if(!elementOpen){
		printf("No elementOpen provided in \"readXMLElements\"\n");
		return;
	}
	unsigned char elementOpenLen = strlen(elementOpen);
	if(elementOpen[0] != '<' || elementOpen[elementOpenLen - 1] != '>'){
		printf("\'%s\' is not a valid xml element", elementOpen);
		return;
	}
	printf("source:\n{%s\n }\n", source);
	if(!strstr(source, elementOpen)){
		printf("\'%s\' is not an XML opening element present in the file.\n", elementOpen);
		return;
	}
	unsigned char *elementClose = malloc(elementOpenLen + 1);
	elementClose[0] = '<';
	elementClose[1] = '/';
	unsigned char index = 0;
	for(index = 1; index < (elementOpenLen + 1) ; index++){
		elementClose[index + 1] = elementOpen[index];
	}
	
	if(!strstr(source, elementClose)){
		printf("\'%s\' is not an XML closing element present in the file.\n%s", elementOpen, source);
		return;
	}
	
	unsigned char *startIndex = strstr(source, elementOpen) + elementOpenLen;
	unsigned char *endIndex = strstr(source, elementClose);
	
	unsigned int subStringLen = endIndex - startIndex;
	unsigned char *subString = malloc(subStringLen + 1);
	strncpy(subString, startIndex, subStringLen);
	subString[subStringLen] = '\0';
	
	XMLElement xml;
	xml.tag = malloc(elementOpenLen);
	xml.attribute = malloc(strlen("temp"));
	xml.children = malloc(subStringLen);
	
	//strncpy(xml.tag, elementOpen, elementOpenLen);
	for(index = 0; index < (elementOpenLen) ; index++){
		xml.tag[index] = elementOpen[index];
	}
	xml.tag[elementOpenLen] = '\0';
	//strncpy(xml.attribute, attribute, strlen(attribute));
	for(index = 0; index < subStringLen ; index++){
		xml.children[index] = subString[index];
	}
	xml.children[subStringLen] = '\0';
	//strncpy(xml.children, subString, subStringLen);
	return xml;
}
