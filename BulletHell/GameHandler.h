#pragma once
#include "BulletHandler.h"
#include "EnemyHandler.h"
#include "PlayerHandler.h"
#include "Schedule.h"

class GameHandler{

private:

	BulletHandler bHandler;
	EnemyHandler eHandler;
	PlayerHandler pHandler;
	Schedule gSched;
	

public:

	void UpdateAll(GameTimer&, const Uint8*);
	void RenderAll();
	void HandleColl();
	
	GameHandler();

	void RunFrame();

};