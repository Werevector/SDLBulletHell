#pragma once
#include "Player.h"
#include "GameTimer.h"
#include "Bullet.h"

class PlayerHandler{

private:

	Player player;
	void HandleMovement();

public:

	PlayerHandler();
	void RenderPlayer();
	void UpdatePlayer(const Uint8*, GameTimer&, std::vector<Bullet*>&);
	void CheckFieldColl();
	void CheckBulletColl();
	SDL_Rect GetPlayerHitBox();

	void SetPlayerDead();

};