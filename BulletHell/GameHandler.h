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

	void PlayerVsEnemyColl(std::vector<Bullet*>&, std::vector<Enemy*>&);
	void EnemyVsPlayerColl(std::vector<Bullet*>&, SDL_Rect);

	bool IsColl(SDL_Rect, SDL_Rect);
	

public:

	void UpdateAll(GameTimer&, const Uint8*);
	void RenderAll();
	
	GameHandler();

	void RunFrame();

};