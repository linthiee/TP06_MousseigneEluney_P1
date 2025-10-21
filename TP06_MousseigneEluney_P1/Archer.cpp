#include "Archer.h"

Archer::Archer(int minAttackDistance, int maxAttackDistance, float health, float stamina) : RangedSoldier(minAttackDistance, maxAttackDistance, health, stamina)
{
	this->maxAttackDistance = minAttackDistance;
	this->maxAttackDistance = maxAttackDistance;
	this->health = health;
	this->stamina = stamina;
}

Archer::~Archer()
{
}

void Archer::attack(Soldier* targets, int index)
{
	if (targets->getHealth() > 0 && getIndex() != targets->getIndex())
	{
		index *= defaultDistance;
		if (index == 0)
		{
			index = defaultDistance;
		}

		if (minAttackDistance >= index && maxAttackDistance <= index)
		{
			std::cout << "The archer attacked!\n";

			targets->removeHealth(25);
		}

		removeStamina(10);
	}
}
