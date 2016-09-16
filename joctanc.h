#pragma once

#include "unit.h"
#include "engine.h"


class Zid : public Unit {

private:
	static unsigned char nume;

protected:
	virtual void action ();
	virtual void behaviour (int pm);

public:
	Zid (int x, int y);

	virtual void *getTip ();
	
	friend class Engine;
};


class Bomba : public Unit {

private:
	static unsigned char nume;
	int m_dirx, m_diry;// POT FI {-1, 0, 1}

protected:
	virtual void action ();
	virtual void behaviour (int pm);

public:
	Bomba (int x, int y, int dirx, int diry);
        
	void *getTip ();

	friend class Engine;
};


class Tanc : public Unit {

public:
	static char cc;

private:
	unsigned char m_nume;
	char m_stg, m_dr, m_sus, m_jos, m_foc;
	char pc;

protected:
	virtual void action ();
	virtual void behaviour (int pm);

public:
	Tanc (char nume, char stg, char dr, char sus, char jos, char foc, int x, int y);

	void *getTip ();

	friend class Engine;   
};
