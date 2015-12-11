
#ifndef _VECTOR_
#define _VECTOR_

typedef struct _vec3{
	float vec [3];
} vec3;
typedef struct _vec4{
	float vec [4];
} vec4;

vec3 	genVec3		( float, float, float);
vec4	genVec4(float, float, float, float);
vec3	addVec3		(vec3, vec3);
vec3	subtractVec3	(vec3, vec3);
vec3	scaleVec3	(vec3, float);
float	dotVec3		(vec3, vec3);
vec3	crossVec3	(vec3, vec3);

void	printVec3	(vec3);
void	setVec3X	(vec3 *, float);
void	setVec3Y	(vec3 *, float);
void	setVec3Z	(vec3 *, float);
float	getVec3X	(vec3);
float	getVec3Y	(vec3);
float	getVec3Z	(vec3);

#endif
