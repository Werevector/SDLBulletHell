#include "PhEnemy.h"

PhEnemy::PhEnemy(int x, int y, float vX, float vY, float spawnTime) : Enemy(x,y,vX,vY,spawnTime){

}

void PhEnemy::Update(std::vector<Bullet*>& bulletVectors, Player& player, GameTimer eTime){
	
	if(isSpawned && !IsDead()){
		
		EnemyMove(eTime.DeltaTime());
		
		eHitBox.x = enemyPosX;
		eHitBox.y = enemyPosY;
		
		passedTime = (eTime.TotalTime()-spawnTime);
		
		firingAngle = CalcFiringAngle(player.GetPlayerCenterX(), player.GetPlayerCenterY() );
		
		Shoot(bulletVectors, eTime);
	}
}

void PhEnemy::Shoot(std::vector<Bullet*>& bulletVectors, GameTimer& eTime){
	
	if(isSpawned){
		
		if(lastShot == 0){
			bulletVectors.push_back(new Bullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle ));
		}
		
		lastShot++;
	
		if(lastShot > 4){
			lastShot = 0;
	
		}
	
	}	
}

float PhEnemy::CalcFiringAngle(float X,float Y){
	return -atan2f(Y-enemyPosY, X-enemyPosX);
}
