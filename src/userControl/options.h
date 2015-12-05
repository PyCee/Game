/**
Sound
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

#define CONFIG_PATH "../usrData/config"

#define STR_SOUND_LEVEL "Sound_Level:"
#define STR_MUSIC_LEVEL "Music_Level:"
#define STR_SOUND_EFFECTS_LEVEL "Sound_Effects_Level:"
#define STR_FIELD_OF_VIEW "Field_Of_View:"
#define STR_BRIGHTNESS "Brightness:"
#define STR_MOUSE_SENSITIVITY "Mouse_Sensitivity:"
#define STR_MOUSE_LOCK "Lock_Mouse_To_Screen:"

void InitOptions(void);

void SaveOptions(void);

void DefaultAllOptions(void);

void DefaultAllSoundOptions(void);

void DefaultSoundLevel(void);
static U8 SoundLevel = 0;
static U8 MuteSound = 0;
#define DEFAULT_SOUND_LEVEL 1
#define MAX_SOUND_LEVEL 255
#define MIN_SOUND_LEVEL 0

void DefaultMusicLevel(void);
static U8 MusicLevel = 0;
static U8 MuteMusic = 0;
#define DEFAULT_MUSIC_LEVEL 2
#define MAX_MUSIC_LEVEL 255
#define MIN_MUSIC_LEVEL 0

void DefaultEffectsLevel(void);
static U8 SoundEffectsLevel = 0;
static U8 MuteSoundEffects = 0;
#define DEFAULT_SOUND_EFFECTS_LEVEL 3
#define MAX_SOUND_EFFECTS_LEVEL 255
#define MIN_SOUND_EFFECTS_LEVEL 0

void DefaultAllVideoOptions(void);

void DefaultFieldOfView(void);
static U8 FieldOfView = 0;
#define DEFAULT_FIELD_OF_VIEW 120
#define MAX_FIELD_OF_VIEW 150
#define MIN_FIELD_OF_VIEW 70

void DefaultBrightness(void);
static U8 Brightness = 0;
#define DEFAULT_BRIGHTNESS 5
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0

void DefaultAllControlOptions(void);

void DefaultMouseSensitivity(void);
#define DEFAULT_MOUSE_SENSITIVITY 128
#define MAX_MOUSE_SENSITIVITY 255
#define MIN_MOUSE_SENSITIVITY 0
static U8 MouseSensitivity = DEFAULT_MOUSE_SENSITIVITY;

void DefaultMouseLock(void);
static U8 MouseLock = 1;
#define DEFAULT_MOUSE_LOCK 1
#define MAX_MOUSE_LOCK 1
#define MIN_MOUSE_LOCK 0

#endif
