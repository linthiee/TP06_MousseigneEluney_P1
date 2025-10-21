#include "Lancer.h"

Lancer::Lancer(int minAttackDistance, int maxAttackDistance, float health, float stamina) : RangedSoldier(minAttackDistance, maxAttackDistance, health, stamina)
{
	this->minAttackDistance = minAttackDistance;
	this->maxAttackDistance = maxAttackDistance;
	this->health = health;
	this->stamina = stamina;
}

Lancer::~Lancer()
{
}

void Lancer::attack(Soldier* targets, int index)
{
	if (targets->getHealth() > 0 && getIndex() != targets->getIndex())
	{
		if (index < getIndex())
		{
			for (int i = 0; i < targets->getIndex(); i++)
			{
				targets->removeHealth(10);

				removeStamina(5);

				std::cout << "The lancer attacked the enemy standing at " << i * defaultDistance << " meters!\n";
			}
		}

		if (index > getIndex())
		{
			for (int i = targets->getIndex(); i > index; i--)
			{
				targets->removeHealth(10);

				removeStamina(5);

				std::cout << "The lancer attacked the enemy standing at " << i * defaultDistance << " meters!\n";
			}
		}
	}

}
