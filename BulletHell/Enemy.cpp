#include "Enemy.h"

Enemy::Enemy(int x, int y, float vX, float vY, float spawnTime){

	spawnTimeSec = spawnTime;

	spawnPosX = x;
	spawnPosY = y;

	boxW = 20;
	boxH = 20;

	EnemyPosX = spawnPosX;
	EnemyPosY = spawnPosY;

	eVelocX = vX;
	eVelocY = vY;

	eHitBox.x = EnemyPosX;
	eHitBox.y = EnemyPosY;
	eHitBox.w = boxW;
	eHitBox.h = boxH;

	isSpawned = false;
}

void Enemy::update(float deltaTime){
	
	if(isSpawned){
		enemyMove(deltaTime);
		eHitBox.x = EnemyPosX;
		eHitBox.y = EnemyPosY;
	}
}

void Enemy::draw(){
	if(isSpawned){
		renderEnemy();
	}
}

void Enemy::renderEnemy(){
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0x00, 0x00, 0xFF ); 
	SDL_RenderFillRect( Graphics::gRenderer, &eHitBox );
}

void Enemy::enemyMove(float deltaTime){
	EnemyPosX += (eVelocX/deltaTime);
	EnemyPosY += (eVelocY/deltaTime);
}

void Enemy::spawn(){
	isSpawned = true;
}

void Enemy::despawn(){
	isSpawned = true;
}