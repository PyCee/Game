

#ifndef _PROTAG_
#define _PROTAG_

typedef struct _Character_t Character_t;

void genProtag(Character_t **);
void freeProtag(Character_t **);
void UpdateProtag(Character_t *, uint64_t );
void Jump(Character_t *);

void setForwardTrue(Character_t *);
void setForwardFalse(Character_t *);
void setLeftTrue(Character_t *);
void setLeftFalse(Character_t *);
void setBackwardTrue(Character_t *);
void setBackwardFalse(Character_t *);
void setRightTrue(Character_t *);
void setRightFalse(Character_t *);

#endif
