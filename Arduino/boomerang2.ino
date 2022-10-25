/*
Keyboard Boomerang-2 Ergo
Version: 1.1
Date: 2022-10-26
Author: Vladimir Romanovich <ibnteo@gmail.com>
License: MIT
*/

#include <Keyboard.h>
#include <Keypad.h>
#include <EEPROM.h>

#define KEY_NONUS_BSLASH 0xEC
#define KEY_APPLICATION 0xED

#define KEYS 30
byte lay = 0;
byte press[KEYS] = {};
byte queue[KEYS] = {};
byte qshift = 0;

#define EEPROM_OS 0
#include "pcb.h"
#include "os.h"
#include "layouts.h"

void kpress(byte k) {
	if (k<1) return;
	press[k-1] = 1;
	byte p = 0;
	for (byte i=0; i<KEYS; i++) {
		if (queue[i]==0) {
			p = i;
			break;
		}
	}
	if (press[K_NAVS-1]>0 && ! qshift) {
		byte code = pgm_read_byte(&navs[k-1]);
		if (code) Keyboard.press(code);
		else if (k==K_LAY1) layout(0);
		else if (k==K_LAY2) layout(1);
		else if (k==K_QSHIFT) qshift = 0;
		//else if (press[K_QSHIFT-1]>0 && k==K_QSHIFT) qshift = 1;
		else if (k==K_NAVS) {
			for (byte i=0; i<KEYS; i++) {
				if (queue[i]==0) {
					break;
				} else if (press[queue[i]-1] == 1) {
					press[K_NAVS-1] = 3;
					byte c = pgm_read_byte(&navs[queue[i]-1]);
					if (c != 0) Keyboard.press(c);
				}
			}
		}
	}
	queue[p] = k;
}

void krelease(byte k) {
	if (k<1) return;
	bool q = false;
	for (byte i=0; i<KEYS; i++) {
		if (queue[i]==0) {
			break;
		} else if (queue[i]==k) {
			q = true;
		}
	}
	bool p = false;
	for (byte i=0; i<KEYS; i++) {
		if (queue[i]==0) {
			break;
		} else if (queue[i]==k || p || ! q) {
			p = true;
			if (press[queue[i]-1]==1) {
				kprint(queue[i]);
			}
			if (! q) press[queue[i]-1] = 3;
		} else {
			khold(queue[i]);
		}
		queue[i] = 0;
	}
	if (k==K_NAVS) {
		if (press[K_NAVS-1]==1 && press[K_FUNC-1]==0 && press[K_NUMB-1]==0) Keyboard.write(' ');
		Keyboard.releaseAll();
		if (! qshift && press[K_QSHIFT-1]==1) qshift = 3;
		else qshift = (qshift==1) ? 3 : 0;
	} else if (press[K_NAVS-1]>0 && press[K_QSHIFT-1]==1 && k==K_QSHIFT) {
		qshift = 1;
	} else if (press[K_NAVS-1]>0 && ! qshift) {
		byte c = pgm_read_byte(&navs[k-1]);
		if (c) Keyboard.release(c);
	}
	press[k-1] = 0;
}

