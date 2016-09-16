#include "unit.h"
#include "engine.h"
#include <cstddef>
#include <iostream>

Engine Unit::motor;

void Unit::react () {
	for (int i = 0; i < m_nm; i++) {
		if (m_alive)
			behaviour(m_message[i]);
	}
	m_nm = 0;
}

Unit::Unit (int x, int y) {
	if ((motor.m_nu == MAXNU - 1) || (motor.m_unitTab[x][y] != NULL))
		return;
	
	m_x = x;
	m_y = y;
	m_nm = 0;
	m_alive = 1;
	
	motor.m_unitVect[motor.m_nu++] = this;
	motor.m_unitTab[m_x][m_y] = this;
}

Unit::~Unit () {}

void Unit::die () {
	m_alive = 0;
}

void Unit::move (int x, int y) {
	motor.m_unitTab[x][y] = this;
	motor.m_unitTab[m_x][m_y] = NULL;
	m_x = x ;
	m_y = y;
	//std::cout<<m_x<<' '<<m_y;
}

void Unit::sendMes (int pm, Unit &pu) {
	if (pu.m_nm < MAXNM) { 
		pu.m_message[pu.m_nm++] = pm;
	}
}

bool Unit::isAlive() {
	return (m_alive == 1);
}

int Unit::getx () {
	return m_x;
}

int Unit::gety () {
	return m_y;
}

