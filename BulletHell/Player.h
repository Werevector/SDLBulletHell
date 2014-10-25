#include "SDL.h"
#include <iostream>

class Player {

private:

	int playerPositionX;
	int playerPositionY;

	SDL_Rect hitbox;
	int hitboxSize; //side size

public:
	
	enum Action{
		//shoot not implemented yet
		idle,
		moveUpp,
		moveDown,
		moveLeft,
		moveRight

	};

	void renderPlayer(SDL_Renderer *renderer);
	void handleMovement(Action playeract);
	Player();


};