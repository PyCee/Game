
#ifndef CALLBACK
#define CALLBACK

typedef struct callback{
	char (*shouldCallback)(struct callback);
	void (*completeCallback)(struct callback);
	unsigned char *_uchar;
	unsigned char numChar;
	float *_float;
	unsigned char numFloat;
	int *_int;
	unsigned char numInt;
} callback;

callback *callbacks[10];
void updateCallbacks(void);
unsigned char nextFreeCallback(void);
void enableCallback(callback *);
void freeCallbacks(void);

callback genCallback(char (*should)(callback), void (*complete)(callback), unsigned char *, unsigned char, float *, unsigned char, int *, unsigned char);
void freeCallback(callback *);
void checkCallback(callback *);

#endif /* CALLBACK */
