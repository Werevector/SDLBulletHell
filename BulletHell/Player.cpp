#include "Player.h";

Player::Player(){
	
	playerPositionX = 60;
	playerPositionY = 60;
	
	hitboxSize = 45;
	
	hitbox.x = playerPositionX;
	hitbox.y = playerPositionY;
	hitbox.h = hitboxSize;
	hitbox.w = hitboxSize;
}

void Player::handleMovement(float deltaTime, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
	
	if(mUpp && hitbox.y > 0){
		playerPositionY -= (0.1/deltaTime);
		hitbox.y = playerPositionY;
		printf("moveUpp\n");
	}else if(mDown && hitbox.y < (SCREEN_HEIGHT - hitbox.h)){
		playerPositionY += (0.1/deltaTime);
		hitbox.y = playerPositionY;
		printf("moveDown\n");
	}
	
	if(mLeft && hitbox.x > 0){
		playerPositionX -= (0.1/deltaTime);
		hitbox.x = playerPositionX;
		printf("moveLeft\n");
	}else if(mRight && hitbox.x < (SCREEN_WIDTH - hitbox.h)){
		playerPositionX += (0.1/deltaTime);
		hitbox.x = playerPositionX;
		printf("moveRight\n");
	}
	
	resetFlags();
	
}

void Player::renderPlayer(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF ); 
	SDL_RenderFillRect( renderer, &hitbox );
}

void Player::resetFlags(){
	mUpp=false;
	mDown=false;
	mLeft=false;
	mRight=false;
}
