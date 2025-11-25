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

void Swordsman::attack(Soldier* target, int targetIdx, std::vector<Soldier*>& squad)
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
		std::cout << "Swordsman (Ind: " << index << ") slashes target " << targetIdx << "!\n";
		target->removeHealth(30);
		removeStamina(10);
	}
	else
	{
		std::cout << "Swordsman missed (Too far)!\n";
		removeStamina(5);
	}
}