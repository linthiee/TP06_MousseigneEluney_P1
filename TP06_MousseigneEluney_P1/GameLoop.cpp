#include "GameLoop.h"

static int soldierSize = 10;

static int maxAttackRange = 20;
static int minAttackRange = 5;

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::play()
{
	setRandomPlayers();
	update();
}

void GameLoop::setRandomPlayers()
{
	for (int i = 0; i < soldierSize; i++)
	{
		switch ((SoldierType)(rand() % (static_cast<int>(SoldierType::Archer) - static_cast<int>(SoldierType::Swordsman) + 1) + static_cast<int>(SoldierType::Swordsman)))
		{
		case SoldierType::Swordsman:

			soldiers.push_back(new Swordsman(rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, 100.0f, 100.0f));

			break;
		case SoldierType::Archer:

			soldiers.push_back(new Archer(rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, 100.0f, 100.0f));

			break;
		case SoldierType::Lancer:

			soldiers.push_back(new Lancer(rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, 100.0f, 100.0f));

			break;
		case SoldierType::Crossbowman:

			soldiers.push_back(new Crossbowman(rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, rand() % (maxAttackRange - minAttackRange + 1) + minAttackRange, 100.0f, 100.0f));

			break;
		default:

			std::cout << "Failed to create a soldier\n";
			break;
		}
	};

	for (int i = 0; i < soldierSize; i++)
	{
		soldiers[i]->setIndex(i);
	}
}

void GameLoop::update()
{
	for (int i = 0; i < soldierSize; i++)
	{
		int randomIdx = rand() % (soldierSize);

		soldiers[i]->attack(soldiers[randomIdx], randomIdx);

		std::cout << "Soldier " << i << " attacked " << randomIdx << std::endl;
	}
}
