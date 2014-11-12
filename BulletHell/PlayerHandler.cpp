#include "PlayerHandler.h"

PlayerHandler::PlayerHandler(){

}

void PlayerHandler::RenderPlayer(){
	player.Draw();
}

void PlayerHandler::UpdatePlayer(const Uint8* currentKeyStates, GameTimer& gTimer, std::vector<Bullet*>& playerBulletVector){
	
	if(currentKeyStates[ SDL_SCANCODE_UP ]){
		player.mUpp = true;
	}
	
	if (currentKeyStates[ SDL_SCANCODE_DOWN ]){
		player.mDown = true;
	}

	if (currentKeyStates[ SDL_SCANCODE_LEFT ]){
		player.mLeft = true;
	}
	
	if (currentKeyStates[ SDL_SCANCODE_RIGHT ]){
		player.mRight = true;
	}

	if(currentKeyStates[ SDL_SCANCODE_LSHIFT ]){
		player.focus = true;
	}else{
		player.focus = false;
	}

	if(currentKeyStates[ SDL_SCANCODE_Z ]){
		player.shoot = true;
	}else{
		player.shoot = false;
	}

	player.Update(gTimer, playerBulletVector);

}

SDL_Rect PlayerHandler::GetPlayerHitBox(){
	return player.GetHitBox();
}

void PlayerHandler::SetPlayerDead(){
	player.isDead = true;
}



