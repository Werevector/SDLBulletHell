#include "BulletHandler.h"

BulletHandler::BulletHandler(){

}

void BulletHandler::RenderBullets(){
	std::vector<Bullet*> bullets = bColl.GetBulletsAsVector();
	
	for(int i = 0; i < bullets.size(); i++){
			bullets[i]->Draw();
	}

}

void BulletHandler::UpdateBullets(GameTimer& gTimer){
	std::vector<Bullet*> bullets = bColl.GetBulletsAsVector();

	for(int i = 0; i < bullets.size(); i++){
			bullets[i]->Update(gTimer);
			
			if(bullets[i]->isOutsideBounds()){
				bullets.erase(bullets.begin() + i);
			}
	}
	std::cout << "  " << bullets.size() << "\n";
}

void BulletHandler::AddShotBullet(Bullet bullet){
	bColl.addBullet(bullet);
}

std::vector<Bullet*>& BulletHandler::GetBulletPointers(){
	return bColl.GetBulletsAsPointer();
}