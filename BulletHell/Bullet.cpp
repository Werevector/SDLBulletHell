#include "Bullet.h"

Bullet::Bullet(int sX, int sY){
	BulletPosX = sX;
	BulletPosY = sY;
	
	bHitBox.x = BulletPosX;
	bHitBox.y = BulletPosY;


}