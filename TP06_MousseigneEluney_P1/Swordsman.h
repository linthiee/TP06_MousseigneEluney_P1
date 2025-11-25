#pragma once
#include "MeleeSoldier.h"

class Swordsman : public MeleeSoldier
{
private:

public:
	Swordsman(int attackRadius, float health, float stamina);
	~Swordsman();

	void attack(Soldier* target, int targetIdx, std::vector<Soldier*>& squad) override;
};
