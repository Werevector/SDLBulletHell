#include "Schedule.h"

Schedule::Schedule(){

	Iteration = 0;

	


}

void Schedule::AddEnemiesToGame(vector<Enemy*>& enemyVectors){
	//Add enemies to an iterated spawn list
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4),0,0,400, 1));
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/1.5),0,0,400, 1));

	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4),0,0,400, 5));
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4.5),0,0,400, 5));
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4),0,0,400, 5.5));
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4.5),0,0,400, 5.5));
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4),0,0,400, 6));
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4.5),0,0,400, 6));
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4),0,0,400, 6.5));
	enemiesList.push_back(new Enemy((Graphics::SCREEN_WIDTH/4.5),0,0,400, 6.5));

	

}

void Schedule::checkSpawn(float sTime, vector<Enemy*>& Enemies ){
	//Checks the current iteration in the spawning list
	if(Iteration < enemiesList.size()){
		if(sTime > enemiesList[Iteration]->whenToSpawn){
			Enemies.push_back(enemiesList[Iteration]);
			Iteration++;
		}
	}

	//Checking for time to spawn, might be redundant.
	//Also checks despawn, could be reworked.
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
