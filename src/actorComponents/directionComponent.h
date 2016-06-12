#ifndef _DIRECTION_COMPONENT_
#define _DIRECTION_COMPONENT_

#define DIRECTION direction[getActor()]
#define FORWARDROTATION DIRECTION->forwardRotation
#define INVERSEFORWARDROTATION DIRECTION->inverseForwardRotation
#define FORWARD DIRECTION->forward
#define VIEW_TARGET DIRECTION->target
#define DIR_ROTATE DIRECTION->rotate
#define DIR_PREV_ROTATE DIRECTION->prevRotate
#define DIR_DELTA_ROTATE DIRECTION->deltaRotate
#define YAW DIR_ROTATE->yaw
#define PITCH DIR_ROTATE->pitch
#define ROLL DIR_ROTATE->roll
#define PREV_YAW DIR_PREV_ROTATE->yaw
#define PREV_PITCH DIR_PREV_ROTATE->pitch
#define PREV_ROLL DIR_PREV_ROTATE->roll
#define DELTA_YAW DIR_DELTA_ROTATE->yaw
#define DELTA_PITCH DIR_DELTA_ROTATE->pitch
#define DELTA_ROLL DIR_DELTA_ROTATE->roll
#define PAN_TIME DIRECTION->panTime
#define PAN_PROGRESS DIRECTION->panProgress
#define DELTA_PAN_PROGRESS DIRECTION->deltaPanProgress
#define VIEWSTATE DIRECTION->viewState
#define i *(XAxis)
#define j *(YAxis)
#define k *(ZAxis)
#define nk *(negZAxis)

#define VIEWSTATE_FREE_ROAM 0
#define VIEWSTATE_LOCK_ON 1
#define VIEWSTATE_PAN 2
#define VIEWSTATE_MOVE 3


typedef struct DirectionComponent {
	struct vec4 *forwardRotation, *inverseForwardRotation;
	struct vec3 *forward, *facing;
	struct vec3 *target;
	struct rotationController *rotate, *deltaRotate;
	float panTime, panProgress, deltaPanProgress;
	
	char viewState;
} DirectionComponent;

struct vec3 *XAxis;
struct vec3 *YAxis;
struct vec3 *ZAxis;
struct vec3 *negZAxis;
struct vec4 *noRotationVec4;

void initDirections(void);
void genDirectionComponent();
void freeDirectionComponent();
void updateDirectionComponent(unsigned short);

void DirectionYaw(float);
void DirectionPitch(float);
void DirectionRoll(float);

void setViewState(unsigned char);

void lookAt(struct vec3 *);
void panView(void);
#endif /* _DIRECTION_COMPONENT_ */
