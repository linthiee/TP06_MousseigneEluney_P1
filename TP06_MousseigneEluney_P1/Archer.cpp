#include "Archer.h"

Archer::Archer() : RangedSoldier(minAttackDistance, maxAttackDistance, health, stamina)
{
}

Archer::~Archer()
{
}

void Archer::attack(Soldier* objective)
{
}
