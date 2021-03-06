
#ifndef _VECTOR_
#define _VECTOR_

typedef struct _vec2 {
	float vec[2];
} vec2;
typedef struct vec3 {
	float vec[3];
} vec3;
typedef struct vec4 {
	float vec[4];
} vec4;

vec2 genVec2(float, float);
vec3 genVec3(float, float, float);
vec4 genVec4(float, float, float, float);

float magnitudeVec3Sq(vec3);
vec3 normalizeVec3(vec3);
vec3 addVec3Vec3(vec3, vec3);
vec3 subtractVec3Vec3(vec3, vec3);
unsigned char cmpVec3Vec3(vec3, vec3);
vec3 scaleVec3(vec3, double);
float dotProduct(vec3, vec3);
vec3 crossProduct(vec3, vec3);

void printVec3(vec3);
void printVec4(vec4);

float leastDistPointLineSq(vec3, vec3, vec3);
float leastDistLineLineSq(vec3, vec3, vec3, vec3);
float closestPointLinePoint(vec3, vec3, vec3);
float *closestPointsLineLine(vec3, vec3, vec3, vec3);

#endif /* _VECTOR_ */
