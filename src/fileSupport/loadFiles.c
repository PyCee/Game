
#include "loadFiles.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void nulTerminate(unsigned char **str)
{
	unsigned char *past = *str;
	*str= malloc(sizeof(char) * (1 + strlen(*str)));
	strcpy(*str, past);
	*str[sizeof(*str) - sizeof(char)] = '\0';
	past = 0;
}
// take file and load it into c-string
unsigned char *readFile(const unsigned char * loc)
{
	unsigned char *fileSource;
	FILE *file;
	if ((file = fopen(loc, "r")) == NULL){
		printf("File not Found: %s\n", loc);
		return 0;
	}
	fseek(file,  0, SEEK_END);
	unsigned int fileLen = ftell(file);
	fseek(file,  0, SEEK_SET);
	fileSource = malloc(fileLen);
	fread(fileSource, fileLen, 1, file );
	fclose(file);
	file = 0;
	return fileSource;
}
