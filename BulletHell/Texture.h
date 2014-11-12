#include <string>
#include "SDL.h"

class Texture{

public:

	Texture();
	~Texture();

	bool loadFromFile( std::string path );

	void free();
	void render( int x, int y );
	void renderFromCenter( int x, int y );

	 int getWidth(); 
	 int getHeight();

private:

	SDL_Texture* texture;
	int mWidth;
	int mHeight;

};