
#ifndef _KEYBOARD_
#define _KEYBOARD_

#define KEY_BINDINGS_PATH "usrData/keyBindings"
#define DEFAULT_KEY_BINDINGS_PATH "usrData/defaultKeyBindings"

typedef struct _Actor_t Actor_t;

char pressed[274];

void InitKeyboard(void);
void DefaultKeyboard(void);
void UselessFunction(void);
void EndGame(void);

void handleEvents(void);

void LoadKeyBindings(void);
void SaveKeyBindings(void);

// Key --> Function
void (*keyFunctions[274 * 2]) (void);

// Function --> Key
static U8 functionKeys[274]; // In order of Key Bindings list

#define STR_SAVE_FILE_EXIT "Exit_Game: %c\n"
#define STR_SAVE_FILE_FOREWARD "Move_Foreward: %c\n"
#define STR_SAVE_FILE_LEFT "Move_Left: %c\n"
#define STR_SAVE_FILE_BACKWARD "Move_Backward: %c\n"
#define STR_SAVE_FILE_RIGHT "Move_Right: %c\n"
#define STR_SAVE_FILE_JUMP "Jump: %c\n"
#define STR_SAVE_FILE_b "b %c\n"

#define STR_SAVE_FILE_LIST_KEY_STRINGS "Valid_keys:_\'Esc\'_"
/*
KeyBindingStrings[] = {
	"_ESCAPE",
	"_F1",
	"_F2",
	"_F3",
	"_F4",
	"_F5",
	"_F6",
	"_F7",
	"_F8",
	"_F9",
	"_F10",
	"_F11",
	"_F12",
	"_1",
	"_2",
	"_3",
	"_4",
	"_5",
	"_6",
	"_7",
	"_8",
	"_9",
	"_0",
	"_MINUS",
	"_EQUALS",
	"_BACKSPACE",
	"_TAB",
	"_q",
	"_w",
	"_e",
	"_r",
	"_t",
	"_y",
	"_u",
	"_i",
	"_o",
	"_p",
	"_LEFTBRACKET",
	"_RIGHTBRACKET",
	"_BACKSLASH",
	"_CAPSLOCK",
	"_a",
	"_s",
	"_d",
	"_f",
	"_g",
	"_h",
	"_j",
	"_k",
	"_l",
	"_SEMICOLON",
	"_QUOTE",
	"_RSHIFT",
	"_RETURN",
	"_z",
	"_x",
	"_c",
	"_v",
	"_b",
	"_n",
	"_m",
	"_COMMA",
	"_PERIOD",
	"_SLASH",
	"_LCTRL",
	"_LALT",
	"_SPACE",
	"_RALT",
	"_RCTRL",
	"_KP_1",
	"_KP_2",
	"_KP_3",
	"_KP_4",
	"_KP_5",
	"_KP_6",
	"_KP_7",
	"_KP_8",
	"_KP_9",
	"_KP_0",
	"_KP_PERIOD",
	"_KP_DIVIDE",
	"_KP_MULTIPLY",
	"_KP_MINUS",
	"_KP_PLUS",
	"_KP_ENTER",
	"_UP",
	"_LEFT",
	"_DOWN",
	"_RIGHT",
}
*/
#endif
