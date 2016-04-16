
#ifndef _CALLBACK_
#define _CALLBACK_
/*
	TimeCallback (origin, )
	HealthCallback 






*/

typedef struct callback{
	
	char (*isFinished)(void);
	void (*callback)(void);
} callback;

#endif /* _CALLBACK_ */
