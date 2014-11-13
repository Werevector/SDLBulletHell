#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Graphics.h"


class Texture{

public:

	Texture();
	~Texture();

	bool loadFromFile( std::string path );

	void free();
	void render( int x, int y, SDL_Rect* clip );
	void renderFromCenter( int x, int y, SDL_Rect* clip );

	 int getWidth(); 
	 int getHeight();

private:

	SDL_Texture* texture;
	int mWidth;
	int mHeight;
	//std::string getApplicationPath();
};