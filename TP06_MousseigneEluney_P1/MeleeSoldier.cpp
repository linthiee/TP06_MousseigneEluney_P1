#include "MeleeSoldier.h"

MeleeSoldier::MeleeSoldier(int attackRadius, float health, float stamina) : Soldier(health, stamina)
{
}

MeleeSoldier::~MeleeSoldier()
{
}

bool MeleeSoldier::canReach(int distance)
{
	return distance <= attackRadius;
}

