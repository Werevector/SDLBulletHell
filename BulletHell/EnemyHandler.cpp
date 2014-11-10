#include "Enemyhandler.h"

EnemyHandler::EnemyHandler(){

}

void EnemyHandler::RenderEnemies(){
	
	for(int i = 0; i < enemyVectors.size(); i++){
		enemyVectors[i]->Draw();
	}

}

void EnemyHandler::UpdateEnemies(std::vector<Bullet*>& bulletVectors, GameTimer& gTimer){

	for(int i = 0; i < enemyVectors.size(); i++){
			enemyVectors[i]->Update(bulletVectors, gTimer);
	}
	for(int i = 0; i < enemyVectors.size(); i++){
		if(enemyVectors[i]->IsDead()){
			enemyVectors.erase(enemyVectors.begin() + i);
		}
	}	

}

void EnemyHandler::AddEnemyToGame(Enemy* e){
	
}

std::vector<Enemy*>& EnemyHandler::GetEnemiesAsPointer(){
	return enemyVectors;
}