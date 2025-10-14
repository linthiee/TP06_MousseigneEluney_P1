#pragma once
#include "RangedSoldier.h"

class Archer : public RangedSoldier
{
private:

public:
	Archer();
	~Archer();

	void attack(Soldier* objective) override;

};

