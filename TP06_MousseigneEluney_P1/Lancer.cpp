#include "Lancer.h"
#include <algorithm>

Lancer::Lancer(int attackRadius, float health, float stamina) : MeleeSoldier(attackRadius, health, stamina)
{
	this->attackRadius = attackRadius;
	this->health = health;
	this->stamina = stamina;
}

Lancer::~Lancer()
{
}

void Lancer::attack(Soldier* target, int targetIdx, std::vector<Soldier*>& squad)
{
	if (this == target)
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
		std::cout << "Lancer (Ind: " << index << ") attacks towards " << targetIdx << "!\n";

		int start = std::min(index, targetIdx) + 1;
		int end = std::max(index, targetIdx);

		bool hitSomeone = false;
		for (int i = start; i <= end; i++)
		{
			if (squad[i]->getHealth() > 0)
			{
				std::cout << " -> Skewered Soldier " << i << "!\n";
				squad[i]->removeHealth(15);
				hitSomeone = true;
			}
		}

		if (!hitSomeone)
		{
			std::cout << " -> But nobody was there.\n";
		}

		removeStamina(10);
	}
	else
	{
		std::cout << "Lancer missed (Too far)!\n";
		removeStamina(5);
	}
}