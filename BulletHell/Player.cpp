#include "Player.h";

Player::Player(){
	
	playerPositionX = Graphics::SCREEN_WIDTH/2;
	playerPositionY = Graphics::SCREEN_HEIGHT/1.5;
	
	hitboxSize = 3;
	
	hitbox.x = playerPositionX;
	hitbox.y = playerPositionY;
	hitbox.h = hitboxSize;
	hitbox.w = hitboxSize;

	playerSpeed = 150;

	isDead = false;

}

void Player::Update(GameTimer& pTimer, std::vector<Bullet*>& playerBulletVectors){
	if(!isDead){	
		HandleMovement(pTimer.DeltaTime());
	
		if(shoot){
			Shoot(playerBulletVectors, pTimer);
		}
	}
}

void Player::HandleMovement(float deltaTime) {
	
	if(focus){
		playerSpeed = 150;
	}else{
		playerSpeed = 500;
	}

	if(mUpp && hitbox.y > 0){
		playerPositionY -= (playerSpeed*deltaTime);
		hitbox.y = playerPositionY;
		printf("moveUpp\n");
	}else if(mDown && hitbox.y < (Graphics::SCREEN_HEIGHT - hitbox.h)){
		playerPositionY += (playerSpeed*deltaTime);
		hitbox.y = playerPositionY;
		printf("moveDown\n");
	}
	
	if(mLeft && hitbox.x > 0){
		playerPositionX -= (playerSpeed*deltaTime);
		hitbox.x = playerPositionX;
		printf("moveLeft\n");
	}else if(mRight && hitbox.x < (Graphics::SCREEN_WIDTH - hitbox.h)){
		playerPositionX += (playerSpeed*deltaTime);
		hitbox.x = playerPositionX;
		printf("moveRight\n");
	}

	
	ResetFlags();
	
}

void Player::Shoot(std::vector<Bullet*>& playerBulletVectors, GameTimer& pTime){
	playerBulletVectors.push_back(new PlayerBulletA( GetPlayerCenterX(), GetPlayerCenterY(), pTime.TotalTime(), 1.57 ));
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