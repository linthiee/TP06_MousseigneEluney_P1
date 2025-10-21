#include "Soldier.h"

Soldier::Soldier(float health, float stamina)
{
	this->health = health;
	this->stamina = stamina;
}

Soldier::~Soldier()
{
}

float Soldier::getHealth()
{
	return health;
}

void Soldier::setHealth(float health)
{
	this->health = health;
}

void Soldier::removeHealth(float damage)
{
	health -= damage;
}

float Soldier::getStamina()
{
	return stamina;
}

void Soldier::setStamina(float stamina)
{
	this->stamina = stamina;
}

void Soldier::removeStamina(float drain)
{
	stamina -= drain;
}

void Soldier::setIndex(int index)
{
	this->index = index;
}

int Soldier::getIndex()
{
	return index;
}

void Soldier::attack(Soldier* targets, int index)
{
	if (targets->getHealth() > 0)
	{
		std::cout << "the NPC attacked!" << std::endl;

		removeStamina(10);

		targets->removeHealth(20);
	}
	else
	{
		targets->setHealth(0);
	}
}

void Soldier::rest()
{
	std::cout << "The NPC is resting!" << std::endl;
	stamina++;

}
