
#include "reflection.h"

#include "../lightingComponent.h"
#include "color.h"
#include <math.h>
#include "../physics/vertex.h"
#include "../physics/vector.h"
#include "../direction/normal.h"
#include "../../actorSelection.h"
#include "../lightingComponent.h"
#include "../../actors.h"

// TODO: test any and every aspect.

// Calculate reflected light at specific vertex.
void PhongReflection(Color_t * reflectedLight, Vertex_t vertex, unsigned char light[MAX_ACTOR_COUNT][MAX_LIGHT_COUNT], float specularGlossiness)
{
	/*unsigned char actorID = 0;
	unsigned char lightID = 0;
	Normal_t *vertexToCamera = subtractVectors( direction[getCameraView()].forward, vertex.surfaceNormal );
	Normal_t vertexToLight[MAX_ACTOR_COUNT][MAX_LIGHT_COUNT];
	while ( actorID < MAX_ACTOR_COUNT ) {
		while ( lightID < MAX_LIGHT_COUNT ) {
			if ( !light[actorID][lightID] )
				continue;
			vertexToLight[actorID][lightID].point[0] = vertex.Pos[0] - lighting[actorID].originatingPoint[lightID]->Pos[0];
			vertexToLight[actorID][lightID].point[1] = vertex.Pos[1] - lighting[actorID].originatingPoint[lightID]->Pos[1];
			vertexToLight[actorID][lightID].point[2] = vertex.Pos[2] - lighting[actorID].originatingPoint[lightID]->Pos[2];
			NormalizeNormal( &vertexToLight[actorID][lightID] );
			lightID++;
		}
		actorID++;
	}
	actorID = 0;
	lightID = 0;
	reflectedLight->Red = vertex.ambiantReflectivity * AmbiantLight.Red;
	reflectedLight->Green = vertex.ambiantReflectivity * AmbiantLight.Green;
	reflectedLight->Blue = vertex.ambiantReflectivity * AmbiantLight.Blue;
	while ( actorID < MAX_ACTOR_COUNT ) {
		while (lightID < MAX_LIGHT_COUNT) {
			if ( !light[actorID][lightID] )
				continue;
			F32 scaleSurfaceNormal = DotProduct(vertex.surfaceNormal, vertexToLight[actorID][lightID]) * 2;
			Vector_t reflectedVertexToLight = *subtractVectors( 
				*scaleVector( vertex.surfaceNormal, scaleSurfaceNormal ),
				vertexToLight[actorID][lightID] );
			
  	   					
			F32 diffuseIntensity = vertex.diffuseReflectivity * DotProduct(vertex.surfaceNormal, vertexToLight[actorID][lightID]);
			F32 specularIntensity = vertex.specularReflectivity * 
			pow(DotProduct(reflectedVertexToLight, *vertexToCamera), specularGlossiness);
			
	  		reflectedLight->Red += (diffuseIntensity + specularIntensity) * lighting[actorID].intensity[lightID].Red;
	  		reflectedLight->Green += (diffuseIntensity + specularIntensity) * lighting[actorID].intensity[lightID].Green;
	  		reflectedLight->Blue += (diffuseIntensity + specularIntensity) * lighting[actorID].intensity[lightID].Blue;
     			
			lightID++;	
     		}
		actorID++;
	}*/
}
