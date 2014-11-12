#include "Schedule.h"

Schedule::Schedule(){

	Iteration = 0;

	


}

void Schedule::AddEnemiesToGame(vector<Enemy*>& enemyVectors){

	enemiesList.push_back(new SpiralEnemy((Graphics::SCREEN_WIDTH/4),0,0,400, 1));
	enemiesList.push_back(new SpiralEnemy((Graphics::SCREEN_WIDTH/1.5),0,0,400, 2));

	

}

void Schedule::checkSpawn(float sTime, vector<Enemy*>& Enemies ){
	if(Iteration < enemiesList.size()){
		if(sTime > enemiesList[Iteration]->whenToSpawn){
			Enemies.push_back(enemiesList[Iteration]);
			Iteration++;
		}
	}

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