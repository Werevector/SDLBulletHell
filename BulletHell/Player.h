#include "SDL.h"
#include <iostream>

class Player {

private:

	int playerPositionX;
	int playerPositionY;

	SDL_Rect hitbox;
	int hitboxSize; //side size
	void resetFlags();

public:
	
	//keypress flags
	bool mUpp;
	bool mDown;
	bool mLeft;
	bool mRight;

	void renderPlayer(SDL_Renderer *renderer);
	void handleMovement(float deltaTime, int SCREEN_WIDTH, int SCREEN_HEIGHT);
	Player();


};