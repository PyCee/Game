#ifndef AFTER_EFFECTS
#define AFTER_EFFECTS

extern GLuint **afterEffectPrograms;
extern char numAfterEffects;

void addAfterEffect(GLuint *);
void removeAfterEffect(char);

#endif /* AFTER_EFFECTS */
