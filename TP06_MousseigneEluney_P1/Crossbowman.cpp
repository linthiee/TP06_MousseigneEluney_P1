#include "Crossbowman.h"

Crossbowman::Crossbowman() : RangedSoldier(minAttackDistance, maxAttackDistance, health, stamina)
{
}

Crossbowman::~Crossbowman()
{
}

void Crossbowman::attack(Soldier* objective)
{
}
