#pragma once
#include "Soldier.h"

class MeleeSoldier : public Soldier
{
protected:

	int attackRadius;

public:

	MeleeSoldier(int attackRadius, float health, float stamina);
	virtual ~MeleeSoldier();

	void attack(Soldier* objective) override;
	void rest() override;
};

