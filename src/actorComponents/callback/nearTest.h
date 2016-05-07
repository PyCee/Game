#ifndef NEAR_TEST
#define NEAR_TEST

struct vec3;

struct callbackController genNearTest(void (*)(struct callbackController), float, struct vec3 *);
char shouldNearTest(struct callbackController);

#endif /* NEAR_TEST */
