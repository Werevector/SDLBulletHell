#include "SpiralEnemy.h"

SpiralEnemy::SpiralEnemy(int spawnX, int spawnY, float vX, float vY, float when) : Enemy(spawnX,spawnY,vX,vY,when){
	
}

void SpiralEnemy::Shoot(std::vector<Bullet>& bulletVectors, GameTimer& eTime){
	if(isSpawned){
		Bullet b(GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle );
		bulletVectors.push_back(b);
	}
}

void SpiralEnemy::Update(GameTimer eTime){
	
	if(isSpawned){
		EnemyMove(eTime.DeltaTime());
		eHitBox.x = enemyPosX;
		eHitBox.y = enemyPosY;
		passedTime = (eTime.TotalTime()-spawnTime);
		firingAngle += 0.1;
	}
}



void SpiralEnemy::Draw(){
	if(isSpawned){
		SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0x00, 0xFF, 0xFF ); 
		SDL_RenderFillRect( Graphics::gRenderer, &eHitBox );
	}
}