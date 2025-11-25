#pragma once
#include "Soldier.h"

class MeleeSoldier : public Soldier
{
protected:

	int attackRadius;

public:

	MeleeSoldier(int attackRadius, float health, float stamina);
	virtual ~MeleeSoldier();

	bool canReach(int distance) override;
};

