#include "Enemy.h"

Enemy::Enemy(int spawnX, int spawnY, float vX, float vY, float when){

	whenToSpawn = when;
	passedTime = 0;
	spawnTime = 0;

	healthPoints = 10;

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

	firingAngle = CalcFiringAngle(0,0);

}

void Enemy::Update(GameTimer eTime){
	
	if(isSpawned){
		EnemyMove(eTime.DeltaTime());
		eHitBox.x = enemyPosX;
		eHitBox.y = enemyPosY;
		passedTime = (eTime.TotalTime()-spawnTime);
		firingAngle += sin(passedTime+180);
	}
}

void Enemy::Draw(){
	if(isSpawned){
		SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0x00, 0x00, 0xFF ); 
		SDL_RenderFillRect( Graphics::gRenderer, &eHitBox );
	}
}



void Enemy::EnemyMove(float deltaTime){
	enemyPosX += (eVelocX*deltaTime);
	enemyPosY += (eVelocY*deltaTime);
}

void Enemy::Spawn(float currtime){
	if(isSpawned == false && IsDead() == false){
		isSpawned = true;
		spawnTime = currtime;
	}
}

void Enemy::Despawn(){
	isSpawned = false;
}

void Enemy::Shoot(std::vector<Bullet*>& bulletVectors, GameTimer& eTime){
	if(isSpawned){
		bulletVectors.push_back(new Bullet( GetEnemyCenterX(), GetEnemyCenterY(), eTime.TotalTime(), firingAngle ));
	}
}

float Enemy::CalcFiringAngle(float X,float Y){
	return -atan2f(Y, X);
}

void Enemy::Damage(int amountOfDamage){
	healthPoints -= amountOfDamage;
}

int Enemy::GetEnemyCenterX(){
	return (enemyPosX + (HITBOX_SIZE/2));
}

int Enemy::GetEnemyCenterY(){
	return (enemyPosY + (HITBOX_SIZE/2));
}

int Enemy::GetHealth(){
	return healthPoints;
}

bool Enemy::IsDead(){
	bool result = false;
	if(healthPoints <= 0){result = true;}
	return result;
}