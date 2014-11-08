#include "PlayerHandler.h"

PlayerHandler::PlayerHandler(){

}

void PlayerHandler::RenderPlayer(){
	player.Draw();
}

void PlayerHandler::UpdatePlayer(const Uint8* currentKeyStates, GameTimer& gTimer){
	
	if(currentKeyStates[ SDL_SCANCODE_UP ]){
		player.mUpp = true;
	}else if (currentKeyStates[ SDL_SCANCODE_DOWN ]){
		player.mDown = true;
	}

	if (currentKeyStates[ SDL_SCANCODE_LEFT ]){
		player.mLeft = true;
	}else if (currentKeyStates[ SDL_SCANCODE_RIGHT ]){
		player.mRight = true;
	}

	if(currentKeyStates[ SDL_SCANCODE_LSHIFT ]){
		player.focus = true;
	}else{
		player.focus = false;
	}

	player.Update(gTimer.DeltaTime());

}



