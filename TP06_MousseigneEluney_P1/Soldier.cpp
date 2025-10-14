#include "Soldier.h"

Soldier::Soldier(float health, float stamina)
{
	this->health = health;
	this->stamina = stamina;
}

Soldier::~Soldier()
{
}

void Soldier::attack(Soldier* objective)
{
	std::cout << "the NPC attacked!" << std::endl;
	stamina--;

	objective->health -= 10;
}

void Soldier::rest()
{
	std::cout << "The NPC is resting!" << std::endl;
	stamina++;

}
