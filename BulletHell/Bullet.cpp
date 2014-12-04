#include "Bullet.h"

Bullet::Bullet(float sX, float sY, float time, float targetAngle){
	
	bTexture.loadFromFile("Textures\\GreenBullet.png");
	
	HITBOX_SIZE = 5;

	bulletPosX = sX-(HITBOX_SIZE/2);
	bulletPosY = sY-(HITBOX_SIZE/2);

	spawnTime = time;
	passedTime = 0;

	bVelocX = 1000;
	bVelocY = 1000;
	
	bHitBox.x = bulletPosX;
	bHitBox.y = bulletPosY;
	bHitBox.h = HITBOX_SIZE;
	bHitBox.w = HITBOX_SIZE;

	bRenderRect.h = 20;
	bRenderRect.w = 20;

	angle = targetAngle;
}

void Bullet::Move(float x, float y){
	bulletPosX = x;
	bulletPosY = y;

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
	
	//Creating vectors
	float VectorLength = 0;
	float vectorX = 1;
	float vectorY = 1;

	//Find vector length with pytagoras
	VectorLength = sqrt((vectorX * vectorX) + (vectorY * vectorY));

	//Normalise vectors
	if(VectorLength != 0){
		vectorX /= VectorLength;
		vectorY /= VectorLength;
	}

	/*float x = cos(angle)*vectorX*bTime.DeltaTime();
	float y = -sin(angle)*vectorY*bTime.DeltaTime();*/
	
	vectorX *= cos(angle)*bVelocX;
	vectorY *= -sin(angle)*bVelocY;

	float x = bulletPosX + vectorX*bTime.DeltaTime();
	float y = bulletPosY + vectorY*bTime.DeltaTime();
	
	
	Move(x, y);

}

void Bullet::Draw(){
	/*SDL_SetRenderDrawColor( Graphics::gRenderer, 0x00, 0xFF, 0x00, 0xFF ); 
	SDL_RenderFillRect( Graphics::gRenderer, &bHitBox );*/
	bTexture.renderFromCenter(GetCenterX(), GetCenterY(), &bRenderRect );
}

int Bullet::GetCenterX(){
	return (bulletPosX+(bHitBox.w/2));
}

int Bullet::GetCenterY(){
	return (bulletPosY+(bHitBox.h/2));
}

SDL_Rect Bullet::GetHitBox(){
	return bHitBox;
}