#include "BulletColl.h"

std::vector<Bullet*> BulletColl::GetBulletsAsVector(){
	return bulletVectors;
}

std::vector<Bullet*>& BulletColl::GetBulletsAsPointer(){
	return bulletVectors;
}

void BulletColl::addBullet(Bullet bullet){
	bulletVectors.push_back(&bullet);
}