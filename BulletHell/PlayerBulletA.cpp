#include "PlayerBulletA.h"

PlayerBulletA::PlayerBulletA(float sX, float sY, float time, float targetAngle) : Bullet(sX,sY,time,targetAngle){

	bTexture.loadFromFile("Textures\\PlayerFairy.png");

	HITBOX_SIZE = 10;

	bHitBox.x = bulletPosX;
	bHitBox.y = bulletPosY;
	bHitBox.h = HITBOX_SIZE;
	bHitBox.w = HITBOX_SIZE;

	bulletPosX = sX-(bHitBox.w/2);
	bulletPosY = sY-(bHitBox.h/2);

	bVelocX = 1000;
	bVelocY = 1000;

}

//void PlayerBulletA::Draw(){
//	/*SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF ); 
//	SDL_RenderFillRect( Graphics::gRenderer, &bHitBox );*/
//
//}

void PlayerBulletA::Update(GameTimer& bTime){
	
	passedTime = (bTime.TotalTime()-spawnTime);

	float x = bulletPosX + cos(angle)*(bVelocX)*bTime.DeltaTime()*passedTime;
	float y = bulletPosY + -sin(angle)*(bVelocX)*bTime.DeltaTime()*passedTime;
	Move(x, y);

}