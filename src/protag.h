

#ifndef _PROTAG_
#define _PROTAG_

#include <stdint.h>

#define SPEED_FORWARD 0.0008
#define SPEED_LEFT 0.0008
#define SPEED_BACKWARD 0.0008
#define SPEED_RIGHT 0.0008
typedef struct _Actor_t Actor_t;

void genProtag(Actor_t **);
void freeProtag(Actor_t **);
void UpdateProtag(Actor_t *, uint64_t);
void Jump(void);

void ControlledActorForward(void);
void ControlledActorLeft(void);
void ControlledActorBackward(void);
void ControlledActorRight(void);

#endif
