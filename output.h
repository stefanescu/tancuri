#pragma once

#include "engine.h"

class Output {

private:
	Engine &motor;

public:
	Output (Engine &pm);

	void init ();
	void close ();

	void afisare ();
};
