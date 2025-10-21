#pragma once
#include "RangedSoldier.h"

class Archer : public RangedSoldier
{
private:

public:
	Archer(int minAttackDistance, int maxAttackDistance, float health, float stamina);
	~Archer();

	void attack(Soldier* targets, int index) override;

};

