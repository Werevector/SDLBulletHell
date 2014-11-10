#pragma once
#include <vector>
#include "Enemy.h"


class EnemyHandler{


private:

public:
	std::vector<Enemy*> enemyVectors;
	
	EnemyHandler();
	void UpdateEnemies(std::vector<Bullet*>&, GameTimer&);
	void RenderEnemies();
	void AddEnemyToGame(Enemy*);
	std::vector<Enemy*>& GetEnemiesAsPointer();

	

};