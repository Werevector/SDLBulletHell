#pragma once
#include "GameTimer.h"
#include "Enemy.h"
#include "SpiralEnemy.h"
#include <vector>

using namespace std;

class Schedule{

public:

	Schedule(vector<Enemy*>& enemyVectors);
	void checkSpawn(float, vector<Enemy*>&);

	bool checkTime(float);

private:
	GameTimer sTimer;

};