#include "RangedSoldier.h"

RangedSoldier::RangedSoldier(int minAttackDistance, int maxAttackDistance, float health, float stamina) : Soldier(health, stamina)
{
}

RangedSoldier::~RangedSoldier()
{
}

bool RangedSoldier::canReach(int distance)
{
	return distance >= minAttackDistance && distance <= maxAttackDistance;
}

