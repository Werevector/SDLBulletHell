#pragma once
#include "GameTimer.h"
#include "Enemy.h"
#include "SpiralEnemy.h"
#include <vector>
#include "PhEnemy.h"

using namespace std;

class Schedule{

public:

	Schedule();
	void AddEnemiesToGame(vector<Enemy*>&);
	void checkSpawn(float, vector<Enemy*>&);

private:
	
	GameTimer sTimer;
	std::vector<Enemy*> enemiesList;
	int Iteration;

};