#pragma once
#include "EnemyColl.h"


class EnemyHandler{


private:

	EnemyColl eColl;

public:

	EnemyHandler();
	void UpdateEnemies(std::vector<Bullet*>&, GameTimer&);
	void RenderEnemies();
	void AddEnemyToGame(Enemy*);
	std::vector<Enemy*>& GetEnemiesAsPointer();

};