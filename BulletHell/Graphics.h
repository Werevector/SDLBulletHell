#pragma once
#include <SDL.h>

class Graphics
{
public:

	static void InitAll();

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	static SDL_Renderer* gRenderer;
	static SDL_Window* gWindow;


};

