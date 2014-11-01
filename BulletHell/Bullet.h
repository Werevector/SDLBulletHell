#pragma once
#include "SDL.h"
#include "Graphics.h"
#include "Player.h"
#include "GameTimer.h"

class Bullet{

public:

	float spawnTime;
	float passedTime;

	Bullet(int, int, float, float);
	virtual void Update(GameTimer&, Player&);
	virtual void Draw();

	//SDL_Texture *texture;
	SDL_Rect bHitBox;

	int bulletPosX;
	int bulletPosY;

	float bVelocX;
	float bVelocY;

	int GetCenterX();
	int GetCenterY();

	bool isOutsideBounds();

protected:

	void Move(int, int);
	float angle;

};