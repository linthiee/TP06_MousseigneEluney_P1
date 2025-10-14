#pragma once
#include "RangedSoldier.h"

class Crossbowman : public RangedSoldier
{
private:

public:
	Crossbowman();
	~Crossbowman();

	void attack(Soldier* objective) override;
};

