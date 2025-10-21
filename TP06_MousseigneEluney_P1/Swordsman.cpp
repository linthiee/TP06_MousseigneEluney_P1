#include "Swordsman.h"

Swordsman::Swordsman(int attackRadius, float health, float stamina) : MeleeSoldier(attackRadius, health, stamina)
{
	this->attackRadius = attackRadius;
	this->health = health;
	this->stamina = stamina;
}

Swordsman::~Swordsman()
{
}

void Swordsman::attack(Soldier* targets, int index)
{
	if (targets->getHealth() > 0 && getIndex() != targets->getIndex())
	{
		index *= defaultDistance;
		if (index == 0)
		{
			index = defaultDistance;
		}

		if (attackRadius <= index)
		{
			std::cout << "The swordsman attacked!\n";

			targets->removeHealth(30);
		}

		removeStamina(15);
	}
}
