#ifndef CALLBACK_COMPONENT
#define CALLBACK_COMPONENT

#define CALLBACKS callback[getActor()]->callbacks
#define NUM_CALLBACKS callback[getActor()]->numCallbacks

typedef struct CallbackComponent {
	struct callbackController **callbacks;
	unsigned char numCallbacks;
} CallbackComponent;

void genCallbackComponent(void);
void freeCallbackComponent(void);
void updateCallbackComponent(unsigned short);
unsigned char nextFreeCallbackController(void);
void enableCallbackController(struct callbackController *);
void disableCallbackController(unsigned char);

#endif /* CALLBACK_COMPONENT */
