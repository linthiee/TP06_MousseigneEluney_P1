#pragma once
#include <vector>
#include "Swordsman.h"
#include "Lancer.h"
#include "Crossbowman.h"
#include "Archer.h"

enum class SoldierType
{
	Swordsman, Lancer, Crossbowman, Archer
};

class GameLoop
{
private:

	std::vector<Soldier*> soldiers;

	void update();
	int countAlive();
	void announceWinner();

public:
	GameLoop();
	~GameLoop();

	void play();

	void setRandomPlayers();

};

