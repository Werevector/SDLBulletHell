#include "GameHandler.h"

GameHandler::GameHandler(){
	gSched.AddEnemiesToGame(eHandler.GetEnemiesAsPointer());
}

void GameHandler::UpdateAll(GameTimer& gTimer, const Uint8* currentKeyStates){
	bHandler.UpdateBullets(gTimer);
	eHandler.UpdateEnemies(bHandler.GetBulletPointers(), gTimer);
	pHandler.UpdatePlayer(currentKeyStates, gTimer);
	gSched.checkSpawn(gTimer.TotalTime(), eHandler.GetEnemiesAsPointer());
}

void GameHandler::RenderAll(){
	bHandler.RenderBullets();
	eHandler.RenderEnemies();
	pHandler.RenderPlayer();
}

//void GameHandler::HandleColl(){
//	pHandler.CheckFieldColl();
//}