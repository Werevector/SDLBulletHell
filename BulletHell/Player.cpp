#include "Player.h";

Player::Player(){
	
	playerPositionX = 60;
	playerPositionY = 60;
	
	hitboxSize = 20;
	
	hitbox.x = playerPositionX;
	hitbox.y = playerPositionY;
	hitbox.h = hitboxSize;
	hitbox.w = hitboxSize;
}

void Player::update(float deltaTime){
	handleMovement(deltaTime);
}

void Player::handleMovement(float deltaTime) {
	

	if(mUpp && hitbox.y > 0){
		playerPositionY -= (0.1/deltaTime);
		hitbox.y = playerPositionY;
		printf("moveUpp\n");
	}else if(mDown && hitbox.y < (Graphics::SCREEN_HEIGHT - hitbox.h)){
		playerPositionY += (0.1/deltaTime);
		hitbox.y = playerPositionY;
		printf("moveDown\n");
	}
	
	if(mLeft && hitbox.x > 0){
		playerPositionX -= (0.1/deltaTime);
		hitbox.x = playerPositionX;
		printf("moveLeft\n");
	}else if(mRight && hitbox.x < (Graphics::SCREEN_WIDTH - hitbox.h)){
		playerPositionX += (0.1/deltaTime);
		hitbox.x = playerPositionX;
		printf("moveRight\n");
	}
	
	resetFlags();
	
}

void Player::draw(){
	renderPlayer();
}

void Player::renderPlayer(){
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0x00, 0x00, 0xFF, 0xFF ); 
	SDL_RenderFillRect( Graphics::gRenderer, &hitbox );
}

void Player::resetFlags(){
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