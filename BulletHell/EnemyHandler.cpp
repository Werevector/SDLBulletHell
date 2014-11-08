#include "Enemyhandler.h"

EnemyHandler::EnemyHandler(){

}

void EnemyHandler::RenderEnemies(){
	std::vector<Enemy*> enemyVectors = eColl.GetEnemies();
	
	for(int i = 0; i < enemyVectors.size(); i++){
		enemyVectors[i]->Draw();
	}

}

void EnemyHandler::UpdateEnemies(std::vector<Bullet*>& bulletVectors, GameTimer& gTimer){
	std::vector<Enemy*> enemyVectors = eColl.GetEnemies();

	for(int i = 0; i < enemyVectors.size(); i++){
			enemyVectors[i]->Update(bulletVectors, gTimer);
	}
}

void EnemyHandler::AddEnemyToGame(Enemy* e){
	eColl.addEnemy(e);
}

std::vector<Enemy*>& EnemyHandler::GetEnemiesAsPointer(){
	return eColl.GetEnemiesAsPointer();
}