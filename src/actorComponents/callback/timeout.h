
#ifndef TIMEOUT
#define TIMEOUT

#define TIMEOUT_REMAINING 0

struct callbackController genTimeout(void (*)(struct callbackController), int);
char shouldTimeout(struct callbackController);


#endif /* TIMEOUT */
