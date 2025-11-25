#pragma once
#include "RangedSoldier.h"

class Crossbowman : public RangedSoldier
{
private:

public:
	Crossbowman(int minAttackDistance, int maxAttackDistance, float health, float stamina);
	~Crossbowman();

	void attack(Soldier* target, int targetIdx, std::vector<Soldier*>& squad) override;
};

