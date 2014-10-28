#include "Bullet.h"

Bullet::Bullet(int sX, int sY, Player& player, float t){
	bulletPosX = sX;
	bulletPosY = sY;

	spawnTime = t;

	bVelocX = 3;
	bVelocY = 3;
	
	bHitBox.x = bulletPosX;
	bHitBox.y = bulletPosY;
	bHitBox.h = 5;
	bHitBox.w = 5;
	
	angle = atan2f(player.GetPlayerX()-bulletPosX, player.GetPlayerY()-bulletPosY);
}

void Bullet::Move(int x, int y){
	bulletPosX = x;
	bulletPosY = y;
}

void Bullet::Render(){
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0x00, 0x00, 0xFF ); 
	SDL_RenderFillRect( Graphics::gRenderer, &bHitBox );
}

void Bullet::Update(GameTimer bTime){
	
	Move(cos(angle)*bVelocX*bTime.DeltaTime(), -sin(angle)*bVelocY*bTime.DeltaTime());

}

void Bullet::Draw(){
	Render();
}