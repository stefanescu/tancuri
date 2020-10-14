#include "engine.h"
#include "unit.h"
#include <cstddef>

void Engine::init (int nc, int nl) {
	gameNr = 0;
	m_nc = nc;
	m_nl = nl;

	int i, j;
	for (i = 0; i < MAXNC; i++) {
		for (j = 0; j < MAXNL; j++) {
			m_unitTab[i][j] = NULL;
		}
	}

	for (i = 0; i < MAXNU; i++) {
		m_unitVect[i] = NULL;
	}

}

int Engine::getnl () {
	return m_nl;
}

int Engine::getnc () {
	return m_nc;
}

int Engine::getnu () {
	return m_nu;
}

bool Engine::validxy (int x, int y) {
	return ((x >= 0 && x < m_nc - 1) && (y >= 0 && y < m_nl - 1));
}

bool Engine::validPoz (int n) {
	return (n >= 0 && n <= m_nu - 1);
}

Unit *Engine::getUnitxy (int x, int y) {
	return m_unitTab[x][y];
}

Unit *Engine::getUnitPoz (int n) {
	return m_unitVect[n];
}

void Engine::next () {
	int i;
	for (i = 0; i < m_nu; i++) {
		m_unitVect[i]->action();
	}

	for (i = 0; i < m_nu; i++) {
		m_unitVect[i]->react();
	}

		
	for (i = 0; i < m_nu; i++) {
		if (m_unitVect[i] != NULL && !m_unitVect[i]->isAlive()) {
			//gameNr++;
			int x = m_unitVect[i]->getx();
			int y = m_unitVect[i]->gety();

			m_unitTab[x][y] = NULL;
			delete m_unitVect[i];
			m_unitVect[i] = m_unitVect[m_nu-1];
			m_unitVect[m_nu-1] = NULL;
			i--;
			m_nu--;
		}
	}

}


