#pragma once
#include "MeleeSoldier.h"

class Swordsman : public MeleeSoldier
{
private:

public:
	Swordsman(int attackRadius, float health, float stamina);
	~Swordsman();

	 void attack(Soldier* targets, int index) override;

};
