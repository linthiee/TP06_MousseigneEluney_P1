#pragma once
#include "Globals.h"
#include <iostream>
#include <vector>

class Soldier
{
protected:

	float health;
	float stamina;

	int index;

public:

	Soldier(float health, float stamina);
	virtual ~Soldier();

	float getHealth();
	void setHealth(float health);
	void removeHealth(float damage);

	float getStamina();
	void setStamina(float stamina);
	void removeStamina(float drain);

	void setIndex(int index);
	int getIndex();

	virtual void rest();

	virtual void attack(Soldier* target, int targetIdx, std::vector<Soldier*>& squad) = 0;
	virtual bool canReach(int distance) = 0;
};

