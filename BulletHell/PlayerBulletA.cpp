#include "PlayerBulletA.h"

PlayerBulletA::PlayerBulletA(float sX, float sY, float time, float targetAngle) : Bullet(sX,sY,time,targetAngle){

	bVelocX = 2000;
	bVelocY = 2000;

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