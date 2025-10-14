#pragma once
#include "MeleeSoldier.h"

class Swordsman : public MeleeSoldier
{
private:

public:
	Swordsman();
	~Swordsman();

	 void attack(Soldier* objective) override;

};
