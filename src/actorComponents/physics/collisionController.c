#include "collisionController.h"

#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

collisionController genCollisionController(void)
{
	collisionController con;
	con._vec3 = 0;
	con._float = 0;
	return con;
}
void freeCollisionController(collisionController *con)
{
	if(con->_vec3)
		free(con->_vec3);
	con->_vec3 = 0;
	if(con->_float)
		free(con->_float);
	con->_float = 0;
	
}
void collisionControllerElement(collisionController *con, void *poi, unsigned char num, unsigned char type)
{
	unsigned char index;
	switch(type){
		case COLLISION_VEC3:
			con->numVec3 = num;
			con->_vec3 = malloc(sizeof(vec3 *) * num);
			memset(con->_vec3, 0, sizeof(con->_vec3));
			for(index = 0; index < num; index++)
				con->_vec3[index] = *(vec3 **)(poi + sizeof(vec3 *) * index);
			break;
		case COLLISION_FLOAT:
			con->numFloat = num;
			con->_float = malloc(sizeof(float) * num);
			memset(con->_float, 0, sizeof(con->_float));
			for(index = 0; index < num; index++)
				con->_float[index] = *(float *)(poi + sizeof(float) * index);
			break;
		default:
			break;
	}
}
