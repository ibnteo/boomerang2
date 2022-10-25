#define LINUX_COMPOSE KEY_LEFT_GUI

const unsigned char lay0[KEYS] PROGMEM = {
	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
	'z', 'x', 'c', 'v', 0, ' ', 'b', 'n', ',', '.'
};
const unsigned char lays[2][KEYS] PROGMEM = {
	{
		'q', 'u', 'i', 'e', 'g', 'w', 'c', 'n', 'd', 'z',
		'f', 'y', 'o', 'a', 'p', 'r', 't', 's', 'h', 'l',
		0, 'v', 'k', 'x', 0, ' ', 'm', 'b', 'j', 0
	},
	{
		'q', 'e', 'b', 't', 'u', 'i', 'r', 'y', 'l', 'p',
		'm', 's', 'j', 'f', 'g', 'h', 'n', 'c', 'd', 'k',
		'z', 'x', 'w', '[', 0, ' ', 'v', ',', '.', ';'
	}
};
const unsigned char slays[2][KEYS] PROGMEM = {
	{
		'Q', 'U', 'I', 'E', 'G', 'W', 'C', 'N', 'D', 'Z',
		'F', 'Y', 'O', 'A', 'P', 'R', 'T', 'S', 'H', 'L',
		0, 'V', 'K', 'X', 0, ' ', 'M', 'B', 'J', 0
	},
	{
		'Q', 'E', 'B', 'T', 'U', 'I', 'R', 'Y', 'L', 'P',
		'M', 'S', 'J', 'F', 'G', 'H', 'N', 'C', 'D', 'K',
		'Z', 'X', 'W', '{', 0, ' ', 'V', '<', '>', ':'
	}
};
const unsigned char navs[KEYS] PROGMEM = {
	' ', 0, 0, 0, 0, KEY_ESC, KEY_HOME, KEY_UP_ARROW, KEY_END, KEY_PAGE_UP,
	KEY_RIGHT_SHIFT, KEY_RIGHT_GUI, KEY_RIGHT_ALT, KEY_RIGHT_CTRL, KEY_KP_ENTER, KEY_RETURN, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_TAB,
	KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_GUI, KEY_LEFT_SHIFT, 0, 0, KEY_BACKSPACE, KEY_DELETE, KEY_INSERT, KEY_PAGE_DOWN
};
const unsigned char space[2][KEYS] PROGMEM = {
	{
		'"', ':', ';', '_', '\\', '*', '1', '2', '3', '-',
		'\'', '.', ',', '-', '/', '0', '4', '5', '6', '+',
		'`', '<', '>', '=', 0, 0, '7', '8', '9', '.'
	},{
		'@', '^', '$', '_', '\\', '*', '1', '2', '3', '-',
		0, '/', '?', '-', '|', '0', '4', '5', '6', '+',
		0, 0, 0, '=', 0, 0, '7', '8', '9', '/'
	}
};
const unsigned char spaces[2][KEYS] PROGMEM = {
	{
		0, 0, '[', ']', 0, '?', '!', '@', '#', 0,
		0, 0, '(', ')', 0, '~', '$', '%', '^', 0 ,
		0, 0, '{', '}', 0, 0, '&', '|', 0, 0
	},{
		0, 0, 0, 0, 0, '&', '!', 0, 0, '#',
		0, 0, '(', ')', 0, 0, 0, '%', 0, 0 ,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
};
const unsigned char numb[KEYS] PROGMEM = {
	KEY_APPLICATION, KEY_CAPS_LOCK, KEY_SCROLL_LOCK, KEY_NUM_LOCK, 0, KEY_KP_ASTERISK, KEY_KP_7, KEY_KP_8, KEY_KP_9, KEY_KP_MINUS,
	0, 0, 0, 0, 0, KEY_KP_SLASH, KEY_KP_4, KEY_KP_5, KEY_KP_6, KEY_KP_PLUS,
	0, 0, 0, 0, KEY_KP_ENTER, KEY_KP_0, KEY_KP_1, KEY_KP_2, KEY_KP_3, KEY_KP_DOT
};
const unsigned char func[KEYS] PROGMEM = {
	KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_PRINT_SCREEN, 0, 0, 0, 0, 0,
	KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_PAUSE, 0, 0, 0, 0, 0,
	KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_RETURN, 0, 0, 0, 0, 0,
};
const unsigned char left[KEYS] PROGMEM = {
	0, KEY_TAB, KEY_DELETE, KEY_BACKSPACE, KEY_ESC, 0, 0, 0, 0, 0,
	0, KEY_HOME, KEY_UP_ARROW, KEY_END, KEY_RETURN, 0, 0, 0, 0, 0,
	0, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, ' ', 0, 0, 0, 0, 0,
};

#define K_LEFT 1
#define K_NUMB 15
#define K_FUNC 16
#define K_NAVS 25
#define K_QSHIFT 26
#define K_SPACE 26
#define K_LAY1 3
#define K_LAY2 2

#define K_COMPOSE_LEFT 2
#define K_COMPOSE_RIGHT 9

#define K_MACROS_LEFT 3
#define K_MACROS_RIGHT 8

#define K_SHIFT_R1 11
#define K_GUI_R1 12
#define K_ALT_R1 13
#define K_CTRL_R1 14
#define K_CTRL_R2 17
#define K_ALT_R2 18
#define K_GUI_R2 19
#define K_SHIFT_R2 20

#define K_CTRL_L1 21
#define K_GUI_L1 22
#define K_ALT_L1 23
#define K_SHIFT_L1 24
#define K_SHIFT_L2 27
#define K_ALT_L2 28
#define K_GUI_L2 29
#define K_CTRL_L2 30

#define K_LINUX 27
#define K_WINDOWS 28
#define K_MACOS 29
#define K_OS_SAVE 30

String compose(byte c) {
  if (c=='.' && os==LINUX) return "0301"; // ударе́ние
  else if (c=='.' && os==WINDOWS) return "0301";

  else if (c=='j' && os==LINUX) return LINUX_COMPOSE ? "<<" : "00ab"; // «
  else if (c=='j' && os==WINDOWS) return "0171";

  else if (c=='k' && os==LINUX) return LINUX_COMPOSE ? ">>" : "00bb"; // »
  else if (c=='k' && os==WINDOWS) return "0187";

  else if (c=='h' && os==LINUX) return LINUX_COMPOSE ? ",\"" : "201e"; // „
  else if (c=='h' && os==WINDOWS) return "8222";

  else if (c=='l' && os==LINUX) return LINUX_COMPOSE ? "<\"" : "0093"; // “
  else if (c=='l' && os==WINDOWS) return "0147";

  else if (c=='m' && os==LINUX) return LINUX_COMPOSE ? ">\"" : "0094"; // ”
  else if (c=='m' && os==WINDOWS) return "0148";

  else if (c==' ' && os==LINUX) return LINUX_COMPOSE ? "  " : "00a0"; // nbsp
  else if (c==' ' && os==WINDOWS) return "0160";

  else if (c=='o' && os==LINUX) return LINUX_COMPOSE ? "oo" : "00b0"; // °
  else if (c=='o' && os==WINDOWS) return "0176";

  else if (c=='e' && os==LINUX) return LINUX_COMPOSE ? "=c" : "20ac"; // €
  else if (c=='e' && os==WINDOWS) return "8364";

  else if (c=='r' && os==LINUX) return "20bd"; // ₽
  else if (c=='r' && os==WINDOWS) return "8381";

  else if (c=='u' && os==LINUX) return LINUX_COMPOSE ? "ox" : "00a4"; // ¤
  else if (c=='u' && os==WINDOWS) return "0164";

  else if (c=='i' && os==LINUX) return LINUX_COMPOSE ? "so" : "00a7"; // §
  else if (c=='i' && os==WINDOWS) return "0167";

  else if (c=='p' && os==LINUX) return LINUX_COMPOSE ? "PP" : "00b6"; // ¶
  else if (c=='p' && os==WINDOWS) return "0182";

  else if (c=='q' && os==LINUX) return LINUX_COMPOSE ? "+-" : "00b1"; // ±
  else if (c=='q' && os==WINDOWS) return "0177";

  else if (c=='y' && os==LINUX) return LINUX_COMPOSE ? "xx" : "008e"; // ×
  else if (c=='y' && os==WINDOWS) return "0142";

  else if (c=='f' && os==LINUX) return LINUX_COMPOSE ? "--." : "2013"; // –
  else if (c=='f' && os==WINDOWS) return "0150";

  else if (c=='d' && os==LINUX) return LINUX_COMPOSE ? "---" : "2014"; // —
  else if (c=='d' && os==WINDOWS) return "0151";

  else if (c=='g' && os==LINUX) return LINUX_COMPOSE ? ":-" : "008f"; // ÷
  else if (c=='g' && os==WINDOWS) return "0143";

  return "";
}

String macros(byte c) {
	switch (c) {
		case 'r': return "return";
		case 'e': return "foreach";
		case 'f': return "function";
		case 'w': return "width";
		case 'h': return "height";
		case 'l': return "length";
		case 'c': return "const";
		case 's': return "switch";
	}
	return "";
}