void kprint(byte k) {
	if (press[K_NAVS-1]>1 && ! qshift) return;
	byte code = 0;
	bool cl = false;
	bool shift = press[K_SHIFT_R1-1]>1 || press[K_SHIFT_R2-1]>1 || press[K_SHIFT_L1-1]>1 || press[K_SHIFT_L2-1]>1;
	if (lay==1 && (k==1 && press[10-1]>1 || k==10 && press[1-1]>1)) {
		code = shift || qshift ? '}' : ']';
	} else if (lay==1 && (k==4 && press[5-1]>0 || k==5 && press[4-1]>0)) {
		code = shift || qshift ? '~' : '`';
		press[4-1] = 0;
		press[5-1] = 0;
	} else if (lay==1 && (k==6 && press[7-1]>0 || k==7 && press[6-1]>0)) {
		code = shift || qshift ? 'O' : 'o';
		press[6-1] = 0;
		press[7-1] = 0;
	} else if (lay==1 && (k==14 && press[15-1]>0 || k==15 && press[14-1]>0)) {
		//code = shift || qshift ? '>' : '.';
		code = shift || qshift ? '"' : '\'';
		press[14-1] = 0;
		press[15-1] = 0;
	} else if (lay==1 && (k==16 && press[17-1]>0 || k==17 && press[16-1]>0)) {
		//code = shift || qshift ? '{' : '[';
		code = shift || qshift ? 'A' : 'a';
		press[16-1] = 0;
		press[17-1] = 0;
	} else if (press[K_LEFT-1]>1) {
		if (k==K_LINUX) {
			sel_os(LINUX);
			if (press[K_OS_SAVE-1]>1) EEPROM.write(EEPROM_OS, LINUX);
		} else if (k==K_WINDOWS) {
			sel_os(WINDOWS);
			if (press[K_OS_SAVE-1]>1) EEPROM.write(EEPROM_OS, WINDOWS);
		} else if (k==K_MACOS) {
			sel_os(MACOS);
			if (press[K_OS_SAVE-1]>1) EEPROM.write(EEPROM_OS, MACOS);
		} else {
			code = pgm_read_byte(&left[k-1]);
		}
	} else if (press[K_FUNC-1]>1) {
		if (qshift) Keyboard.press(KEY_RIGHT_SHIFT);
		if (press[K_SHIFT_R1-1]>1 || press[K_SHIFT_R2-1]>1) Keyboard.press(KEY_RIGHT_SHIFT);
		if (press[K_SHIFT_L1-1]>1 || press[K_SHIFT_L2-1]>1) Keyboard.press(KEY_LEFT_SHIFT);
		code = pgm_read_byte(&func[k-1]);
	} else if (press[K_NUMB-1]>1) {
		if (qshift) Keyboard.press(KEY_RIGHT_SHIFT);
		if (press[K_SHIFT_R1-1]>1 || press[K_SHIFT_R2-1]>1) Keyboard.press(KEY_RIGHT_SHIFT);
		if (press[K_SHIFT_L1-1]>1 || press[K_SHIFT_L2-1]>1) Keyboard.press(KEY_LEFT_SHIFT);
		code = pgm_read_byte(&numb[k-1]);
	} else if (press[K_SPACE-1]>1 && shift) {
		code = pgm_read_byte(&spaces[lay][k-1]);
		if (! code) {
			code = pgm_read_byte(&spaces[1-lay][k-1]);
			cl = true;
		}
	} else if (press[K_SPACE-1]>1) {
		code = pgm_read_byte(&space[lay][k-1]);
		if (! code) {
			code = pgm_read_byte(&space[1-lay][k-1]);
			cl = true;
		}
	} else if (press[K_COMPOSE_LEFT-1]>1 || press[K_COMPOSE_RIGHT-1]>1) {
		byte c = pgm_read_byte(&lay0[k-1]);
		unicode(compose(c));
	} else if (press[K_MACROS_LEFT-1]>1 || press[K_MACROS_RIGHT-1]>1) {
		byte c = pgm_read_byte(&lay0[k-1]);
		macro(macros(c));
	} else if (
		press[K_GUI_R1-1]>1 || press[K_GUI_R2-1]>1 || press[K_GUI_L1-1]>1 || press[K_GUI_L2-1]>1 ||
		press[K_ALT_R1-1]>1 || press[K_ALT_R2-1]>1 || press[K_ALT_L1-1]>1 || press[K_ALT_L2-1]>1 ||
		press[K_CTRL_R1-1]>1 || press[K_CTRL_R2-1]>1 || press[K_CTRL_L1-1]>1 || press[K_CTRL_L2-1]>1
	) {
		if (qshift) Keyboard.press(KEY_RIGHT_SHIFT);
		if (press[K_SHIFT_R1-1]>1 || press[K_SHIFT_R2-1]>1) Keyboard.press(KEY_RIGHT_SHIFT);
		if (press[K_SHIFT_L1-1]>1 || press[K_SHIFT_L2-1]>1) Keyboard.press(KEY_LEFT_SHIFT);
		code = pgm_read_byte(&lay0[k-1]);
	} else {
		if (shift || qshift) {
			code = pgm_read_byte(&slays[lay][k-1]);
			if (code==' ') {
				if (qshift) Keyboard.press(KEY_RIGHT_SHIFT);
				if (press[K_SHIFT_R1-1]>1 || press[K_SHIFT_R2-1]>1) Keyboard.press(KEY_RIGHT_SHIFT);
				if (press[K_SHIFT_L1-1]>1 || press[K_SHIFT_L2-1]>1) Keyboard.press(KEY_LEFT_SHIFT);
			}
		} else {
			code = pgm_read_byte(&lays[lay][k-1]);
		}
	}
	if (code) {
		if (press[K_GUI_R1-1]>1 || press[K_GUI_R2-1]>1) Keyboard.press(KEY_RIGHT_GUI);
		if (press[K_GUI_L1-1]>1 || press[K_GUI_L2-1]>1) Keyboard.press(KEY_LEFT_GUI);
		if (press[K_CTRL_R1-1]>1 || press[K_CTRL_R2-1]>1) Keyboard.press(KEY_RIGHT_CTRL);
		if (press[K_CTRL_L1-1]>1 || press[K_CTRL_L2-1]>1) Keyboard.press(KEY_LEFT_CTRL);
		if (press[K_ALT_R1-1]>1 || press[K_ALT_R2-1]>1) Keyboard.press(KEY_RIGHT_ALT);
		if (press[K_ALT_L1-1]>1 || press[K_ALT_L2-1]>1) Keyboard.press(KEY_LEFT_ALT);
		if (cl) layout(1-lay);
		Keyboard.write(code);
		if (cl) layout(1-lay);
		if (qshift==1) qshift = 2;
		else if (qshift==3) qshift = 0;
	}
	Keyboard.releaseAll();
}

