#include "SpiralEnemy.h"

SpiralEnemy::SpiralEnemy(int spawnX, int spawnY, float vX, float vY, float when) : Enemy(spawnX,spawnY,vX,vY,when){
	
}

void SpiralEnemy::Shoot(std::vector<Bullet*>& bulletVectors, GameTimer& eTime){
	if(isSpawned){
		for(int i = 1 ; i <= 1 ; i++){	
			bulletVectors.push_back(new YSpeedBullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle ));
			bulletVectors.push_back(new YSpeedBullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle +(3.14) ));
		}
	}
}

void SpiralEnemy::Update(std::vector<Bullet*>& bulletVectors, GameTimer eTime){
	
	if(isSpawned){
		passedTime = (eTime.TotalTime()-spawnTime);
		if(GetEnemyCenterY() < Graphics::SCREEN_HEIGHT/2 || passedTime > 10){
			EnemyMove(eTime.DeltaTime());
		}else{
			firingAngle += (3.13/16);
			Shoot(bulletVectors, eTime);
		}
		eHitBox.x = enemyPosX;
		eHitBox.y = enemyPosY;
		//firingAngle += 0.1;
		
	}
}



void SpiralEnemy::Draw(){
	if(isSpawned){
		SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0x00, 0xFF, 0xFF ); 
		SDL_RenderFillRect( Graphics::gRenderer, &eHitBox );
	}
}