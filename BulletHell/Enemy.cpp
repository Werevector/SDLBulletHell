#include "Enemy.h"

Enemy::Enemy(int spawnX, int spawnY, float vX, float vY, float spawnTime){

	whenToSpawn = spawnTime;
	passedTime = 0;

	enemyPosX = spawnX;
	enemyPosY = spawnY;

	boxW = HITBOX_SIZE;
	boxH = HITBOX_SIZE;

	eVelocX = vX;
	eVelocY = vY;

	eHitBox.x = enemyPosX;
	eHitBox.y = enemyPosY;
	eHitBox.w = boxW;
	eHitBox.h = boxH;

	isSpawned = false;
}

void Enemy::Update(GameTimer eTime){
	
	if(isSpawned){
		EnemyMove(eTime.DeltaTime());
		eHitBox.x = enemyPosX;
		eHitBox.y = enemyPosY;
		passedTime = (eTime.TotalTime()-spawnTime);
	}
}

void Enemy::Draw(){
	if(isSpawned){
		SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0x00, 0x00, 0xFF ); 
		SDL_RenderFillRect( Graphics::gRenderer, &eHitBox );
	}
}

void Enemy::EnemyMove(float deltaTime){
	enemyPosX += (eVelocX/deltaTime);
	enemyPosY += (eVelocY/deltaTime);
}

void Enemy::Spawn(float currtime){
	if(isSpawned = false){

		isSpawned = true;
		spawnTime = currtime;

	}
}

void Enemy::Despawn(){
	isSpawned = false;
}

void Enemy::Shoot(std::vector<Bullet>& bulletVectors, Player& player, GameTimer& eTime){
	if(isSpawned){
		Bullet b(GetEnemyCenterX(), GetEnemyCenterY(), player, eTime.TotalTime());
		bulletVectors.push_back(b);
	}
}

int Enemy::GetEnemyCenterX(){
	return (enemyPosX+(eHitBox.w/2));
}

int Enemy::GetEnemyCenterY(){
	return (enemyPosY+(eHitBox.h/2));
}