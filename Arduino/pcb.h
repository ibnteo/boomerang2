#define LED_LAYER LED_BUILTIN_RX
#define LED_LAYER_HIGH LOW
#define LED_LAYER_LOW HIGH

/*
  Rro Micro
R1 2	21 R1
R2 3	20 R2
C5 4	19 C6
C4 5	18 C7
C3 6	15 C8
C2 7	14 C9
C1 8	16 C10
R3 9	10 R3
*/

#define COLS 5
#define ROWS 3
#define KEYPADS 2
byte colPins[KEYPADS][COLS] = {
	{8, 7, 6, 5, 4},
	{19, 18, 15, 14, 16}
};
byte rowPins[KEYPADS][ROWS] = {
	{2, 3, 9},
	{21, 20, 10}
};
const char keypad_keys[KEYPADS][ROWS][COLS] = {
	{
		{1, 2, 3, 4, 5},
		{11, 12, 13, 14, 15},
		{21, 22, 23, 24, 25}
	},
	{
		{6, 7, 8, 9, 10},
		{16, 17, 18, 19, 20},
		{26, 27, 28, 29, 30}
	}
};
Keypad keypad[KEYPADS] = {
	Keypad(makeKeymap(keypad_keys[0]), rowPins[0], colPins[0], ROWS, COLS),
	Keypad(makeKeymap(keypad_keys[1]), rowPins[1], colPins[1], ROWS, COLS)
};
