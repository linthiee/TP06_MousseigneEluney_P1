#include "GameLoop.h"
#include <iostream>
#include <vector>
#include <cmath> 

static int soldierSize = 10;

static int maxAttackRange = 60;
static int minAttackRange = 10;

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
	for (int i = 0; i < soldiers.size(); i++)
	{
		delete soldiers[i];
	}

	soldiers.clear();
}

void GameLoop::play()
{
	setRandomPlayers();

	int turn = 1;
	while (countAlive() > 1)
	{
		std::cout << "\n--- Turn " << turn << " ---\n";
		update();
		turn++;
	}

	announceWinner();
}

void GameLoop::setRandomPlayers()
{
	for (int i = 0; i < soldierSize; i++)
	{
		int type = rand() % 4;

		int rangeMin = minAttackRange;
		int rangeMax = rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange;

		switch (type)
		{
		case 0: 
			soldiers.push_back(new Swordsman(rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, 100.0f, 100.0f));
			break;

		case 1:
			soldiers.push_back(new Archer(rangeMin, rangeMax, 100.0f, 100.0f));
			break;

		case 2: 
			soldiers.push_back(new Lancer(rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, 100.0f, 100.0f));
			break;

		case 3: 
			soldiers.push_back(new Crossbowman(rangeMin, rangeMax, 100.0f, 100.0f));
			break;

		default:
			std::cout << "Failed to create a soldier\n";
			break;
		}
	};

	for (int i = 0; i < soldiers.size(); i++)
	{
		soldiers[i]->setIndex(i);
	}
}

void GameLoop::update()
{
	for (int i = 0; i < soldiers.size(); i++)
	{
		if (soldiers[i]->getHealth() <= 0)
		{
			continue;
		}

		std::vector<int> aliveEnemies;
		for (int j = 0; j < soldiers.size(); j++)
		{
			if (i != j && soldiers[j]->getHealth() > 0)
			{
				aliveEnemies.push_back(j);
			}
		}

		if (aliveEnemies.empty())
		{
			return;
		}

		bool canReachSomeone = false;
		for (int enemyIdx = 0; enemyIdx < aliveEnemies.size(); enemyIdx++)
		{
			int dist = std::abs(i - enemyIdx) * 10;
			if (soldiers[i]->canReach(dist))
			{
				canReachSomeone = true;
				break;
			}
		}

		int targetIdx = -1;

		if (canReachSomeone)
		{

			for (int k = 0; k < 20; k++) 
			{
				int randomPick = aliveEnemies[rand() % aliveEnemies.size()];
				int dist = std::abs(i - randomPick) * 10;

				if (soldiers[i]->canReach(dist)) 
				{
					targetIdx = randomPick;
					break;
				}
			}

			if (targetIdx == -1)
			{
				targetIdx = aliveEnemies[rand() % aliveEnemies.size()];
			}

			soldiers[i]->attack(soldiers[targetIdx], targetIdx, soldiers);
		}
		else
		{
			targetIdx = aliveEnemies[rand() % aliveEnemies.size()];

			std::cout << "Soldier " << i << " uses a desperate attack (Too far) on " << targetIdx << "!\n";

			soldiers[targetIdx]->removeHealth(15);
			soldiers[i]->removeStamina(10);
		}
	}
}

int GameLoop::countAlive()
{
	int count = 0;
	for (int i = 0; i < soldiers.size(); i++)
	{
		if (soldiers[i]->getHealth() > 0)
		{
			count++;
		}
	}
	return count;
}

void GameLoop::announceWinner()
{
	std::cout << "\n--- Game Over ---\n";

	int winnerIndex = -1;

	for (int i = 0; i < soldiers.size(); i++)
	{
		if (soldiers[i]->getHealth() > 0)
		{
			winnerIndex = i;
			break;
		}
	}

	if (winnerIndex != -1)
	{
		std::cout << "The winner is Soldier " << winnerIndex << "!\n";
	}
	else
	{
		std::cout << "Everyone died! It's a draw.\n";
	}
}