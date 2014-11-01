#include "YSpeedBullet.h"

YSpeedBullet::YSpeedBullet(int sX, int sY, float time, float targetAngle) : Bullet(sX,sY,time,targetAngle){

}

void YSpeedBullet::Draw(){
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0x0D, 0xFF ); 
	SDL_RenderFillRect( Graphics::gRenderer, &bHitBox );
}
