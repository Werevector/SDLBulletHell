#pragma once
#include "Player.h"
#include "GameTimer.h"

class PlayerHandler{

private:

	Player player;
	void HandleMovement();

public:

	PlayerHandler();
	void RenderPlayer();
	void UpdatePlayer(const Uint8*, GameTimer&);
	void CheckFieldColl();
	void CheckBulletColl();

};