#include "YSpeedBullet.h"

YSpeedBullet::YSpeedBullet(float sX, float sY, float time, float targetAngle) : Bullet(sX,sY,time,targetAngle){

	bVelocX = 500;
	bVelocY = 500;

}

void YSpeedBullet::Draw(){
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0x0D, 0xFF ); 
	SDL_RenderFillRect( Graphics::gRenderer, &bHitBox );
}

void YSpeedBullet::Update(GameTimer& bTime){
	
	passedTime = (bTime.TotalTime()-spawnTime);
	
	float x = cos(angle)*(bVelocX)*bTime.DeltaTime();
	float y = -sin(angle)*(bVelocX)*bTime.DeltaTime();
	Move(x, y);

}