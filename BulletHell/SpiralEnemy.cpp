#include "SpiralEnemy.h"

SpiralEnemy::SpiralEnemy(int spawnX, int spawnY, float vX, float vY, float when) : Enemy(spawnX,spawnY,vX,vY,when){
	eVelocX = vX;
	eVelocY = vY;
}

void SpiralEnemy::Shoot(std::vector<Bullet*>& bulletVectors, GameTimer& eTime){
	if(isSpawned){
		for(int i = 1 ; i <= 1 ; i++){	
			bulletVectors.push_back(new YSpeedBullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle ));
			bulletVectors.push_back(new YSpeedBullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle +(3.14) ));
		}
	}
}

void SpiralEnemy::Update(std::vector<Bullet*>& bulletVectors, Player& player, GameTimer eTime){
	
	if(isSpawned && !IsDead()){
		passedTime = (eTime.TotalTime()-spawnTime);
		if(GetEnemyCenterY() < Graphics::SCREEN_HEIGHT/2 || passedTime > 10){
			EnemyMove(eTime.DeltaTime());
		}else{
			firingAngle += (3.13/16);
			Shoot(bulletVectors, eTime);
		}
		eHitBox.x = enemyPosX;
		eHitBox.y = enemyPosY;
		
	}
}
