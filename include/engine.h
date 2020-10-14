#pragma once


#define MAXNC 100
#define MAXNL 100
#define MAXNU 10000
#define MAXGAMES 5

class Unit;

class Engine {

private:
	Unit *m_unitTab[MAXNC][MAXNL];
	Unit *m_unitVect[MAXNU];
	int m_nc, m_nl, m_nu;
	
	int gameNr;

public:
	void init (int nc, int nl);

	int getnl ();
	int getnc ();
	int getnu ();

	bool validxy (int x, int y);
	bool validPoz (int n);

	Unit *getUnitxy (int x, int y);
	Unit *getUnitPoz (int n);
	void next ();

	friend class Unit;
};
