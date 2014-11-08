#pragma once
#include "SDL.h"
#include "Graphics.h"
#include "Player.h"
#include "GameTimer.h"

class Bullet{

public:

	float spawnTime;
	float passedTime;

	Bullet(float, float, float, float);
	virtual void Update(GameTimer&);
	virtual void Draw();

	//SDL_Texture *texture;
	SDL_Rect bHitBox;

	float bulletPosX;
	float bulletPosY;

	float bVelocX;
	float bVelocY;

	int GetCenterX();
	int GetCenterY();

	bool isOutsideBounds();

protected:

	void Move(float, float);
	float angle;
	static const int HITBOX_SIZE = 5;

};