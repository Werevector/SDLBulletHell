#include "Player.h";

Player::Player(){
	
	playerPositionX = 60;
	playerPositionY = 60;
	
	hitboxSize = 10;
	
	hitbox.x = playerPositionX;
	hitbox.y = playerPositionY;
	hitbox.h = hitboxSize;
	hitbox.w = hitboxSize;
}

void Player::handleMovement(Action playeract) {
	switch(playeract){
		case moveUpp:
		playerPositionY -= 3;
		hitbox.y = playerPositionY;
		std::cout << "moveUpp";
		break;

		case moveDown:
		playerPositionY += 3;
		hitbox.y = playerPositionY;
		std::cout << "moveDown";
		break;

		case moveLeft:
		playerPositionX -= 3;
		hitbox.x = playerPositionX;
		std::cout << "moveLeft";
		break;

		case moveRight:
		playerPositionX += 3;
		hitbox.x = playerPositionX;
		std::cout << "moveRight";
		break;

		case idle:
		break;
	}
}

void Player::renderPlayer(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF ); 
	SDL_RenderFillRect( renderer, &hitbox );
}

