#include "input.h"
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <cctype>

void Input::init () {
}

void Input::close () {
}

int Input::getc () {
	int c;

	if (kbhit()) {
		c = getch();
		if (c == 0 || c == 224)
			c = getch();
	}
	c = tolower(c);
	return (c == 0) ? 0 : c;
}
