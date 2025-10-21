#pragma once
#include "Soldier.h"

class MeleeSoldier : public Soldier
{
protected:

	int attackRadius;

public:

	MeleeSoldier(int attackRadius, float health, float stamina);
	virtual ~MeleeSoldier();

	void attack(Soldier* targets, int index) override;
	void rest() override;
};

