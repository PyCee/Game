
#include "dataTypes.h"
#include "loadFiles.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void nulTerminate(U8 **str)
{
	U8 *past = *str;
	*str= malloc(sizeof(char) * (1 + strlen(*str)));
	strcpy(*str, past);
	*str[sizeof(*str) - sizeof(char)] = '\0';
	past = 0;
}
// take file and load it into c-string
U8 * readFile(const U8 * loc)
{
	U8 *fileSource;
	FILE *file;
	if ((file = fopen(loc, "r")) == NULL){
		printf("File not Found: %s\n", loc);
		return 0;
	}
	fseek(file,  0, SEEK_END);
	U32 fileLen = ftell(file);
	fseek(file,  0, SEEK_SET);
	fileSource = malloc(fileLen);
	fread(fileSource, fileLen, 1, file );
	fclose(file);
	file = 0;
	return fileSource;
}
U8 *readXMLElements(const U8 *source, const U8 *elementOpen)//, const U8 *elementClose)
{
	
	if(elementOpen[0] != '<' || elementOpen[strlen(elementOpen) - 1] != '>'){
		printf("\'%s\' is not a valid xml element", elementOpen);
		return;
	}
	U8 *elementClose = malloc(sizeof(char) * (strlen(elementOpen) + 2));
	elementClose[0] = '<';
	elementClose[1] = '/';
	U8 index;
	for(index = 1; index < strlen(elementOpen); index++){
		elementClose[index + 1] = elementOpen[index];
	}
	
	U8* startIndex = strstr(source, elementOpen) + (strlen(elementOpen) * sizeof(U8));
	U8* endIndex = strstr(source, elementClose);
	U8 *tmpSource = startIndex;
	U32 subStringLen = endIndex - startIndex;
	U8 *subString = malloc(subStringLen);
	while(tmpSource < endIndex){
		*subString = *tmpSource;
		subString += sizeof(U8);
		tmpSource += sizeof(U8);
	}
	*subString = '\0';
	startIndex = 0;
	endIndex = 0;
	tmpSource = 0;
	return subString - subStringLen;
}
