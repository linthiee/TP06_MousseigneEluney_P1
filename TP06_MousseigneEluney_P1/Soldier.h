#pragma once
#include "Globals.h"
#include <iostream>

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

	virtual void attack(Soldier* targets, int index);
	virtual void rest();

};

