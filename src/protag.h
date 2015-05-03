

#ifndef _PROTAG_
#define _PROTAG_

typedef struct _Actor_t Actor_t;
#include <stdint.h>

void genProtag(Actor_t **);
void freeProtag(Actor_t **);
void UpdateProtag(Actor_t *, uint64_t);
void Jump(Actor_t *);

void setForwardTrue(Actor_t *);
void setForwardFalse(Actor_t *);
void setLeftTrue(Actor_t *);
void setLeftFalse(Actor_t *);
void setBackwardTrue(Actor_t *);
void setBackwardFalse(Actor_t *);
void setRightTrue(Actor_t *);
void setRightFalse(Actor_t *);

#endif
