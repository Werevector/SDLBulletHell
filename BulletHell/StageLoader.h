#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Enemy.h"
#include "SpiralEnemy.h"
#include "SpreadEnemy.h"
#include <fstream>
#include <sstream>

//#define SpiralEnemy(x,y,Vy,Vx,t) enemyVector.push_back(new SpiralEnemy(x,y,Vy,Vx,t));
//#define SpreadEnemy(x,y,Vy,Vx,t) enemyVector.push_back(new SpreadEnemy(x,y,Vy,Vx,t));

#define SpiralEnemyCode 000
#define SpreadEnemyCode 001

using namespace std;

class StageLoader{

public:
	
	static void loadEnemiesFromStage(string fileName, vector<Enemy*>& enemyVector);

private:

	/*void InterpLine(string line);*/

};