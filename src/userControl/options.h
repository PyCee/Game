/**
Sound
	-Master Sound Level
	-Sound Level
	-Music Level
	-Effects Level
Video
	-FOV
	-Brightness
Controls
	-Mouse Sensitivity
	-Lock Mouse
**/

#ifndef _OPTIONS_
#define _OPTIONS_

#define CONFIG_PATH "../usrData/config.xml"
#define DEFAULT_CONFIG_PATH "../usrData/defaultConfig.xml"

void loadOptions(unsigned char *);
void DefaultOptions(void);
void SaveOptions(void);

static unsigned char MasterLevel = 0;
static unsigned char MuteMaster = 0;
#define MAX_MASTER_SOUND_LEVEL 255
#define MIN_MASTER_SOUND_LEVEL 0

static unsigned char SoundLevel = 0;
static unsigned char MuteSound = 0;
#define MAX_SOUND_LEVEL 255
#define MIN_SOUND_LEVEL 0

static unsigned char MusicLevel = 0;
static unsigned char MuteMusic = 0;
#define MAX_MUSIC_LEVEL 255
#define MIN_MUSIC_LEVEL 0

static unsigned char SoundEffectsLevel = 0;
static unsigned char MuteSoundEffects = 0;
#define MAX_SOUND_EFFECTS_LEVEL 255
#define MIN_SOUND_EFFECTS_LEVEL 0

static unsigned char FieldOfView = 0;
#define MAX_FIELD_OF_VIEW 150
#define MIN_FIELD_OF_VIEW 70

static unsigned char Brightness = 0;
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0

#define MAX_MOUSE_SENSITIVITY 255
#define MIN_MOUSE_SENSITIVITY 0
static unsigned char MouseSensitivity = 1;

static unsigned char MouseLock = 1;
#define MAX_MOUSE_LOCK 1
#define MIN_MOUSE_LOCK 0

#endif
