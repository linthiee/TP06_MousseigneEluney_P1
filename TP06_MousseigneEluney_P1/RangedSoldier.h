#pragma once
#include "Soldier.h"

class RangedSoldier : public Soldier
{
protected:

	int minAttackDistance;
	int maxAttackDistance;

public:

	RangedSoldier(int minAttackDistance, int maxAttackDistance, float health, float stamina);
	virtual ~RangedSoldier();

	 void attack(Soldier* targets, int index) override;
	 void rest() override;
};
