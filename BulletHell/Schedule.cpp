#include "Schedule.h"

Schedule::Schedule(std::vector<Enemy>& enemyVectors){

	/*for(int i=0; i<5; i++){
		Enemy e1(10,0,0,0.05, 6000);
		enemyVectors.push_back(e1);
	}*/
	Enemy e1(10,0,0,0.05, 10);
	Enemy e2(100,0,0,0.05, 5);
	Enemy e3(400,0,0,0.05, 2);
	Enemy e4(0,50, 0.1, 0, 3);
	Enemy e5(0,50, 0.1, 0, 3.5);
	Enemy e6(0,50, 0.1, 0, 4);
	Enemy e7(0,50, 0.1, 0, 4.5);

	/*Enemy e0(400,400,0,0,0.5);
	enemyVectors.push_back(e0);*/

	enemyVectors.push_back(e1);
	enemyVectors.push_back(e2);
	enemyVectors.push_back(e3);
	enemyVectors.push_back(e4);
	enemyVectors.push_back(e5);
	enemyVectors.push_back(e6);
	enemyVectors.push_back(e7);

}

void Schedule::checkSpawn(float sTime, std::vector<Enemy>& Enemies ){
	

	for(int i = 0; i < Enemies.size(); i++){
		
		if(sTime > Enemies[i].spawnTimeSec){
			Enemies[i].spawn();
		}
		
		if(Enemies[i].GetEnemyCenterX() > Graphics::SCREEN_WIDTH ||
			Enemies[i].GetEnemyCenterY() > Graphics::SCREEN_HEIGHT){
				Enemies[i].despawn();
		}
	
	}

}

//bool Schedule::checkTime(float sTime){
//	
//}