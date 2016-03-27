
#ifndef _PROTAG_
#define _PROTAG_

#include <stdint.h>

#define SPEED_FORWARD 0.0008
#define SPEED_LEFT 0.0008
#define SPEED_BACKWARD 0.0008
#define SPEED_RIGHT 0.0008

void UpdateProtag(unsigned short);
void Jump(void);

void ControlledActorForward(void);
void UnControlledActorForward(void);
void ControlledActorLeft(void);
void UnControlledActorLeft(void);
void ControlledActorBackward(void);
void UnControlledActorBackward(void);
void ControlledActorRight(void);
void UnControlledActorRight(void);

#endif
