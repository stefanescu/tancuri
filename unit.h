#pragma once

#include "engine.h"

#define MAXNM 10


class Unit {

private:
	int m_alive;
	int m_x, m_y, m_poz;
	int m_message[MAXNM];
	int m_nm;

	void react ();

protected:
	Unit (int x, int y);
	virtual ~Unit ();

	void die ();
	void move (int x, int y);
	void sendMes (int pm, Unit &pu);
	virtual void action () = 0;
	virtual void behaviour (int pm) = 0;
	
	void checkNextMatch ();


public:
	static Engine motor;

	bool isAlive();
	int getx ();
	int gety ();
	virtual void *getTip () = 0;

	friend class Engine;
};
