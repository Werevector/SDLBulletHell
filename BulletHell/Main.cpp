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

#include "PlayerHandler.h"
#include "EnemyHandler.h"
#include "BulletHandler.h"
#include "GameHandler.h"
using namespace std;

void init();
bool loadMedia();
void close();

//World obects
//Player player;
//vector<Enemy*> enemyVectors;
//Schedule gameSched(enemyVectors);
//vector<Bullet*> bulletVectors;

//PlayerHandler pHandler;
//EnemyHandler eHandler;
//BulletHandler bHandler;





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

void draw(GameHandler& gameHandler){

		//Clear screen
		SDL_SetRenderDrawColor( Graphics::gRenderer, 0x00, 0x00, 0x00, 0xFF );
		SDL_RenderClear( Graphics::gRenderer );

		gameHandler.RenderAll();

		//Update screen
		SDL_RenderPresent( Graphics::gRenderer );
}

void update(const Uint8* currentKeyStates, GameHandler& gameHandler){

	/*pHandler.UpdatePlayer(currentKeyStates, gTimer);
	eHandler.UpdateEnemies(gTimer);
	bHandler.UpdateBullets(gTimer);*/

	gameHandler.UpdateAll(gTimer, currentKeyStates);

	//gameSched.checkSpawn(gTimer.TotalTime(),enemyVectors);

}

int main( int argc, char* args[] ) {

	//initialize the game
	init();
	loadMedia();
	bool quit = false;
	SDL_Event event;
	gTimer.Reset();

	GameHandler gameHandler;

	while( !quit )
	{
		while( SDL_PollEvent( &event ) != 0 ){
			if( event.type == SDL_QUIT ){
				quit = true;
			}
		}//EventWhile

		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
		update(currentKeyStates, gameHandler );

		gTimer.Tick();
		cout << gTimer.TotalTime() << "";

		//draw to the screen
		draw( gameHandler );

	}//GameLoop

	close();

	return 0;

}//main
