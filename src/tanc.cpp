#include "input.h"
#include "output.h"
#include "joctanc.h"
#include <iostream>
#include <windows.h>

Input intrare;
Output iesire(Tanc::motor);

int main () {


	Tanc::motor.init(78,47);

	char nume;
	char cmdSus, cmdJos, cmdStanga, cmdDreapta, cmdFoc;

	/*std::cout << "Introduceti simbolul primului tanc: ";
	std::cin >> nume; system ("cls");
	std::cout << "Introduceti comenzile de deplasare si de interactiune al primului tanc: " << std::endl;
	std::cout << "Stanga = "; cmdStanga = intrare.getc(); system ("cls");
	std::cout << "Dreapta = "; cmdDreapta = intrare.getc(); system ("cls");
	std::cout << "Sus = "; cmdSus = intrare.getc(); system ("cls");
	std::cout << "Jos = "; cmdJos = intrare.getc(); system ("cls");
	std::cout << "Foc = ";  cmdFoc = intrare.getc(); system ("cls");

	new Tanc (nume, cmdStanga, cmdDreapta, cmdSus, cmdJos, cmdFoc, 10, 10);*/


	/*std::cout << "Introduceti simbolul celui de-al doilea tanc: ";
	std::cin >> nume; system ("cls");
	std::cout << "Introduceti comenzile de deplasare si de interactiune al celui de-al doilea tanc: " << std::endl;
	std::cout << "Stanga = "; cmdStanga = intrare.getc(); system ("cls");
	std::cout << "Dreapta = "; cmdDreapta = intrare.getc(); system ("cls");
	std::cout << "Sus = "; cmdSus = intrare.getc(); system ("cls");
	std::cout << "Jos = "; cmdJos = intrare.getc(); system ("cls");
	std::cout << "Foc = "; cmdFoc = intrare.getc(); system ("cls");
	
	new Tanc (nume, cmdStanga, cmdDreapta, cmdSus, cmdJos, cmdFoc, 10, 11);*/
	
	
	//new Tanc ('X', 97, 100, 119, 115, 32, 10, 10);
    new Tanc ('X', 'a', 'd', 'w', 's', 32, 10, 10);
	new Tanc ('T', 107, 109, 104, 112, 48, 30, 10);
	
	int i;
	for (i = 10; i < 35; i++) new Zid (i,30);
	for (i = 20; i < 35; i++) new Zid (25,i);
	for (i = 30; i < 35; i++) new Zid (70,i);
	for (i = 50; i < 70; i++) new Zid (i, 35);
	for (i = 45; i < 60; i++) new Zid (i,5);
	for (i = 5; i < 20; i++) new Zid (55,i);
	
	new Zid(35,20);
	new Zid(35,21);
	new Zid(35,22);
	new Zid(36,20);
	new Zid(36,21);
	new Zid(36,22);
	new Zid(37,20);
	new Zid(38,21);
	new Zid(39,22);
	
	//new Zid (51,30);
	//new Zid (52,30);
	//new Zid (32,31);

	intrare.init(); 
	iesire.init();

	do {
		Tanc::cc = intrare.getc();
		Tanc::motor.next();
		//iesire.afisare();
		Sleep(3);
		
	} while (Tanc::cc != 27);

	intrare.close();
	iesire.close();
	
	return 0;
}


