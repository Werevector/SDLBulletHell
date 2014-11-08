#include "EnemyColl.h"

std::vector<Enemy*> EnemyColl::GetEnemies(){
	return enemyVectors;
}

std::vector<Enemy*>& EnemyColl::GetEnemiesAsPointer(){
	return enemyVectors;
}

void EnemyColl::addEnemy(Enemy*){

}