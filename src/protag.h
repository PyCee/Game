
#ifndef _PROTAG_
#define _PROTAG_

#include <stdint.h>

#define PROTAG_NAME "PROTAG"
#define SPEED_FORWARD 0.0008
#define SPEED_LEFT 0.0008
#define SPEED_BACKWARD 0.0008
#define SPEED_RIGHT 0.0008

U8			genProtag									(void);
void		UpdateProtag							(U8, U16);
void		Jump											(void);

void		ControlledActorForward		(void);
void		ControlledActorLeft				(void);
void		ControlledActorBackward		(void);
void		ControlledActorRight			(void);

#endif
