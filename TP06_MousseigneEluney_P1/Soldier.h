#pragma once
#include <iostream>

class Soldier
{
protected:

	float health;
	float stamina;

public:

	Soldier(float health, float stamina);
	virtual ~Soldier();

	virtual void attack(Soldier* objective);
	virtual void rest();

};

