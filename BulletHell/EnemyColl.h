#pragma once
#include <vector>
#include "Enemy.h"

class EnemyColl{

private:

	std::vector<Enemy*> enemyVectors;

public:

	std::vector<Enemy*> GetEnemies();
	std::vector<Enemy*>& GetEnemiesAsPointer();
	void addEnemy(Enemy*);

};