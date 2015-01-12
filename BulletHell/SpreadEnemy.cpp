#include "SpreadEnemy.h"

SpreadEnemy::SpreadEnemy(int spawnX, int spawnY, float vX, float vY, float when) : Enemy(spawnX,spawnY,vX,vY,when){
	eVelocX = vX;
	eVelocY = vY;
}

void SpreadEnemy::Shoot(std::vector<Bullet*>& bulletVectors, GameTimer& eTime){
	if(isSpawned){	
			if(lastShot == 0){
				bulletVectors.push_back(new YSpeedBullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle + 0.1 ));
				bulletVectors.push_back(new YSpeedBullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle + 0.2 ));
				bulletVectors.push_back(new YSpeedBullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle - 0.1 ));
				bulletVectors.push_back(new YSpeedBullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle - 0.2 ));
			}
			lastShot++;
			if(lastShot>10){lastShot=0;}

	}
}

void SpreadEnemy::Update(std::vector<Bullet*>& bulletVectors, Player& player, GameTimer eTime){
	
	if(isSpawned && !IsDead()){
		passedTime = (eTime.TotalTime()-spawnTime);
		if(GetEnemyCenterY() < Graphics::SCREEN_HEIGHT/2 || passedTime > 10){
			EnemyMove(eTime.DeltaTime());
		}else{
			Shoot(bulletVectors, eTime);
		}


		eHitBox.x = enemyPosX;
		eHitBox.y = enemyPosY;
	}
}