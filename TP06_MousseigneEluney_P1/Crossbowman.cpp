#include "Crossbowman.h"

static int maxBullets = 2;

static int maxChance = 101;
static float chance = 0;

Crossbowman::Crossbowman(int minAttackDistance, int maxAttackDistance, float health, float stamina) : RangedSoldier(minAttackDistance, maxAttackDistance, health, stamina)
{
	this->maxAttackDistance = minAttackDistance;
	this->maxAttackDistance = maxAttackDistance;
	this->health = health;
	this->stamina = stamina;
}

Crossbowman::~Crossbowman()
{
}

void Crossbowman::attack(Soldier* targets, int index)
{
	if (targets->getHealth() > 0 && getIndex() != targets->getIndex())
	{
		for (int i = 0; i < maxBullets; i++)
		{
			chance = rand() % (maxChance) + 1;

			if (chance >= maxChance / 2)
			{
				targets->removeHealth(10);

				removeStamina(10);

				std::cout << "The crosbowwman attacked the enemy!\n";
			}
			else
			{
				std::cout << "The crosbowwman failed to attack!\n";
			}
		}
	}
}
