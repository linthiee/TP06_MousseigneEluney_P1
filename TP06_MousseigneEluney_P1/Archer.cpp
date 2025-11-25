#include "Archer.h"

Archer::Archer(int minAttackDistance, int maxAttackDistance, float health, float stamina) : RangedSoldier(minAttackDistance, maxAttackDistance, health, stamina)
{
	this->minAttackDistance = minAttackDistance;
	this->maxAttackDistance = maxAttackDistance;
	this->health = health;
	this->stamina = stamina;
}

Archer::~Archer()
{
}

void Archer::attack(Soldier* target, int targetIdx, std::vector<Soldier*>& squad)
{
	if (this == target)
	{
		return;
	}

	if (target->getHealth() <= 0)
	{
		return;
	}

	if (stamina < 10)
	{
		rest(); 
		return;
	}

	int distance = std::abs(index - targetIdx) * 10;

	if (canReach(distance))
	{
		std::cout << "Archer (Ind: " << index << ") shoots " << targetIdx << "!\n";
		target->removeHealth(25);
		removeStamina(10);
	}
	else
	{
		std::cout << "Archer missed (Range mismatch)!\n";
		removeStamina(5);
	}
}
