
#ifndef TIMEOUT
#define TIMEOUT

#define TIMEOUT_REMAINING 0

struct callback genTimeout(int, void (*complete)(struct callback));
char shouldTimeout(struct callback);


#endif /* TIMEOUT */
