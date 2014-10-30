#pragma once
#include "SDL.h"
#include "Graphics.h"
#include "Player.h"
#include "GameTimer.h"

class Bullet{

public:

	float spawnTime;
	Bullet(int, int, Player&, float);
	void Update(GameTimer bTime, Player&);
	void Draw();

	//SDL_Texture *texture;
	SDL_Rect bHitBox;

	int bulletPosX;
	int bulletPosY;

	float bVelocX;
	float bVelocY;

	float angle;

private:

	void Move(int, int);
	void Render();

};