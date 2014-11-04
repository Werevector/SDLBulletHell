#pragma once
#include "SDL.h"
#include <iostream>
#include "Graphics.h"
#include <vector>


class Player {

private:

	int playerPositionX;
	int playerPositionY;

	float playerSpeed;

	//void Shoot(std::vector<Bullet>&, GameTimer);

	SDL_Rect hitbox;
	int hitboxSize; //side size
	
	void ResetFlags();
	void HandleMovement(float deltaTime);

public:
	
	//keypress flags
	bool mUpp;
	bool mDown;
	bool mLeft;
	bool mRight;
	bool focus;

	void Update(float deltaTime);
	
	Player();
	
	void Draw();
	
	int GetPlayerX();
	int GetPlayerY();
	int GetPlayerCenterX();
	int GetPlayerCenterY();

};