#define LINUX	1
#define WINDOWS	2
#define MACOS	3
byte os = 1;
byte CTRL_L = KEY_LEFT_CTRL;
byte CTRL_R = KEY_RIGHT_CTRL;
byte WIN_L = KEY_LEFT_GUI;
byte WIN_R = KEY_RIGHT_GUI;
void sel_os(byte o) {
	os = o;
	if (os==MACOS) {
		CTRL_L = KEY_LEFT_GUI;
		CTRL_R = KEY_RIGHT_GUI;
		WIN_L = KEY_LEFT_CTRL;
		WIN_R = KEY_RIGHT_CTRL;
	} else {
		CTRL_L = KEY_LEFT_CTRL;
		CTRL_R = KEY_RIGHT_CTRL;
		WIN_L = KEY_LEFT_GUI;
		WIN_R = KEY_RIGHT_GUI;
	}
}
void layout(byte l) {
	if (lay != l) {
		Keyboard.releaseAll();
		if (os == MACOS) {
			Keyboard.press(KEY_LEFT_GUI);
			Keyboard.press(' ');
		} else if (os == WINDOWS) {
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press(KEY_LEFT_CTRL);
		} else {
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press(KEY_LEFT_ALT);
		}
		Keyboard.releaseAll();
	}
	lay = l;
	digitalWrite(LED_LAYER, lay == 0 ? LED_LAYER_LOW : LED_LAYER_HIGH);
}
