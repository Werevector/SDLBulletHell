#include "PlayerBulletA.h"

PlayerBulletA::PlayerBulletA(float sX, float sY, float time, float targetAngle) : Bullet(sX,sY,time,targetAngle){

	HITBOX_SIZE = 10;

	bulletPosX = sX-(HITBOX_SIZE/2);
	bulletPosY = sY-(HITBOX_SIZE/2);

	bHitBox.x = bulletPosX;
	bHitBox.y = bulletPosY;
	bHitBox.h = HITBOX_SIZE;
	bHitBox.w = HITBOX_SIZE;

	bVelocX = 1000;
	bVelocY = 1000;

}

void PlayerBulletA::Draw(){
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF ); 
	SDL_RenderFillRect( Graphics::gRenderer, &bHitBox );
}

void PlayerBulletA::Update(GameTimer& bTime){
	
	passedTime = (bTime.TotalTime()-spawnTime);
	
	float x = cos(angle)*(bVelocX)*bTime.DeltaTime();
	float y = -sin(angle)*(bVelocX)*bTime.DeltaTime();
	Move(x, y);

}