void khold(byte k) {
	if (k<1) return;
	if (press[k-1]<2) {
		press[k-1] = 2;
	}
}

void macro(String str) {
	if (str=="") return;
	byte l = lay;
	Keyboard.releaseAll();
	layout(0);
	Keyboard.print(str);
	layout(l);
}

void unicode(String str) {
	if (str=="") return;
	byte l = lay;
	Keyboard.releaseAll();
	if (os==LINUX && LINUX_COMPOSE && str.length()<4) {
		// Compose
		Serial.println(str.length(), DEC);
		layout(0);
		Keyboard.press(LINUX_COMPOSE);
		Keyboard.print(str);
		Keyboard.releaseAll();
		layout(l);
	} else if (os==LINUX) {
		// Ctrl+U <code> <Enter>
		layout(0);
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.write('U');
		Keyboard.releaseAll();
		Keyboard.print(str);
		Keyboard.write(KEY_RETURN);
		layout(l);
	} else if (os==WINDOWS) {
		// Alt+<codeNumBlock>
		Keyboard.press(KEY_RIGHT_ALT);
		for (byte i = 0; i < str.length(); i++) {
			byte s = str.charAt(i) - '1' + KEY_KP_1;
			if (s < KEY_KP_1 || s > KEY_KP_9) s = KEY_KP_0;
			Keyboard.write(s);
		}
		Keyboard.releaseAll();
	}
}

void setup() {
	Serial.begin(9600);
	os = EEPROM.read(EEPROM_OS);
	sel_os(os);
	pinMode(LED_BUILTIN_TX, INPUT);
	pinMode(LED_LAYER, OUTPUT);
	Keyboard.begin();
}

void loop() {
	for (byte k=0; k<KEYPADS; k++) {
		if (keypad[k].getKeys()) {
			for (int i=0; i<LIST_MAX; i++) {
				if (keypad[k].key[i].stateChanged && keypad[k].key[i].kchar) {
					if (keypad[k].key[i].kstate==PRESSED) {
						kpress(keypad[k].key[i].kchar);
					} else if (keypad[k].key[i].kstate==RELEASED) {
						krelease(keypad[k].key[i].kchar);
					} else if (keypad[k].key[i].kstate==HOLD) {
						khold(keypad[k].key[i].kchar);
					}
				}
			}
		}
	}
}
