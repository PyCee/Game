#ifndef NEAR_TEST
#define NEAR_TEST

struct vec3;

struct callbackController genDistanceCheck(void (*)(struct callbackController), float, struct vec3 *);
char shouldDistanceCheck(struct callbackController);

#endif /* NEAR_TEST */
