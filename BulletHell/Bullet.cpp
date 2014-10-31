#include "Bullet.h"

Bullet::Bullet(int sX, int sY, Player& player, float time){
	bulletPosX = sX;
	bulletPosY = sY;

	spawnTime = time;
	passedTime = 0;

	bVelocX = 0.1;
	bVelocY = 0.1;
	
	bHitBox.x = bulletPosX;
	bHitBox.y = bulletPosY;
	bHitBox.h = 5;
	bHitBox.w = 5;
	
	angle = -atan2f(player.GetPlayerCenterY()-bulletPosY, player.GetPlayerCenterX()-bulletPosX);
}

void Bullet::Move(int x, int y){
	bulletPosX += x;
	bulletPosY += y;

	bHitBox.x = bulletPosX;
	bHitBox.y = bulletPosY;
}

bool Bullet::isOutsideBounds(){
	bool result = false;
	if(GetCenterX() >= Graphics::SCREEN_WIDTH || GetCenterY() >= Graphics::SCREEN_HEIGHT){
		result = true;
	}
	return result;
}

void Bullet::Update(GameTimer& bTime, Player& player){
	
	passedTime = (bTime.TotalTime()-spawnTime);
	
	int x = cos(angle)*(bVelocX+(0.05*(passedTime)))/bTime.DeltaTime();
	int y = -sin(angle)*(bVelocY+(0.05*(passedTime)))/bTime.DeltaTime();
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
