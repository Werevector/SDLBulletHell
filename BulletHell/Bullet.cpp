#include "Bullet.h"

Bullet::Bullet(float sX, float sY, float time, float targetAngle){
	bulletPosX = sX-(HITBOX_SIZE/2);
	bulletPosY = sY-(HITBOX_SIZE/2);

	spawnTime = time;
	passedTime = 0;

	bVelocX = 100;
	bVelocY = 100;
	
	bHitBox.x = bulletPosX;
	bHitBox.y = bulletPosY;
	bHitBox.h = HITBOX_SIZE;
	bHitBox.w = HITBOX_SIZE;
	
	//-atan2f(player.GetPlayerCenterY()-bulletPosY, player.GetPlayerCenterX()-bulletPosX);

	angle = targetAngle;
}

void Bullet::Move(float x, float y){
	bulletPosX += x;
	bulletPosY += y;

	bHitBox.x = bulletPosX;
	bHitBox.y = bulletPosY;
}

bool Bullet::isOutsideBounds(){
	bool result = false;
	if(GetCenterX() >= Graphics::SCREEN_WIDTH + 50 || GetCenterY() >= Graphics::SCREEN_HEIGHT + 50 || GetCenterY() <= -50 || GetCenterX() <= -50){
		result = true;
	}
	return result;
}

void Bullet::Update(GameTimer& bTime){
	
	passedTime = (bTime.TotalTime()-spawnTime);
	
	float x = cos(angle)*bVelocX*bTime.DeltaTime();
	float y = -sin(angle)*bVelocY*bTime.DeltaTime();
	Move(x, y);

}

void Bullet::Draw(){
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0x00, 0xFF, 0x00, 0xFF ); 
	SDL_RenderFillRect( Graphics::gRenderer, &bHitBox );
}

int Bullet::GetCenterX(){
	return (bulletPosX+(bHitBox.w/2));
}

int Bullet::GetCenterY(){
	return (bulletPosY+(bHitBox.h/2));
}
