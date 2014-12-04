#include "GameHandler.h"

GameHandler::GameHandler(){
	gSched.AddEnemiesToGame(eHandler.GetEnemiesAsPointer());
}

void GameHandler::UpdateAll(GameTimer& gTimer, const Uint8* currentKeyStates){
	bHandler.UpdateBullets(gTimer);
	eHandler.UpdateEnemies(bHandler.GetBulletPointers(), pHandler.GetPlayerPointer(), gTimer);
	pHandler.UpdatePlayer(currentKeyStates, gTimer, bHandler.GetPlayerBulletPointers());
	
	gSched.checkSpawn(gTimer.TotalTime(), eHandler.GetEnemiesAsPointer());
	
	PlayerVsEnemyColl(bHandler.GetPlayerBulletPointers(), eHandler.GetEnemiesAsPointer());
	EnemyVsPlayerColl(bHandler.GetBulletPointers(), pHandler.GetPlayerHitBox());
}

void GameHandler::RenderAll(){
	bHandler.RenderBullets();
	eHandler.RenderEnemies();
	pHandler.RenderPlayer();
}

void GameHandler::PlayerVsEnemyColl(std::vector<Bullet*>& playerBullets, std::vector<Enemy*>& EnemyVector){
	
	int pBsize = playerBullets.size();

	for(int i = 0; i < EnemyVector.size(); i++){
		
		for(int j = 0; j < playerBullets.size() ; j++){

			if( IsColl(EnemyVector[i]->GetHitBox(), playerBullets[j]->GetHitBox()) ){
				EnemyVector[i]->Damage(1);
				playerBullets.erase(playerBullets.begin() + j);
		
			}
		}
	}
}

void GameHandler::EnemyVsPlayerColl(std::vector<Bullet*>& enemyBullets, SDL_Rect playerRect){
	for(int i = 0; i < enemyBullets.size(); i++){
		
		if( IsColl(enemyBullets[i]->GetHitBox(), playerRect) ){
			pHandler.SetPlayerDead();
		}

	}
}

bool GameHandler::IsColl(SDL_Rect a, SDL_Rect b){
	 //Axix projection collision
	 bool result = true;

	 int leftA, leftB;
	 int rightA, rightB;
	 int topA, topB;
	 int bottomA, bottomB;

	 leftA = a.x;
	 rightA = a.x + a.w;
	 topA = a.y;
	 bottomA = a.y + a.h;

	 leftB = b.x;
	 rightB = b.x + b.w;
	 topB = b.y;
	 bottomB = b.y + b.h;

	 if(bottomA <= topB){
		 result = false;
	 }
	 if(topA >= bottomB){
		 result = false;
	 }
	 if(rightA <= leftB){
		 result = false;
	 }
	 if(leftA >= rightB){
		 result = false;
	 }

	 return result;
}