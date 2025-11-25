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

void Soldier::rest()
{
	stamina += 15; 
	std::cout << "Soldier " << index << " is resting.\n";
}

int Soldier::getIndex()
{
	return index;
}
