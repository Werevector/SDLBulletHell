#include "Player.h";

Player::Player(){
	
	playerPositionX = Graphics::SCREEN_WIDTH/2;
	playerPositionY = Graphics::SCREEN_HEIGHT/1.5;
	
	hitboxSize = 5;
	
	hitbox.x = playerPositionX;
	hitbox.y = playerPositionY;
	hitbox.h = hitboxSize;
	hitbox.w = hitboxSize;

	playerSpeed = 150;

	isDead = false;

	lastShot = 0;

}

void Player::Update(GameTimer& pTimer, std::vector<Bullet*>& playerBulletVectors){
	if(!isDead){	
		HandleMovement(pTimer.DeltaTime());
	
		if(shoot&&lastShot==0){
			Shoot(playerBulletVectors, pTimer);
		}
		lastShot++;
		if(lastShot>4){
			lastShot=0;
		}
	}
}

void Player::HandleMovement(float deltaTime) {
	
	if(focus){
		playerSpeed = 150;
	}else{
		playerSpeed = 500;
	}

	float VectorLength = 0;
	float vectorX = 0;
	float vectorY = 0;

	if(mUpp && hitbox.y > 0){
		vectorY -= 1;
		printf("moveUpp\n");
	}
	
	if(mDown && hitbox.y < (Graphics::SCREEN_HEIGHT - hitbox.h)){
		vectorY += 1;
		printf("moveDown\n");
	}
	
	if(mLeft && hitbox.x > 0){
		vectorX -= 1;
		printf("moveLeft\n");
	}
	
	if(mRight && hitbox.x < (Graphics::SCREEN_WIDTH - hitbox.h)){
		vectorX += 1;
		printf("moveRight\n");
	}

	VectorLength = sqrt((vectorX * vectorX) + (vectorY * vectorY));
	
	

	if(VectorLength != 0){
		vectorX /= VectorLength;
		vectorY /= VectorLength;
	}
	playerPositionX += vectorX*playerSpeed*deltaTime;
	playerPositionY += vectorY*playerSpeed*deltaTime;

	hitbox.y = playerPositionY;
	hitbox.x = playerPositionX;
	
	ResetFlags();
	
}

void Player::Shoot(std::vector<Bullet*>& playerBulletVectors, GameTimer& pTime){
	playerBulletVectors.push_back(new PlayerBulletA( GetPlayerCenterX()-10, GetPlayerCenterY(), pTime.TotalTime(), 1.57+0.05 ));
	playerBulletVectors.push_back(new PlayerBulletA( GetPlayerCenterX()+10, GetPlayerCenterY(), pTime.TotalTime(), 1.57-0.05 ));
	playerBulletVectors.push_back(new PlayerBulletA( GetPlayerCenterX()-10, GetPlayerCenterY(), pTime.TotalTime(), 1.57+0.3 ));
	playerBulletVectors.push_back(new PlayerBulletA( GetPlayerCenterX()+10, GetPlayerCenterY(), pTime.TotalTime(), 1.57-0.3 ));
}

void Player::Draw(){
	if(!isDead){
		SDL_SetRenderDrawColor( Graphics::gRenderer, 0x00, 0x00, 0xFF, 0xFF ); 
		SDL_RenderFillRect( Graphics::gRenderer, &hitbox );
	}
}

void Player::ResetFlags(){
	mUpp=false;
	mDown=false;
	mLeft=false;
	mRight=false;
}

int Player::GetPlayerX(){
	return playerPositionX;
}

int Player::GetPlayerY(){
	return playerPositionY;
}

int Player::GetPlayerCenterX(){
	return (playerPositionX+(hitbox.w/2));
}

int Player::GetPlayerCenterY(){
	return (playerPositionY+(hitbox.h/2));
}

SDL_Rect Player::GetHitBox(){
	return hitbox;
}