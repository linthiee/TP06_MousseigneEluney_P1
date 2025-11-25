
#pragma once
#include "MeleeSoldier.h"

class Lancer : public MeleeSoldier
{
private:

public:
	Lancer(int attackRadius, float health, float stamina);
	~Lancer();

	void attack(Soldier* target, int targetIdx, std::vector<Soldier*>& squad) override;
};

