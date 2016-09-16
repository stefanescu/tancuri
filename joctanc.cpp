#include "joctanc.h"
#include "unit.h"
#include "engine.h"
#include <cstddef>
#include <windows.h>

enum Mesaj {
    KILL = 1
};

 unsigned char Zid::nume = 177;

void Zid::action () {
}

void Zid::behaviour (int pm) {
}

Zid::Zid (int x, int y) : Unit(x, y) {
}

void *Zid::getTip () {
    return &nume;
}


unsigned char Bomba::nume = '.';

void Bomba::action () {
	if (isAlive()) {

		int xn = getx() + m_dirx;
		int yn = gety() + m_diry;

		if (!motor.validxy(xn, yn) && m_diry == -1)
			die();
		else if (!motor.validxy(xn, yn + 1) && m_diry == 1)
			die();
		else if (!motor.validxy(xn, yn) && m_dirx == -1)
			die();
		else if (!motor.validxy(xn + 1, yn) && m_dirx == 1)
			die();
		else if (motor.getUnitxy(xn,yn) == NULL)
			move(xn, yn);
		else if (motor.getUnitxy(xn,yn) != NULL) {
			sendMes(KILL, *(motor.getUnitxy(xn,yn)));
			die();
		}
	}
	//Sleep(3);
}

void Bomba::behaviour (int pm) {
    if (pm == KILL)
        die();
}

Bomba::Bomba (int x, int y, int dirx, int diry) : Unit(x, y),
m_dirx(dirx), m_diry(diry) {
}

void *Bomba::getTip () {
    return &nume;
}


char Tanc::cc = 0;

//******************************************************
void Tanc::action () {
    if ((cc == m_stg) || (cc == m_dr) || (cc == m_sus)
    || (cc == m_jos) || (cc == m_foc)) {

		int bx = getx(), by = gety(), dirx = 0, diry = 0;

		if ((cc == m_stg) && (motor.validxy(getx() - 1, gety())) && (motor.getUnitxy(getx() - 1, gety()) == NULL)) {
			move(getx() - 1, gety());
			pc = cc;
		}

		else if ((cc == m_dr) && (motor.validxy(getx() + 2, gety())) && (motor.getUnitxy(getx() + 1, gety()) == NULL)) {
			move(getx() + 1, gety());
			pc = cc;
		}

		else if ((cc == m_sus) && (motor.validxy(getx(), gety() - 1)) && (motor.getUnitxy(getx(), gety() - 1) == NULL)) {
			move(getx(), gety() - 1);
			pc = cc;
		}

		else if ((cc == m_jos) && (motor.validxy(getx(), gety() + 2)) && (motor.getUnitxy(getx(), gety()  + 1) == NULL)) {
			move(getx(), gety() + 1);
			pc = cc;
		}

		else if (cc == m_foc) {
			if (pc == m_stg) {
				bx--;
				dirx = -1;
			}

			else if (pc == m_dr) {
				bx++;
				dirx = 1;
			}

			else if (pc == m_sus) {
				by--;
				diry = -1;
			}

			else if (pc == m_jos) {
				by++;
				diry = 1;
			}

			if (motor.validxy(bx,by)) {
				if (motor.getUnitxy(bx, by) == NULL) 
					new Bomba(bx, by, dirx, diry);
				
				else
					sendMes(KILL, *(motor.getUnitxy(bx, by)));
			}

		}
	}
}
//*******************************************************

void Tanc::behaviour (int pm) {
	if (pm == KILL)
		die();
}

Tanc::Tanc (char nume, char stg, char dr, char sus, char jos, char foc, int x, int y) :
Unit(x, y), m_nume(nume), m_stg(stg), m_dr(dr), m_sus(sus), m_jos(jos), m_foc(foc) {
}

void *Tanc::getTip () {
	return &m_nume;
}

