#pragma once
#include "SDL.h"
#include <iostream>
#include "stdio.h"
#include <string>
#include "Player.h"
#include "GameTimer.h"
#include "Graphics.h"
#include <vector>
#include "Enemy.h"
#include "Schedule.h"
#include "Bullet.h"

using namespace std;

void init();
bool loadMedia();
void close();

//World obects
Player player;
vector<Enemy> enemyVectors;
Schedule gameSched(enemyVectors);
vector<Bullet> bulletVectors;

//timer
GameTimer gTimer;



//SDL_Texture* loadTexture( std::string path );


void init()
{

	SDL_Init( SDL_INIT_VIDEO );
	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
	
	Graphics::gWindow = SDL_CreateWindow( "BulletHell", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	Graphics::gRenderer = SDL_CreateRenderer( Graphics::gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Nothing to load
	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( Graphics::gRenderer );
	SDL_DestroyWindow( Graphics::gWindow );
	Graphics::gWindow = NULL;
	Graphics::gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void draw(){
		
	//Clear screen
		SDL_SetRenderDrawColor( Graphics::gRenderer, 0x00, 0x00, 0x00, 0xFF );
		SDL_RenderClear( Graphics::gRenderer );

		player.Draw();

		for(int i = 0; i < enemyVectors.size(); i++){
			enemyVectors[i].Draw();
		}

		for(int i = 0; i < bulletVectors.size(); i++){
			bulletVectors[i].Draw();
		}

		//Update screen
		SDL_RenderPresent( Graphics::gRenderer );
}

void update(const Uint8* currentKeyStates){
	
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

	//Enemies
	for(int i = 0; i < enemyVectors.size(); i++){
			enemyVectors[i].Update(gTimer);
			enemyVectors[i].Shoot(bulletVectors, player, gTimer);
	}

	//Bullets
	for(int i = 0; i < bulletVectors.size(); i++){
			bulletVectors[i].Update(gTimer, player);
	
	}

	player.Update(gTimer.DeltaTime());
	gameSched.checkSpawn(gTimer.TotalTime(),enemyVectors);
	

}

int main( int argc, char* args[] ) {
	
	//initialize the game
	init();
	loadMedia();
	bool quit = false;
	SDL_Event event;
	gTimer.Reset();
	

	while( !quit )
	{
		while( SDL_PollEvent( &event ) != 0 ){
			if( event.type == SDL_QUIT ){
				quit = true;
			}
		}//EventWhile

		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
		update(currentKeyStates);

		gTimer.Tick();
		cout << gTimer.TotalTime() << "\n";

		//draw to the screen
		draw();
		
	}//GameLoop

	close();

	return 0;

}//main