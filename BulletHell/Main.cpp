#pragma once
#include "SDL.h"
#include <iostream>
#include "stdio.h"
#include <string>
#include "Player.h"


using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void init();
bool loadMedia();
void close();

Player player;
Player::Action playerAction;


//SDL_Texture* loadTexture( std::string path );
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;


void init()
{

	SDL_Init( SDL_INIT_VIDEO );
	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
	gWindow = SDL_CreateWindow( "BulletHell", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
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
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}



int main( int argc, char* args[] ) {
	
	//initialize the game
	init();
	loadMedia();
	bool quit = false;
	SDL_Event event;


	//Start logic loop
	while( !quit )
	{
		while( SDL_PollEvent( &event ) != 0 )
		{
			if( event.type == SDL_QUIT )
			{
				quit = true;
			}
			else if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.sym){
					case SDLK_w:
					playerAction = Player::moveUpp;
					cout << "eventUpp";
					break;
				
					case SDLK_s:
					playerAction = Player::moveDown;
					cout << "eventDown";
					break;

					case SDLK_a:
					playerAction = Player::moveLeft;
					cout << "eventLeft";
					break;

					case SDLK_d:
					playerAction = Player::moveRight;
					cout << "eventRight";
					break;

					default:
					playerAction = Player::idle;
					break;
				}
			}
		}//EventWhile

		player.handleMovement(playerAction);
		playerAction = Player::idle;
		
		int SDL_WaitEvent(SDL_Event *event);

		//Clear screen
		SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
		SDL_RenderClear( gRenderer );

		player.renderPlayer( gRenderer );

		
		//Update screen
		SDL_RenderPresent( gRenderer );
		
		

	}//NotQuitwhile

	close();

	return 0;

}//main