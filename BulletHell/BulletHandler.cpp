#include "BulletHandler.h"

BulletHandler::BulletHandler(){

}

void BulletHandler::RenderBullets(){
	
	for(int i = 0; i < bulletVector.size(); i++){
			bulletVector[i]->Draw();
	}

}

void BulletHandler::UpdateBullets(GameTimer& gTimer){

	for(int i = 0; i < bulletVector.size(); i++){
			bulletVector[i]->Update(gTimer);
			
			if(bulletVector[i]->isOutsideBounds()){
				bulletVector.erase(bulletVector.begin() + i);
			}
	}
	std::cout << "  " << bulletVector.size() << "\n";
}

void BulletHandler::AddShotBullet(Bullet bullet){
}

std::vector<Bullet*>& BulletHandler::GetBulletPointers(){
	return bulletVector;
}