#pragma once
#include "SDL.h"
#include <iostream>
#include "Graphics.h"

class Player {

private:

	int playerPositionX;
	int playerPositionY;

	SDL_Rect hitbox;
	int hitboxSize; //side size
	void resetFlags();
	void renderPlayer();
	void handleMovement(float deltaTime);

public:
	
	//keypress flags
	bool mUpp;
	bool mDown;
	bool mLeft;
	bool mRight;

	void update(float deltaTime);
	Player();
	void draw();
	int GetPlayerX();
	int GetPlayerY();

};