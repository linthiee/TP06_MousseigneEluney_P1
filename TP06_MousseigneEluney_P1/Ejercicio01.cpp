/* Crear una clase base abstracta para representar a un soldado, la cual maneje los
siguientes datos y funcionalidades:
? Cantidad de vida.
? Cantidad de stamina.
? Atacar a otros personajes.
? Descansar.*/
#include <ctime>
#include <iostream>
#include "GameLoop.h"

static int size = 10;

void main()
{
	srand(time(nullptr));
	GameLoop* gameloop = new GameLoop();

	gameloop->play();

	delete gameloop;
}