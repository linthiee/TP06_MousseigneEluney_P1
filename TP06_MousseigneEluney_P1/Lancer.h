#pragma once
#include "RangedSoldier.h"

class Lancer : public RangedSoldier
{
private:

public:
	Lancer();
	~Lancer();

	void attack(Soldier* objective) override;
};

