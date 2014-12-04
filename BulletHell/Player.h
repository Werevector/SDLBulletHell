#pragma once
#include "SDL.h"
#include <iostream>
#include "Graphics.h"
#include <vector>
#include "Bullet.h"
#include "PlayerBulletA.h"
#include "Texture.h"

class Player {

private:

	float playerPositionX;
	float playerPositionY;

	float playerSpeed;

	//void Shoot(std::vector<Bullet>&, GameTimer);

	SDL_Rect hitbox;
	SDL_Rect renderQuad;

	int hitboxSize; //side size
	
	void ResetFlags();
	void HandleMovement(float deltaTime);

	float lastShot;

	Texture pTexture;


public:
	
	

	//keypress flags
	bool mUpp;
	bool mDown;
	bool mLeft;
	bool mRight;
	bool focus;
	bool shoot;
	
	void Shoot(std::vector<Bullet*>&, GameTimer&);
	
	void Update(GameTimer&, std::vector<Bullet*>&);
	
	Player();
	
	void Draw();
	
	int GetPlayerX();
	int GetPlayerY();
	int GetPlayerCenterX();
	int GetPlayerCenterY();
	SDL_Rect GetHitBox();
	bool isDead;

	

};