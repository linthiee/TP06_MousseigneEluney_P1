#include "Crossbowman.h"

static int maxBullets = 2;

static int maxChance = 101;
static float chance = 0;

Crossbowman::Crossbowman(int minAttackDistance, int maxAttackDistance, float health, float stamina) : RangedSoldier(minAttackDistance, maxAttackDistance, health, stamina)
{
	this->minAttackDistance = minAttackDistance;
	this->maxAttackDistance = maxAttackDistance;
	this->health = health;
	this->stamina = stamina;
}

Crossbowman::~Crossbowman()
{
}

void Crossbowman::attack(Soldier* target, int targetIdx, std::vector<Soldier*>& squad)
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
		std::cout << "Crossbowman (Ind: " << index << ") double-taps " << targetIdx << "!\n";

		if ((rand() % 100) < 60)
		{
			target->removeHealth(15);
			std::cout << " -> Hit 1!\n";
		}
		else std::cout << " -> Miss 1.\n";

		if (target->getHealth() > 0)
		{
			if ((rand() % 100) < 60)
			{
				target->removeHealth(15);
				std::cout << " -> Hit 2!\n";
			}
			else std::cout << " -> Miss 2.\n";
		}

		removeStamina(10);
	}
	else
	{
		std::cout << "Crossbowman missed (Range mismatch)!\n";
		removeStamina(5);
	}
}