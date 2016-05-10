
#ifndef CALLBACK
#define CALLBACK

#define CALLBACK_VEC3 0
#define CALLBACK_FLOAT 1
#define CALLBACK_INT 2
#define CALLBACK_CHAR 3

typedef struct callbackController{
	char (*shouldCallback)(struct callbackController);
	void (*completeCallback)(struct callbackController);
	struct vec3 *_vec3;
	unsigned char numVec3;
	float *_float;
	unsigned char numFloat;
	int *_int;
	unsigned char numInt;
	unsigned char *_uchar;
	unsigned char numUChar;
} callbackController;


callbackController genCallbackController(char (*)(callbackController), void (*)(callbackController));
void freeCallbackController(callbackController *);
void checkCallbackController(callbackController *);
void callbackControllerElement(callbackController *, void *, unsigned char, unsigned char);

#endif /* CALLBACK */
