#include "Schedule.h"

Schedule::Schedule(){

	//enemyVectors.push_back(new Enemy((Graphics::SCREEN_WIDTH/4),0,0,100, 2));
	//enemyVectors.push_back(new SpiralEnemy((Graphics::SCREEN_WIDTH/4),0,0,400, 2);


	


}

void Schedule::AddEnemiesToGame(vector<Enemy*>& enemyVectors){

	enemyVectors.push_back(new Enemy((Graphics::SCREEN_WIDTH/1.5),0,0,400, 2));
	enemyVectors.push_back(new Enemy((Graphics::SCREEN_WIDTH/4),0,0,400, 4));
	enemyVectors.push_back(new Enemy((Graphics::SCREEN_WIDTH/2),0,0,400, 5));
	//enemyVectors.push_back(new SpiralEnemy((Graphics::SCREEN_WIDTH/2),0,0,400, 1));
	//enemyVectors.push_back(new SpiralEnemy((Graphics::SCREEN_WIDTH/1.5),0,0,400, 6));
	/*enemyVectors.push_back(new SpiralEnemy((Graphics::SCREEN_WIDTH/6),0,0,400, 6));
	enemyVectors.push_back(new SpiralEnemy((Graphics::SCREEN_WIDTH/4),0,0,400, 6));*/

}

void Schedule::checkSpawn(float sTime, vector<Enemy*>& Enemies ){
	

	for(int i = 0; i < Enemies.size(); i++){
		
		if(sTime > Enemies[i]->whenToSpawn){
			Enemies[i]->Spawn(sTime);
		}
		
		if(Enemies[i]->GetEnemyCenterX() > Graphics::SCREEN_WIDTH ||
			Enemies[i]->GetEnemyCenterY() > Graphics::SCREEN_HEIGHT){
				Enemies[i]->Despawn();
		}
	}

}

//bool Schedule::checkTime(float sTime){
//	
//}