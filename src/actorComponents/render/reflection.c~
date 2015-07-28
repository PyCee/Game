
#include "../../dataTypes.h"
#include "reflection.h"

#include "../lightingComponent.h"
#include "color.h"
#include <math.h>
#include "../physics/vector.h"
#include "../direction/normal.h"

void PhongReflection
(Color_t *reflectedLight, // pointer to answer container
Normal_t cameraNegation, Color_t ambiantLightIntensity,
Normal_t surfaceNormal, F32 ambianceReflectivity, F32 diffuseReflectivity, F32 specularReflectivity,
F32 specularGlossiness, Color_t *lightColorIntensity, Normal_t *lightNegation, U8 numLights)
{
	F32 reflectedLightColor = 0;
	U8 light = 0;
	reflectedLightColor = ambianceReflectivity * ambiantLightIntensity.Red;
	while (light < numLights)
	{
	/*
		F32 scaleSurfaceNormal = DotProduct(surfaceNormal, vertexToLight[light]) * 2;
		Vector_t reflectedVertexToLight = scaleVector(surfaceNormal, scaleSurfaceNormal) - vertexToLight[];
	
     				for (each light source){
     				
    F32 diffuseIntensity = diffuseReflectivity * DotProduct(surfaceNormal, vertexToLight[light]);
    F32 specularIntensity = specularReflectivity * 
    		pow(DotProduct(reflectedVertexToLight[light], vertexToCamera), surfaceSpecularGlossiness);
    
    reflectedLightColor += (diffuseIntensity + specularIntensity) * lightColorIntensity->Red;
     					
     				}
     				
     				
	*/
		light++;
	}
	// repeat for each color Red, Gre, Blu
}
