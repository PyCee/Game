
#ifndef _KEYBOARD_
#define _KEYBOARD_

typedef struct _Character_t Character_t;

char pressed[274];
char KEYS[274];
void (*press[274])(Character_t*);
void (*release[274])(Character_t*);

void InitKeyboard();
void DefaultKeyboard();
void UselessFunction();
void EndGame();

void handleEvents();

#endif

/*
	SDLK_ESCAPE top left of keyboard
	SDLK_F1
	SDLK_F2
	SDLK_F3
	SDLK_F4
	SDLK_F5
	SDLK_F6
	SDLK_F7
	SDLK_F8
	SDLK_F9
	SDLK_F10
	SDLK_F11
	SDLK_F12
	SDLK_1
	SDLK_2
	SDLK_3
	SDLK_4
	SDLK_5
	SDLK_6
	SDLK_7
	SDLK_8
	SDLK_9
	SDLK_0
	SDLK_MINUS -
	SDLK_EQUALS =
	SDLK_BACKSPACE backspace, right of '='
	SDLK_TAB --	-- tab, left of 'q'
	SDLK_q
	SDLK_w
	SDLK_e
	SDLK_r
	SDLK_t
	SDLK_y
	SDLK_u
	SDLK_i
	SDLK_o
	SDLK_p
	SDLK_LEFTBRACKET [ , right of 'p'
	SDLK_RIGHTBRACKET ] , right of '['
	SDLK_BACKSLASH \, backslash, right of ']'
	SDLK_CAPSLOCK caps lock, left of 'a'
	SDLK_a
	SDLK_s
	SDLK_d
	SDLK_f
	SDLK_g
	SDLK_h
	SDLK_j
	SDLK_k
	SDLK_l
	SDLK_SEMICOLON ;  right of 'l'
	SDLK_QUOTE '  singular quote, right of ';'
	SDLK_RSHIFT right shift, left of 'z'
	SDLK_RETURN enter key, mid-right of screen
	SDLK_z
	SDLK_x
	SDLK_c
	SDLK_v
	SDLK_b
	SDLK_n
	SDLK_m
	SDLK_COMMA comma, right of m
	SDLK_PERIOD .  period, right of comma, 2 right of m
	SDLK_SLASH /  left of right shift
	SDLK_LCTRL left control, below left shift
	SDLK_LALT left alt, below 'x' and 'c'
	SDLK_SPACE space bar, bottom mid
	SDLK_RALT right alt, below comma and period
	SDLK_RCTRL right control, below period and slash
	SDLK_KP_1 keypad 1
	SDLK_KP_2 keypad 2
	SDLK_KP_3 keypad 3
	SDLK_KP_4 keypad 4
	SDLK_KP_5 keypad 5
	SDLK_KP_6 keypad 6
	SDLK_KP_7 keypad 7
	SDLK_KP_8 keypad 8
	SDLK_KP_9 keypad 9
	SDLK_KP_0 keypad 0
	SDLK_KP_PERIOD keypad . , period, dot
	SDLK_KP_DIVIDE keypad / , slash
	SDLK_KP_MULTIPLY keypad * , multiply
	SDLK_KP_MINUS keypad - , dash
	SDLK_KP_PLUS keypad + , plus
	SDLK_KP_ENTER keypad enter
	SDLK_UP up arrow
	SDLK_LEFT left arrow
	SDLK_DOWN down arrow
	SDLK_RIGHT right arrow
*/
