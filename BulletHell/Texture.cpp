#include "Texture.h"

Texture::Texture(){
	//Initialize
	texture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture(){
	free();
}

bool Texture::loadFromFile(std::string path){
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

	if( loadedSurface == NULL ){
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}else{
		
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( Graphics::gRenderer, loadedSurface );

		if( newTexture == NULL ){
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}else{

			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;

		}
	
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );

		}
	
	//Return success
	texture = newTexture;
	return texture != NULL;

}

void Texture::free(){
	
	//Free texture if it exists
	if( texture != NULL ){
		SDL_DestroyTexture( texture );
		texture = NULL;
		mWidth = 0;
		mHeight = 0;
	}

}

void Texture::render(int x, int y, SDL_Rect* clip){
	
}

void Texture::renderFromCenter(int x, int y, SDL_Rect* clip){
	
	//Set rendering space and render to screen
	int renderX = x - clip->w/2;
	int renderY = y - clip->h/2;
	SDL_Rect renderQuad = { renderX, renderY, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL ){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	//SDL_RenderCopy( Graphics::gRenderer, texture, clip, &renderQuad );
	SDL_RenderCopy( Graphics::gRenderer, texture, NULL, &renderQuad );
	/*SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
	SDL_RenderFillRect( Graphics::gRenderer, &renderQuad );*/
	
}

int Texture::getWidth(){
	return mWidth;
}

int Texture::getHeight(){
	return mHeight;
}


//std::string Texture::getApplicationPath(){
//	char buffer[MAX_PATH];
//	
//	GetModuleFileName( NULL, buffer, MAX_PATH );
//	
//	char *pos = strrchr(buffer, '\\');
//	
//	if (pos != NULL)
//		*pos = '\0';
//	
//	std::string appPath(buffer);
//	return appPath;
//}