#include "output.h"
#include "engine.h"
#include "unit.h"
#include <stdio.h>
#include <windows.h>
#include <wincon.h>
#include <winbase.h>
#include <stdlib.h>
#include <iostream>

void ShowCursor (bool option) {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = option;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void MaximizeScreen () {
	HANDLE console;
	COORD size;
	HWND hWnd;

	console = GetStdHandle(STD_OUTPUT_HANDLE);
	size = GetLargestConsoleWindowSize(console);
	SetConsoleScreenBufferSize(console, size);
	SetConsoleTitle("TANCURI");
	hWnd = FindWindow(NULL, "TANCURI");

	ShowWindow(hWnd, SW_MAXIMIZE);
}

void gotoxy (int col, int line) {
  COORD coord;
  coord.X = col;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }

static int pictVect[MAXNU][2], npict;

Output::Output (Engine &pm): motor(pm) {
}

void Output::init () {
	
	
	//textmode(c4350);
	//_setcursortype(_NOCURSOR);
	//clrscr();
	system ("cls");
	MaximizeScreen();
	ShowCursor(FALSE);
	
	int i, j;
	for (i = 0; i < motor.getnl(); i++) {
		for (j = 0; j < motor.getnc(); j++) {
			if (i == 0) {
				gotoxy(j, i + 2);
				std::cout << (char)219;
			}
			
			else if (j == 0) {
				gotoxy(j, i + 2);
				std::cout << (char)219;
			}
			
			else if (i == motor.getnl() - 1) {
				gotoxy(j, motor.getnl() + 1);
				std::cout << (char)219;
			}
			
			else if (j == motor.getnc() - 1) {
				gotoxy(motor.getnc() - 1, i + 2);
				std::cout << (char)219;
			}
			
			else if (motor.getUnitxy(i, j) != NULL) {
				if (*(char*)(motor.getUnitxy(i, j)->getTip())  == (char)177) {
					gotoxy(motor.getUnitPoz(i)->getx() + 1, motor.getUnitPoz(i)->gety() + 3);
					std::cout << (char)177;
				}
			}
			
			else if (motor.getUnitxy(i, j) == NULL)
			    gotoxy(j + 1, i + 3);
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	npict = 0;
}

void Output::close () {
	//textmode(c80);
	//_setcursortype(_NORMALCURSOR);
	ShowCursor(TRUE);
	system ("cls");
	//clrscr();
}

void Output::afisare () {
	int i;

	for (i = 0; i < npict; i++) {
			gotoxy(pictVect[i][0], pictVect[i][1]);
				std::cout << ' ';
	}
	
	npict = 0;

	for (i = 0; i < motor.getnu(); i++) {
		if (motor.getUnitPoz(i) != NULL)
			if (*(char*)(motor.getUnitPoz(i)->getTip()) != (char)177) {
				gotoxy(motor.getUnitPoz(i)->getx() + 1, motor.getUnitPoz(i)->gety() + 3);
				std::cout << *(char*)motor.getUnitPoz(i)->getTip();
				
				pictVect[npict][0] = motor.getUnitPoz(i)->getx() + 1;
				pictVect[npict][1] = motor.getUnitPoz(i)->gety() + 3;
				npict++;
			}
	}
}

/*void Output::afisare()
{
	int *A,i;

	for (i = 0;i<npict;i++) 
		{
			gotoxy(pictVect[i][0], pictVect[i][1]);
			std::cout<<' ';
		}
	npict=0;
	
	for (i = 0; i < motor.getnu(); i++) 
		{
		if (motor.getUnitPoz(i) != NULL)
		{
				A=(int*)(motor.getUnitPoz(i)->getTip());
				if (*A!=178) 
					{
						gotoxy(motor.getUnitPoz(i)->getx()+1, motor.getUnitPoz(i)->gety()+3);
						std::cout<<char(*A);
				
						pictVect[npict][0] = motor.getUnitPoz(i)->getx()+1;
						pictVect[npict][1] = motor.getUnitPoz(i)->gety()+3;
						npict++;
					}
		}
		}
}*/



