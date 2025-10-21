
#pragma once
#include "RangedSoldier.h"

class Lancer : public RangedSoldier
{
private:

public:
	Lancer(int minAttackDistance, int maxAttackDistance, float health, float stamina);
	~Lancer();

	void attack(Soldier* targets, int index) override;
};

