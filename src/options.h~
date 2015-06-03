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
**/

#ifndef _OPTIONS_
#define _OPTIONS_

#define CONFIG_PATH "usrData/config"

#define STR_SOUND_LEVEL "Sound Level: %u\n"
#define STR_MUSIC_LEVEL "Music Level: %u\n"
#define STR_SOUND_EFFECTS_LEVEL "Sound Effects Level: %u\n"
#define STR_FIELD_OF_VIEW "Field Of View: %u\n"
#define STR_BRIGHTNESS "Brightness: %u\n"
#define STR_MOUSE_SENSITIVITY "Mouse Sensitivity: %u\n"

void InitOptions();

void SaveOptions();

void DefaultAllOptions();

void DefaultAllSoundOptions();

void DefaultSoundLevel();
static unsigned char SoundLevel = 0;
static unsigned char MuteSound = 0;
#define DEFAULT_SOUND_LEVEL 0
#define MAX_SOUND_LEVEL 255
#define MIN_SOUND_LEVEL 0

void DefaultMusicLevel();
static unsigned char MusicLevel = 0;
static unsigned char MuteMusic = 0;
#define DEFAULT_MUSIC_LEVEL 0
#define MAX_MUSIC_LEVEL 255
#define MIN_MUSIC_LEVEL 0

void DefaultEffectsLevel();
static unsigned char SoundEffectsLevel = 0;
static unsigned char MuteSoundEffects = 0;
#define DEFAULT_SOUND_EFFECTS_LEVEL 0
#define MAX_SOUND_EFFECTS_LEVEL 255
#define MIN_SOUND_EFFECTS_LEVEL 0

void DefaultAllVideoOptions();

void DefaultFieldOfView();
static unsigned char FieldOfView = 0;
#define DEFAULT_FIELD_OF_VIEW 100
#define MAX_FIELD_OF_VIEW 150
#define MIN_FIELD_OF_VIEW	70

void DefaultBrightness();
static unsigned char Brightness = 0;
#define DEFAULT_BRIGHTNESS 1
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0

void DefaultAllControlOptions();

void DefaultMouseSensitivity();
static unsigned char MouseSensitivity = 0;
#define DEFAULT_MOUSE_SENSITIVITY 1
#define MAX_MOUSE_SENSITIVITY 255
#define MIN_MOUSE_SENSITIVITY 0

#endif
