#include "Schedule.h"

Schedule::Schedule(vector<Enemy*>& enemyVectors){


	enemyVectors.push_back(new Enemy((Graphics::SCREEN_WIDTH/4),0,0,100, 5));
	enemyVectors.push_back(new SpiralEnemy((Graphics::SCREEN_WIDTH/2),0,0,100, 8));

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