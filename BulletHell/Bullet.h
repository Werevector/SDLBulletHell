#include "SDL.h"

struct Bullet{

public:

	Bullet(int, int);

	//SDL_Texture *texture;
	SDL_Rect bHitBox;

	int BulletPosX;
	int BulletPosY;

	float bVelocX;
	float bVelocY;

};